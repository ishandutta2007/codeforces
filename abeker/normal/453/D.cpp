#include <bits/stdc++.h>
#define bc __builtin_popcount
using namespace std;

typedef long long ll;

const int MAXM = 20;

ll T, MOD;
int M, N, P;
int b[MAXM + 1];
ll c[1 << MAXM];
ll e[1 << MAXM];
ll memo[MAXM + 1];

void load() {
  scanf("%d%lld%d", &M, &T, &P);
  N = 1 << M;
  for (int i = 0; i < N; i++)
    scanf("%lld", e + i);
  for (int i = 0; i <= M; i++)
    scanf("%d", b + i);
}

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

ll pot(ll x, ll y) {
  ll res = 1;
  for (; y; y /= 2) {
    if (y % 2)
      res = mul(res, x);
    x = mul(x, x);
  }
  return res;
}

void fwht(ll* a, int len) {
  if (len == 1)
    return;
  fwht(a, len / 2);
  fwht(a + len / 2, len / 2);
  for (int i = 0; i < len / 2; i++) {
    ll sum = add(a[i], a[i + len / 2]);
    ll diff = add(a[i], -a[i + len / 2]);
    a[i] = sum;
    a[i + len / 2] = diff;
  }
}

void solve() {
  MOD = (ll)P * N;
  for (int i = 0; i < N; i++) {
    c[i] = b[bc(i)] % MOD;
    e[i] %= MOD;
  }
  fwht(e, N);
  fwht(c, N);
  memset(memo, -1, sizeof memo);
  for (int i = 0; i < N; i++) {
    ll &ref = memo[bc(i)];
    if (ref == -1)
      ref = pot(c[i], T);
    e[i] = mul(e[i], ref);
  }
  fwht(e, N);
  for (int i = 0; i < N; i++)
    printf("%lld\n", e[i] / N);
}

int main() {
  load();
  solve();
  return 0;
}