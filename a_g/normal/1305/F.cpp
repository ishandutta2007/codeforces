#include <bits/stdc++.h>
using namespace std;

vector<long long> get_prime_factors(long long x) {
  vector<long long> ans;
  for (int p = 2; 1LL*p*p <= x; p++) {
    if (x % p == 0) {
      ans.push_back(p);
      while (x % p == 0) x /= p;
    }
  }
  if (x > 1) ans.push_back(x);
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n;
  cin >> n;
  vector<long long> a(n);
  for (long long& x: a) cin >> x;
  long long ans = 1e9;
  auto calc = [&] (long long p) {
    long long d = 0;
    for (long long x: a) {
      if (x < p) d += (p-x);
      else d += min(x%p, p-x%p);
      if (d > ans) return;
    }
    ans = min(ans, d);
  };
  int trials = 50;
  while (trials--) {
    int i = rng()%n;
    int j = rng()%3-1;
    for (long long p: get_prime_factors(a[i]+j)) {
      calc(p);
    }
  }
  cout << ans << '\n';
}