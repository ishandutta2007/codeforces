#include <bits/stdc++.h>
using namespace std;

const int MAXN = 6e5 + 5;
const int MOD = 1e9 + 7;

int N;
char c[MAXN], d[MAXN];
int fact[MAXN], inv[MAXN];
int pw2[MAXN], phi[MAXN];

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

int choose(int n, int k) {
  if (k < 0 || n < k)
    return 0;
  return mul(fact[n], mul(inv[k], inv[n - k]));
}

void init() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = mul(fact[i - 1], i);
    inv[i] = pot(fact[i], MOD - 2);
  }
  pw2[0] = 1;
  for (int i = 1; i < MAXN; i++)
    pw2[i] = add(pw2[i - 1], pw2[i - 1]);
  for (int i = 1; i < MAXN; i++) {
    phi[i] += i;
    for (int j = 2 * i; j < MAXN; j += i)
      phi[j] -= phi[i];
  }
  for (int i = 2; i < MAXN; i++)
    phi[i] = add(add(phi[i], phi[i]), phi[i - 1]);
}

void load() {
  scanf("%s%s%d", c, d, &N);
}

int get_cnt(char* s, char chr) {
  return count(s, s + strlen(s), chr);
}

int solve() {
  int len_c = strlen(c);
  int len_d = strlen(d);
  int a_c = get_cnt(c, 'A');
  int a_d = get_cnt(d, 'A');
  int q_c = get_cnt(c, '?');
  int q_d = get_cnt(d, '?');
  int q_tot = q_c + q_d;
  int val = q_d + a_d - a_c;
  if (len_c == len_d) {
    int both = 0;
    for (int i = 0; i < len_c; i++)
      if (c[i] == '?' && d[i] == '?')
        both++;
      else if (c[i] != '?' && d[i] != '?' && c[i] != d[i]) {
        both = -1;
        break;
      }
    int equal = both == -1 ? 0 : pw2[both];
    int sum = 0, geom = add(pw2[N + 1], -2);
    for (int i = 1; i <= N; i++)
      sum = add(sum, mul(pw2[i], phi[N / i]));
    return add(mul(equal, add(mul(geom, geom), -sum)), add(mul(geom, pw2[q_tot]), mul(choose(q_tot, val), add(sum, -geom))));
  }
  int sol = 0;
  for (int i = 0; i <= q_tot; i++)
    if (i != val) {
      int x = len_d - len_c + i - val;
      int y = i - val;
      int g = __gcd(x, y);
      x /= g;
      y /= g;
      if (y < 0) {
        x = -x;
        y = -y;
      }
      if (x > 0)
        sol = add(sol, mul(choose(q_tot, i), add(pw2[N / max(x, y) + 1], -2)));
    }
  return sol;
}

int main() {
  init();
  load();
  printf("%d\n", solve());
  return 0;
}