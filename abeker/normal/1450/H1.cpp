#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MOD = 998244353;

int N;
char s[MAXN];
int inv[MAXN];
int fact[MAXN], ifact[MAXN];

void load() {
  scanf("%d%*d%s", &N, s);
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

int choose(int n, int k) {
  return k < 0 || n < k ? 0 : mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int solve() {
  inv[1] = 1;
  for (int i = 2; i <= N; i++)
    inv[i] = MOD - mul(MOD / i, inv[MOD % i]);
  fact[0] = ifact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = mul(fact[i - 1], i);
    ifact[i] = mul(ifact[i - 1], inv[i]);
  }
  int sum = 0;
  vector <int> cnt(2);
  for (int i = 0; i < N; i++)
    if (s[i] == 'b')
      sum += i % 2 ? -1 : 1;
    else if (s[i] == '?')
      cnt[i % 2]++;
  int sol = 0;
  int n = cnt[0] + cnt[1], d = cnt[1] - sum;
  for (int i = 1; i <= N / 4; i++)
    sol = add(sol, mul(i, add(choose(n, d + 2 * i), choose(n, d - 2 * i))));
  for (int i = 1; i < n; i++)
    sol = mul(sol, inv[2]);
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}