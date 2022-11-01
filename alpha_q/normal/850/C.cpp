#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 105;

int n, a[N];
map <int, ll> mask;
map <ll, int> f;

int getMex (set <ll> s) {
  int ret = 0;
  for (ll x : s) {
    if (x != ret) return ret;
    ++ret;
  }
  return ret;
}

int call (ll x) {
  if (x == 0) return 0;
  if (f.find(x) != f.end()) return f[x];
  set <ll> trans;
  for (int i = 1; i <= 32; ++i) {
    ll saved = x & ((1LL << i) - 1);
    ll fucked = x >> i;
    if (fucked & 1LL) fucked ^= 1LL;
    ll y = saved | fucked;
    if (y != x) trans.insert(call(y));
  }
  return f[x] = getMex(trans);
}

int main() {
  scanf("%d", &n);
  for (int it = 1; it <= n; ++it) {
    ll x;
    scanf("%lld", &x);
    for (ll i = 2; i * i <= x; ++i) {
      if (x % i) continue;
      int e = 0;
      while (x % i == 0) ++e, x /= i;
      if (mask.find(i) == mask.end()) mask[i] = 0;
      mask[i] |= (1LL << e);
    }
    if (x > 1) {
      if (mask.find(x) == mask.end()) mask[x] = 0;
      mask[x] |= (1LL << 1);
    }
  }
  ll sum = 0;
  for (auto it : mask) {
    sum ^= call(it.second);
  }
  puts(sum ? "Mojtaba" : "Arpa");
  return 0;
}