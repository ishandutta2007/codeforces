#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 5;
const int MOD = 998244353;

int N;
int a[MAXN];
int fact[MAXN], inv[MAXN];

inline int mul(int x, int y) {
  return (ll)x * y % MOD;
}

int pot(int x, int y) {
  int res = 1;
  for (; y; y /= 2) {
    if (y % 2)
      res = mul(res, x);
    x = mul(x, x);
  }
  return res;
}

int choose(int n, int k) {
  return mul(fact[n], mul(inv[k], inv[n - k]));
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < 2 * N; i++)
    scanf("%d", a + i);
  sort(a, a + 2 * N);
  fact[0] = inv[0] = 1;
  for (int i = 1; i <= 2 * N; i++) {
    fact[i] = mul(fact[i - 1], i);
    inv[i] = pot(fact[i], MOD - 2);
  }
  ll diff = accumulate(a + N, a + 2 * N, 0ll) - accumulate(a, a + N, 0ll);
  printf("%d\n", mul(diff % MOD, choose(2 * N, N)));
  return 0;
}