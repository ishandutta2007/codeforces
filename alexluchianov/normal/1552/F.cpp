#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 200000;

int const modulo = 998244353;
int x[1 + nmax], y[1 + nmax], s[1 + nmax];
int modifier[1 + nmax];


int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) 
    std::cin >> x[i] >> y[i] >> s[i];
  int result = x[n] + 1, acc = 0;
  
  for(int i = n; 1 <= i; i--) {
    acc -= modifier[i];
    if(acc < 0)
      acc += modulo;
    int tps = (acc + s[i]);
    if(modulo <= tps)
      tps -= modulo;
    result = (result + 1LL * (x[i] - y[i]) * tps) % modulo;
    acc += tps;
    if(modulo <= acc)
      acc -= modulo;
    int start = 0;
    for(int jump = (1 << 20); 0 < jump; jump /= 2)
      if(start + jump <= n && x[start + jump] < y[i])
        start += jump;
    modifier[start] += tps;
    if(modulo <= modifier[start])
      modifier[start] -= modulo;
  }
  std::cout << result << '\n';
  return 0;
}