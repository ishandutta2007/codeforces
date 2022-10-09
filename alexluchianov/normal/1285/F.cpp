#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
ll const inf = 1LL * nmax * nmax;
int frec[1 + nmax];
ll dp[1 + nmax];

bool solve(ll target) {
  for(int i = nmax; 1 <= i; i--) {
    dp[i] = 0;
    int lim = nmax / i;
    int ptr = lim + 1, acc = 0;
    
    for(int j = 1; j <= lim; j++) {
      while(1 < ptr && target <= 1LL * (ptr - 1) * j * i * i) {
        ptr--;
        acc += frec[ptr * i];
      }
      dp[i] += acc * frec[i * j];
    }
    for(int j = i * 2; j <= nmax; j += i)
      dp[i] -= dp[j];
  }
  return 0 < dp[1];
}

ll binarysearch(ll from, ll to) {
  if(from < to) {
    ll mid = (from + to + 1) / 2;
    if(solve(mid) == 1)
      return binarysearch(mid, to);
    else
      return binarysearch(from, mid - 1);
  } else
    return from;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    frec[val] = 1;
  }
  for(int i = 1; i <= nmax; i++)
    for(int j = i; j <= nmax; j += i)
      frec[i] |= frec[j];
  std::cout << binarysearch(1, inf) << '\n';
  return 0;
}