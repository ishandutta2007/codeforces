#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 20;
const int MOD = 1e9 + 7;

int N;
char s[MAX + 1];
int one[MAX], zero[MAX];

void load() {
  scanf("%d%s", &N, s);
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

void fwht(int* a, int n, bool invert) {
  if (!n)
    return;
  fwht(a, n - 1, invert);
  fwht(a + (1 << n - 1), n - 1, invert);
  for (int i = 0; i < 1 << n - 1; i++) {
    int memo = a[i + (1 << n - 1)];
    a[i + (1 << n - 1)] = add(a[i], -memo);
    a[i] = add(a[i], memo);
  }
  if (invert)
    for (int i = 0; i < 1 << n; i++)
      a[i] = mul(a[i], (MOD + 1) / 2);
}

int solve() {
  for (int i = 0; i < 1 << N; i++) {
    one[i] = s[i] - '0';
    zero[i] = one[i] ^ 1;
  }
  fwht(one, N, false);
  fwht(zero, N, false);
  for (int i = 0; i < 1 << N; i++)
    one[i] = mul(one[i], zero[i]);
  fwht(one, N, true);
  int sol = 0;
  for (int i = 0; i < 1 << N; i++)
    sol = add(sol, mul(one[i], 1 << __builtin_popcount(i)));
  return mul(sol, 3);
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}