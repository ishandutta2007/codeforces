#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
ll const inf = 100000000000000;

int a[5 + nmax], b[5 + nmax];

int n, m, k, p;

ll used[5 + nmax];

bool solve(ll target) {
  for(int i = 1;i <= m + 1; i++)
    used[i] = 0;
  ll total = 0;
  for(int i = 1; i <= n; i++) {
    ll _left = m, curr = target;
    while(0 < _left) {
      ll safe = curr / b[i];
      safe = std::min(_left, safe);
      _left -= safe;
      curr -= b[i] * safe;
      if(curr < b[i] && 0 < _left) {
        ll regen = (b[i] - curr + p - 1) / p;
        used[_left + 1] += regen;
        curr += 1LL * regen * p;
        total += regen;
      }
    }
    if(curr < a[i]) {
      ll regen = (a[i] - curr + p - 1) / p;
      total += regen;
      used[1] += regen;
    }
    if(m * k < total)
      return false;
  }
  int acc = 0;
  for(int i = m; 1 <= i; i--) {
    acc += used[i] - k;
    if(0 < acc)
      return false;
  }
  return true;
}

ll binarysearch(ll from, ll to) {
  if(from < to) {
    ll mid = (from + to) / 2;
    if(solve(mid) == true)
      return binarysearch(from, mid);
    else
      return binarysearch(mid + 1, to);
  } else
    return from;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  std::cin >> n >> m >> k >> p;
  ll smax = 0;
  for(int i = 1;i <= n; i++) {
    std::cin >> a[i] >> b[i];
    smax = std::max(smax, 1LL * b[i]);
  }
  std::cout << binarysearch(smax, inf) << '\n';

  return 0;
}