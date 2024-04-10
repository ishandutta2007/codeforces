#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;
using namespace std;

int const nmax = 50;
int v[5 + nmax], v2[5 + nmax];

std::string afunction(std::string s) {
  return "(" + s + "-" + "abs((" + s + "-1)))";
}

std::string equal(std::string s, std::string t) {
  return "(" + afunction("abs((" + s + "-" + t + "))") + "-1)";
}

void print(int x, int n) {
  if(x < n) {
    std::cout << "(";
    std::cout << "(" << equal("t", std::to_string(x)) << "*" << v[x] / 2 << ")+";
    print(x + 1, n);
    std::cout << ")";
  } else
    std::cout << "(" << equal("t", std::to_string(x)) << "*" << v[x] / 2 << ")";
}

void print2(int x, int n) {
  if(x < n) {
    std::cout << "(";
    std::cout << "(" << equal("t", std::to_string(x)) << "*" << v2[x] / 2 << ")+";
    print2(x + 1, n);
    std::cout << ")";
  } else
    std::cout << "(" << equal("t", std::to_string(x)) << "*" << v2[x] / 2 << ")";
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 0;i < n; i++) {
    int r;
    std::cin >> v[i] >> v2[i] >> r;
    if(v[i] % 2 == 1)
      v[i]++;
    if(v2[i] % 2 == 1)
      v2[i]++;
  }
  std::cout << "(0-";
  print(0, n - 1);
  std::cout << ")\n";
  std::cout << "(0-";
  print2(0, n - 1);
  std::cout << ")\n";
  return 0;
}