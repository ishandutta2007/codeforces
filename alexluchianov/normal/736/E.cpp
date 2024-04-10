#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

int const nmax = 3000;
int v[5 + nmax];
char rel[5 + nmax][5 + nmax];
int given[5 + nmax];

int main() {
  int n, m;
  std::cin >> m >> n;
  for(int i = m; m - n < i; i--) {
    std::cin >> v[i];
  }
  int sum = m * (m - 1);
  for(int i = m - n + 1; i <= m; i++)
    sum -= v[i];
  for(int i = m - n; 1 <= i; i--) {
    v[i] = sum / i + (0 < (sum % i));
    sum -= v[i];
  }
  sum = 0;
  for(int i = 1;i <= m; i++) {
    sum += v[i];
    if(sum < i * (i - 1)) {
      std::cout << "no\n";
      return 0;
    }
    if(v[i] < 0 || 2 * (m - 1) < v[i]) {
      std::cout << "no\n";
      return 0;
    }
    if(i + 1 <= m && v[i] > v[i + 1]) {
      std::cout << "no\n";
      return 0;
    }
  }

  if(sum != m * (m - 1)) {
    std::cout << "no\n";
    return 0;
  }
  
  for(int i = m;1 <= i; i--) {
    int cap = 2 * (i - 1);
    assert(v[i] <= cap);
    cap -= v[i];
    v[i] = 0;
    for(int j = 1;j <= i; j++)
      given[j] = 0;
    int ptr = i - 1;
    while(0 < cap && 0 < ptr) {
      if(v[ptr - 1] < v[ptr] && given[ptr] < 2) {
        v[ptr]--;
        cap--;
        given[ptr]++;
        if(ptr + 1 < i)
          ptr++;
      } else
        ptr--;
    }
    while(0 < cap && 0 < ptr) {
      if(v[ptr - 1] < v[ptr] && given[ptr] < 2) {
        v[ptr]--;
        cap--;
        given[ptr]++;
        if(ptr + 1 < i)
          ptr++;
      } else
        ptr--;
    }
    assert(cap == 0);
    rel[i][i] = 'X';
    for(int j = 1;j < i; j++)
      if(given[j] == 1) {
        rel[i][j] = 'D';
        rel[j][i] = 'D';
      } else if(given[j] == 0) {
        rel[i][j] = 'W';
        rel[j][i] = 'L';
      } else {
        rel[i][j] = 'L';
        rel[j][i] = 'W';
      }
  }

  std::cout << "yes\n";
  for(int i = 1; i <= m; i++)
    std::cout << (rel[i] + 1) << '\n';
  return 0;
}