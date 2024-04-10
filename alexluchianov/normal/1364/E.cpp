#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using ll = long long;

std::mt19937 rng(std::chrono::high_resolution_clock().now().time_since_epoch().count());

int rand(int lim) {
  return std::uniform_int_distribution<int>(1, lim)(rng);
}

int ask(int a, int b) {
  std::cout << "? " << a << " " << b << std::endl;
  int number;
  std::cin >> number;
  return number;
}

int const sigma = 13;

int extract(int id, int n) {
  int result = (1 << 13) - 1;
  for(int i = 0; i < sigma; i++) {
    int pos = rand(n);
    if(pos != id)
      result &= ask(id, pos);
  }
  return result;
}

int main() {
  int n;
  std::cin >> n;
  int pos = 1, result = extract(1, n);
  for(int i = 2; i <= n; i++) {
    if(ask(pos, i) == result) {
      pos = i;
      result = extract(pos, n);
    }
  }
  std::vector<int> sol(1 + n);
  for(int i = 1;i <= n; i++) {
    if(pos == i)
      sol[i] = 0;
    else
      sol[i] = ask(pos, i);
  }
  std::cout << "! ";
  for(int i = 1;i <= n; i++)
    std::cout << sol[i] << " ";
  std::cout << std::endl;
  return 0;
}