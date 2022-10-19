#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e18;

inline ll add(ll x, ll y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;
}

ll mul(ll x, ll y) {
  ll res = 0;
  for (; y; y /= 2) {
    if (y % 2)
      res = add(res, x);
    x = add(x, x);
  }
  return res;
}

void solve() {
  int N, M;
  scanf("%d%d", &N, &M);
  unordered_map <ll, int> cnt, who;
  for (int i = 0; i < N; i++) {
    ll sum = 0;
    for (int j = 0; j < M; j++) {
      ll c;
      scanf("%lld", &c);
      sum = add(sum, mul(c, M - j));
    }
    who[sum] = i;
    cnt[sum]++;
  }
  ll spec, other;
  for (auto it : cnt)
    if (it.second == 1)
      spec = it.first;
    else
      other = it.first;
  printf("%d %lld\n", who[spec] + 1, add(other, -spec));
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    solve();
  return 0;
}