#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
ll const inf = 4000000000000000000;

int v[1 + nmax];
int sol[1 + nmax];
int sol2[1 + nmax];

ll solve(int n, ll target) {
  for(int i = 1; i <= n; i++) {
    int x = 0;
    for(int jump = (1 << 30); 0 < jump; jump /= 2)
      if(x + jump <= v[i] && target <= v[i] - 3LL * (x + jump) * (x + jump) + 3 * (x + jump) - 1)
        x += jump;
    sol[i] = x;
  }
  ll result = 0;
  for(int i = 1; i <= n; i++)
    result += sol[i];
  return result;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  ll k;
  std::cin >> n >> k;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  
  ll x = inf;
  for(ll jump = (1LL << 62); 0 < jump; jump /= 2) {
    if(solve(n, x - jump) < k)
      x -= jump;
  }
  solve(n, x);
  for(int i = 1; i <= n; i++) {
    sol2[i] = sol[i]; 
    k -= sol2[i];
  }
  solve(n, x - 1);

  for(int i = 1;i <= n; i++) {
    int d = std::min(1LL * sol[i] - sol2[i], k);
    k -= d;
    std::cout << sol2[i] + d << " ";
  }
  std::cout << '\n';
  return 0;
}