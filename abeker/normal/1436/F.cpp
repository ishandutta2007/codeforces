#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 998244353;

int N;
ll freq[MAXN];
int sum[MAXN], sq[MAXN];
int prime[MAXN];

inline int mul(int x, int y) {
  return (ll)x * y % MOD;
}

int pot(int x, ll y) {
  if (y < 0)
    return 0;
  int res = 1;
  for (y %= MOD - 1; y; y /= 2) {
    if (y % 2)
      res = mul(res, x);
    x = mul(x, x);
  }
  return res;
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;  
}

inline void inc(int &x, int y) {
  x = add(x, y);
}

void load() {
  scanf("%d", &N);
  while (N--) {
    int a, f;
    scanf("%d%d", &a, &f);
    freq[a] += f;
    inc(sum[a], mul(f, a));
    inc(sq[a], mul(f, mul(a, a)));
  }
}

int solve() {
  for (int i = 1; i < MAXN; i++) {
    bool is_prime = i > 1 && !prime[i];
    if (is_prime)
      prime[i] = i;
    for (int j = 2 * i; j < MAXN; j += i) {
      freq[i] += freq[j];
      inc(sum[i], sum[j]); 
      inc(sq[i], sq[j]); 
      if (is_prime && !prime[j])
        prime[j] = i;
    }
  }
  int sol = 0;
  for (int i = 1; i < MAXN; i++) {
    int parity = 0;
    for (int x = i; x > 1; x /= prime[x]) {
      if (!(x % ((ll)prime[x] * prime[x]))) {
        parity = -1;
        break;
      }
      parity ^= 1;
    }
    if (parity == -1 || freq[i] <= 1)
      continue;
    int pairs = add(mul(sum[i], sum[i]), -sq[i]);
    int tmp = mul(sq[i], mul((freq[i] - 1) % MOD, pot(2, freq[i] - 2)));
    inc(tmp, mul(pairs, add(pot(2, freq[i] - 2), mul((freq[i] - 2) % MOD, pot(2, freq[i] - 3)))));
    inc(sol, parity ? -tmp : tmp);
  }
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}