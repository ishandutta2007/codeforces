#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;

int const sigma = 10;
std::string pattern = "codeforces";
int v[1 + sigma];

void increment() {
  int id = 0;
  for(int i = 0;i < sigma; i++)
    if(v[i] < v[id])
      id = i;
  v[id]++;
}

ll eval() {
  ll result = 1;
  for(int i = 0; i < sigma; i++)
    result = result * v[i];
  return result;
}

int main() {
  ll k;
  std::cin >> k;
  while(eval() < k)
    increment();
  for(int i = 0;i < sigma; i++)
    for(int j = 0; j < v[i]; j++)
      std::cout << pattern[i];
}