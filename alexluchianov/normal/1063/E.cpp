#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>

using ll = long long;

int const nmax = 1000;
int v[5 + nmax],inv[5 + nmax];
int seen[5 + nmax];

std::string change(std::string base, int pos, char ch) {
  ch = 139 - ch; 
  base[pos - 1] = ch;

  return base;
}
std::string sol[5 + nmax];

int main() {
  int n;
  std::cin >> n;
  bool perfect = true;
  for(int i = 1; i <= n; i++) {
    std::cin >> v[i];
    inv[v[i]] = i;
    perfect &= (v[i] == i);
  }
  if(perfect == true) {
    std::cout << n << '\n';
    for(int i = 1;i <= n; i++) {
      for(int j = 1;j <= n; j++)
        std::cout << ".";
      std::cout << '\n';
    }
    return 0;
  }
  std::string base;
  std::cout << n - 1 << '\n';
  for(int i = 0; i < n; i++)
    base += ".";
  seen[n] = 1;
  if(n != inv[n]) {
    int start = inv[n];
    while(start != n) {
      seen[start] = 1;
      start = inv[start];
    }
  }
  int lines = 0;
  for(int i = 1;i <= n; i++)
    if(i < v[i] && seen[i] == 0) {
      seen[i] = 1;
      ++lines;
      sol[lines] = change(change(change(base, i, 92), v[i], 92), n, 92);
      int start= inv[i];
      while(start != v[i]) {
        seen[start] = 1;
        ++lines;
        if(start < v[start]) 
          sol[lines] = change(change(base, start, 92), v[start], 92);
        else
          sol[lines] = change(change(base, start, 47), v[start], 47);
        start = inv[start];
      }
      seen[start] = 1;
      ++lines;
      sol[lines] = change(change(base, v[start], 47), n, 47);
    }
  if(n != inv[n]) {
    int start = inv[n];
    while(start != n) {
      seen[start] = 1;
      ++lines;
      if(start < v[start]) 
        sol[lines] = change(change(base, start, 92), v[start], 92);
      else
        sol[lines] = change(change(base, start, 47), v[start], 47);
      start = inv[start];
    }
  }
  for(int i = lines + 1; i <= n; i++)
    sol[i] = base;
  for(int i = n; 1 <= i; i--) {
    std::cout << sol[i] << '\n';
  }
  return 0;
}