#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const int N = 505;
const int MAGIC = 1005;
const int MOD = 998244353;

bool isPrime (ll x) {
  if (x < 2) return 0;
  if (x == 2) return 1;
  if (x % 2 == 0) return 0;
  for (ll i = 3; i * i <= x; i += 2) {
    if (x % i == 0) return 0;
  }
  return 1;
}

ll square (ll x) {
  ll lo = 0, hi = 2e9 + 5;
  while (lo < hi) {
    ll mid = lo + hi >> 1;
    if (mid * mid < x) lo = mid + 1;
    else hi = mid;
  }
  return lo;
}

ll cube (ll x) {
  ll lo = 0, hi = 1260000;
  while (lo < hi) {
    ll mid = lo + hi >> 1;
    if (mid * mid * mid < x) lo = mid + 1;
    else hi = mid;
  }
  return lo;
}

ll fourth (ll x) {
  ll lo = 0, hi = 38000;
  while (lo < hi) {
    ll mid = lo + hi >> 1;
    if (mid * mid * mid * mid < x) lo = mid + 1;
    else hi = mid;
  }
  return lo;
}

int n; ll x, tmp;
map <ll, int> ppf;
map <ll, int> cnt;
vector <ll> two;
vector <ll> rest;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    
    tmp = square(x);
    if (tmp * tmp == x and isPrime(tmp)) {
      ppf[tmp] += 2;
      continue;
    }

    tmp = cube(x);
    if (tmp * tmp * tmp == x and isPrime(tmp)) {
      ppf[tmp] += 3;
      continue;
    }

    tmp = fourth(x);
    if (tmp * tmp * tmp * tmp == x and isPrime(tmp)) {
      ppf[tmp] += 4;
      continue;
    }

    // x = pq
    two.push_back(x);
  }

  for (auto num : two) {
    ++cnt[num];
  }

  two.clear();

  for (auto it : cnt) {
    two.push_back(it.first);
    // cout << it.first << " " << it.second << endl;
  }
  
  for (int it = 0; it < MAGIC; ++it) {
    int sz = two.size();
    int found = 0, ii, jj;
    for (int i = 0; i < sz; ++i) {
      for (int j = i + 1; j < sz; ++j) {
        ll x = two[i], y = two[j];
        ll g = __gcd(x, y);
        if (g != 1) {
          ll xx = x / g, yy = y / g;
          ppf[xx] += cnt[x], ppf[yy] += cnt[y], ppf[g] += (cnt[x] + cnt[y]);
          ii = i, jj = j, found = 1;
          break;
        }
      }
      if (found) break;
    }
    if (!found) break;
    rest.clear();
    for (int i = 0; i < sz; ++i) {
      if (i != ii and i != jj) rest.push_back(two[i]);
    }
    two = rest;
  }

  for (int it = 0; it < MAGIC; ++it) {
    rest.clear();
    for (auto num : two) {
      int good = 0;
      for (auto it : ppf) {
        ll p = it.first;
        if (num % p == 0) {
          ll q = num / p;
          ppf[p] += cnt[num];
          ppf[q] += cnt[num];
          good = 1;
          break;
        }
      }
      if (!good) {
        rest.push_back(num);
      }
    }
    two = rest;
  }

  // for (auto it : two) cout << it << endl;

  ll ans = 1;
  for (auto it : ppf) {
    ans *= ((it.second + 1) % MOD);
    ans %= MOD;
  }

  for (auto num : two) {
    // cout << num << endl;
    ll mul = (cnt[num] + 1) % MOD;
    mul *= mul, mul %= MOD;
    // cout << mul << endl;
    ans *= mul, ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}