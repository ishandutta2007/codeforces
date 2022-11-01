#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fuck (vector <ll> vec, int bit) {
  if (bit < 0) return 0;
  vector <ll> zero, one;
  for (ll x : vec) {
    if (x & 1LL << bit) one.emplace_back(x);
    else zero.emplace_back(x);
  }
  if (zero.empty() or one.empty()) return fuck(vec, bit - 1);
  vec.clear();
  ll ret = min(fuck(zero, bit - 1), fuck(one, bit - 1));
  return ret | 1LL << bit;
}

int main() {
  int n;
  cin >> n;
  vector <ll> a(n);
  for (auto &x : a) scanf("%lld", &x);
  cout << fuck(a, 30) << '\n';
  return 0;
}