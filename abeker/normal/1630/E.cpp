#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 998244353;

int phi[MAXN];
int fact[MAXN], ifact[MAXN];

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

int pot(int x, int y) {
  int res = 1;
  for (; y; y /= 2) {
    if (y % 2)
      res = mul(res, x);
    x = mul(x, x);
  }
  return res;
}

int inverse(int x) {
  return pot(x, MOD - 2);
}

void init() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = mul(fact[i - 1], i);
    ifact[i] = inverse(fact[i]);
  }
  for (int i = 1; i < MAXN; i++) {
    phi[i] += i;
    for (int j = 2 * i; j < MAXN; j += i)
      phi[j] -= phi[i];
  }
}

int solve() {
  int N;
  scanf("%d", &N);
  vector <int> freq(N + 1);
  for (int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    freq[x]++;
  }
  int g = 0;
  unordered_map <int, int> cnt;
  for (int i = 1; i <= N; i++) {
    g = __gcd(g, freq[i]);
    cnt[freq[i]]++;
  }
  if (g == N)
    return 1;
  int num = 0, denom = 0;
  for (int d = 1; d <= g; d++)
    if (!(g % d)) {
      int sum = 0;
      int n = N / d;
      int prod = mul(phi[d], fact[n - 2]);
      for (auto it : cnt) {
        int tmp = it.first / d;
        prod = mul(prod, pot(ifact[tmp], it.second));
        sum = add(sum, mul(it.second, mul(tmp, tmp - 1)));
      }
      denom = add(denom, mul(prod, mul(n, n - 1)));
      num = add(num, mul(prod, sum));
    }
  return mul(N, add(1, -mul(num, inverse(denom))));
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while (tc--) 
    printf("%d\n", solve());
  return 0;
}