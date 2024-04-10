#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const int B = 12;
const int D = 64;
const int MASK = 1030;

int q, b;
ll f[B][D][MASK];
ll sum[B][D];

ll call (int base, int rem, int mask) {
  if (rem <= 0) return mask == 0;
  ll &ret = f[base][rem][mask];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = 0; i < base; ++i) {
    ret += call(base, rem - 1, mask ^ 1 << i);
  }
  return ret;
}

ll solve (ll x) {
  if (x == 0) return 0;
  vector <int> v;
  while (x) {
    v.push_back(x % b);
    x /= b;
  }
  reverse(v.begin(), v.end());
  int mask = 0, sz = v.size();
  ll ans = 0;
  for (int i = 0; i < sz; ++i) {
    mask ^= 1 << v[i];
    if (i + 1 < sz) {
      for (int j = 0; j < v[i + 1]; ++j) {
        ans += call(b, sz - 2 - i, mask ^ 1 << j);
      }
    } else {
      ans += (mask == 0);
    }
  }
  for (int i = 1; i < v[0]; ++i) {
    ans += call(b, sz - 1, 1 << i);
  }
  for (int i = 1; i < sz; ++i) {
    for (int j = 1; j < b; ++j) {
      ans += call(b, sz - 1 - i, 1 << j);
    }
  }
  return ans;
}

int main() {
  memset(f, -1, sizeof f);
  memset(sum, -1, sizeof sum);
  scanf("%d", &q);
  while (q--) {
    ll l, r;
    scanf("%d %lld %lld", &b, &l, &r);
    printf("%lld\n", solve(r) - solve(l - 1));
  }
  return 0;
}