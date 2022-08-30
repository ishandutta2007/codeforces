#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int sub(int x, int y) { return x < y ? x - y + mod : x - y; }
inline int mul(int x, int y) { return 1ull * x * y % mod; }
inline int qsm(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) {
      ans = mul(ans, x);
    }
    y >>= 1;
    x = mul(x, x);
  }
  return ans;
}

const int maxN = 2e5 + 5;

int cnt[maxN], sum[maxN], pw[maxN];
int n, odd, ans;

int main() {
  pw[0] = 1;
  for (int i = 1; i < maxN; i++) pw[i] = add(pw[i - 1], pw[i - 1]);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a; scanf("%d", &a);
    if (a % 2 == 1) {
      ++odd;
    } else {
      int bit = 0;
      while (a % 2 == 0) ++bit, a >>= 1;
      ++cnt[bit];
    }
  }
  for (int i = 29; i >= 1; i--) sum[i] = sum[i + 1] + cnt[i];
  ans = sub(pw[n], pw[n - odd]);
  for (int i = 1; i <= 29; i++) {
    if (cnt[i]) {
      ans = add(ans, mul(sub(pw[cnt[i] - 1], 1), pw[sum[i + 1]]));
    }
  }
  printf("%d\n", ans);
  return 0;
}