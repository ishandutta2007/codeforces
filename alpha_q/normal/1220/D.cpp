#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

typedef long long ll;

ll get (vector <ll> v) {
  if (v.empty()) return 0;
  vector <ll> ev, od;
  for (auto it : v) {
    if (it & 1) od.emplace_back(it);
    else ev.emplace_back(it >> 1);
  }
  return max((ll) od.size(), get(ev));
}

int main() {
  int n;
  vector <ll> v;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    ll x; scanf("%lld", &x);
    v.emplace_back(x);
  }
  vector <ll> org = v;
  ll ans = 0, pwr = 1;
  vector <ll> good;
  while (!v.empty()) {
    vector <ll> ev, od;
    for (auto it : v) {
      if (it & 1) od.emplace_back(it);
      else ev.emplace_back(it >> 1);
    }
    ll cur = od.size();
    if (cur > ans) {
      ans = cur;
      for (auto &it : od) it *= pwr;
      good = od;
    }
    v = ev, pwr <<= 1LL;
  }
  set <ll> yo(good.begin(), good.end());
  cout << n - ans << '\n';
  for (auto it : org) if (!yo.count(it)) printf("%lld ", it);
  puts("");
  return 0;
}