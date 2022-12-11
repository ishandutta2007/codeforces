#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


template<typename Container>
Container reversed(Container container);


template<typename Container>
Container digits(typename Container::value_type number, typename Container::value_type base = 10);


template<typename Container>
bool is_palindromic_sequence(const Container &a);

template<typename Type>
bool is_palindromic_number(const Type &a);

template<typename Container>
Container subsequence(const Container &a, size_t begin, size_t end);


int main() {
  ios_base::sync_with_stdio(false);
  string s;
  getline(cin, s);

  size_t maxSize = 0;
  for(size_t begin = 0;begin < s.size();begin++) {
    for(size_t end = begin + 1;end <= s.size();end++) {
      if(!is_palindromic_sequence(subsequence(s, begin, end))) {
	maxSize = max(maxSize, end - begin);
      }
    }
  }

  cout << maxSize << endl;
  
  return 0;
}


template<typename Container>
Container reversed(Container container) {
  reverse(container.begin(), container.end());
  return container;
}

template<typename Container>
Container digits(typename Container::value_type number, typename Container::value_type base) {
  Container res;
  while(number != 0) {
    inserter(res, res.end()) = number % base;
    number /= base;
  }

  return reversed(res);
}

template<typename Container>
bool is_palindromic_sequence(const Container &a) {
  return a == reversed(a);
}

template<typename Type>
bool is_palindromic_number(const Type &a) {
  return is_palindromic_sequence<vector<Type>>(digits<vector<Type>>(a));
}

template<typename Container>
Container subsequence(const Container &a, size_t begin, size_t end) {
  Container res;
  for(size_t i = begin;i < end;i++) {
    inserter(res, res.end()) = a[i];
  }
  return res;
}