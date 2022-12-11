#include <iostream>
#include <vector>
using namespace std;

template<typename Value, typename Iterator>
class Table {
public:
  Table();
  virtual Iterator insert(Iterator _pos, Value _value) = 0;
  virtual Iterator erase(Iterator _pos) = 0;
  virtual Iterator begin() = 0;
  virtual Iterator end() = 0;
  virtual size_t size() = 0;

  void print_of_size(size_t _size);
  void print();
  void read_of_size(size_t _size);
  void read();
  
  void push_back(Value _value);
  Value pop_back();
  void push_front(Value _value);
  Value pop_front();

  size_t count(Value _value);
};


template<typename Value, typename Iterator = typename vector<Value>::iterator>
class Table_stdvector : public Table<Value, Iterator> {
private:
  vector<Value> m_container;
public:
  Table_stdvector();
  Iterator insert(Iterator _pos, Value _value);
  Iterator erase(Iterator _pos);
  Iterator begin();
  Iterator end();
  size_t size();
};


typedef Table_stdvector<char> String;

int main() {
  String s;
  s.read();

  size_t nb8 = s.count('8');

  cout << min(nb8, s.size() / 11) << endl;
  return 0;
}


template<typename Value, typename Iterator>
Table<Value, Iterator>::Table() {}

template<typename Value, typename Iterator>
void Table<Value, Iterator>::print_of_size(size_t _size) {
  Iterator _it = begin();
  for(size_t _i = 0;_i < _size;_i++) {
    cout << (*_it) << " ";
    _it++;
  }
  cout << endl;
}


template<typename Value, typename Iterator>
void Table<Value, Iterator>::print() {
  cout << size() << endl;
  print_of_size(size());
}

template<typename Value, typename Iterator>
void Table<Value, Iterator>::read_of_size(size_t _size) {
  for(size_t _i = 0;_i < _size;_i++) {
    Value _value;
    cin >> _value;
    push_back(_value);
  }
}

template<typename Value, typename Iterator>
void Table<Value, Iterator>::read() {
  size_t _size;
  cin >> _size;
  read_of_size(_size);
}

template<typename Value, typename Iterator>
void Table<Value, Iterator>::push_back(Value _value) {
  insert(end(), _value);
}

template<typename Value, typename Iterator>
Value Table<Value, Iterator>::pop_back() {
  Iterator _it = end();
  _it--;
  Value _value = *_it;
  erase(_it);
  return _value;
}

template<typename Value, typename Iterator>
void Table<Value, Iterator>::push_front(Value _value) {
  insert(begin(), _value);
}

template<typename Value, typename Iterator>
Value Table<Value, Iterator>::pop_front() {
  Iterator _it = begin();
  Value _value = *_it;
  erase(_it);
  return _value;
}

template<typename Value, typename Iterator>
size_t Table<Value, Iterator>::count(Value _value) {
  size_t _res = 0;
  for(Value _val : (*this)) {
    if(_value == _val) {
      _res++;
    }
  }
  return _res;
}

template<typename Value, typename Iterator>
Table_stdvector<Value, Iterator>::Table_stdvector() : m_container() {}

template<typename Value, typename Iterator>
Iterator Table_stdvector<Value, Iterator>::insert(Iterator _pos, Value _value) {
  return m_container.insert(_pos, _value);
}

template<typename Value, typename Iterator>
Iterator Table_stdvector<Value, Iterator>::erase(Iterator _pos) {
  return m_container.erase(_pos);
}

template<typename Value, typename Iterator>
Iterator Table_stdvector<Value, Iterator>::begin() {
  return m_container.begin();
}

template<typename Value, typename Iterator>
Iterator Table_stdvector<Value, Iterator>::end() {
  return m_container.end();
}

template<typename Value, typename Iterator>
size_t Table_stdvector<Value, Iterator>::size() {
  return m_container.size();
}