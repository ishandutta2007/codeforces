#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename Container>
typename Container::value_type sum(const Container& container);

template< typename ContainerOut, typename ContainerIn, typename Operation>
ContainerOut apply(const ContainerIn& container, Operation op);


string s;

bool is_contained(string c) {
  return s.find(c) != string::npos;
}

int main() {
  getline(cin, s);
  vector<string> strings = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};
  bool is_possible = sum(apply<vector<int>>(strings, is_contained));

  if(is_possible)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}


template<typename Container>
typename Container::value_type sum(const Container& container) {
  typename Container::value_type sum = 0;
  for(auto elem : container) {
    sum += elem;
  }
  return sum;
}


template< typename ContainerOut, typename ContainerIn, typename Operation>
ContainerOut apply(const ContainerIn& container, Operation op) {
  ContainerOut res;
  for(auto elem : container) {
    inserter(res, res.end()) = op(elem);
  }
  return res;
}