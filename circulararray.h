#include <iostream>

using namespace std;

template<class T>
class CircularArray {
private:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray();

    CircularArray(int _capacity);

    virtual ~CircularArray();

    void push_front(T data);

    void push_back(T data);

    void insert(T data, int pos);

    T pop_front();

    T pop_back();

    bool is_full();

    bool is_empty();

    int size();

    void clear();

    T &operator[](int);

    void sort();

    bool is_sorted();

    void reverse();

    string to_string(string sep = " ");

private:
    int next(int);

    int prev(int);
};

template<class T>
CircularArray<T>::CircularArray() {
    CircularArray(0);
}

template<class T>
CircularArray<T>::CircularArray(int _capacity) {
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template<class T>
CircularArray<T>::~CircularArray() {
    delete[] array;
}

template<class T>
int CircularArray<T>::prev(int index) {
    return (index == 0) ? capacity - 1 : index - 1;
}

template<class T>
int CircularArray<T>::next(int index) {
    return (index + 1) % capacity;
}

template<class T>
string CircularArray<T>::to_string(string sep) {
    string result = "";
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;
}

template<class T>
bool CircularArray<T>::is_empty() {
    return (front == -1 && back == -1);
}

template<class T>
bool CircularArray<T>::is_full() {
    return next(back) == front;
}

template<class T>
int CircularArray<T>::size() {
    if (is_empty()) {
        return 0;
    }
    if (front == back) {
        return 1;
    }

    if (front > back) {
        return (capacity - front) + (back + 1);
    } else {
        return back - front + 1;
    }
}

template<class T>
void CircularArray<T>::push_front(T data) {
    if (is_empty()) {
        front = back = 0;
    } else {
        front = next(front);
    }
    array[front] = data;
}

template<class T>
void CircularArray<T>::push_back(T data) {
    if (is_empty()) {
        back = front = 0;
    } else {
        back = next(back);
    }
    array[back] = data;
}

template<class T>
void CircularArray<T>::clear() {

}

template<class T>
void CircularArray<T>::sort() {

}

template<class T>
bool CircularArray<T>::is_sorted() {
    return false;
}

template<class T>
void CircularArray<T>::reverse() {

}

template<class T>
void CircularArray<T>::insert(T data, int pos) {

}

template<class T>
T CircularArray<T>::pop_front() {
    T &value = array[front];
    front = prev(front);

    return value;
}

template<class T>
T CircularArray<T>::pop_back() {
    T &value = array[back];
    back = prev(back);

    return value;
}

template<class T>
T &CircularArray<T>::operator[](int) {
    return array[1];
}
