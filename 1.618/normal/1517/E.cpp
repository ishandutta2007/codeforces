/*
BULB: 20min. 
result of thinking: Pure.

: C2, C, C
          C2, C, P
          ...P...C
          ...P...P
          C1

start coding: 8:00
AC:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 200005
const int mod = 998244353;
int n, a[maxn];
ll sum[maxn], sum2[maxn];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    sum[i] = sum[i - 1] + a[i];
    sum2[i] = (i > 2 ? sum2[i - 2] : 0) + a[i];
  }
  ll ans = 0;
  // C...C
  for (int i = 1; i <= n - 2; i++) {
    int lb = 0, rb = (i - 1) / 2 + 1;
    while (lb < rb) {
      int mid = (lb + rb) / 2;
      int pos = i - mid * 2;
      if (2 * (sum2[i] + sum2[pos - 1] + a[n]) < sum[n])
        rb = mid;
      else
        lb = mid + 1;
    }
    ans += (i - 1) / 2 - lb + 1;
  }
  // C...P
  for (int i = 3; i < n; i++) {
    int lb = 1, rb = (i - 1) / 2 + 1;
    while (lb < rb) {
      int mid = (lb + rb) / 2;
      int pos = i - mid * 2;
      if (2 * (sum2[i] + sum2[pos - 1]) < sum[n]) 
        rb = mid;
      else
        lb = mid + 1;
    }
    ans += (i - 1) / 2 - lb + 1;
  }
  // P...C
  for (int i = 2; i <= n - 2; i++) {
    int lb = 0, rb = i / 2;
    while (lb < rb) {
      int mid = (lb + rb) / 2;
      int pos = i - mid * 2;
      if (2 * (sum2[i] + sum2[pos - 1] - a[1] + a[n]) < sum[n])
        rb = mid;
      else
        lb = mid + 1;
    }
    ans += i / 2 - lb;
  }
  // P...P
  for (int i = 4; i < n; i++) {
    int lb = 1, rb = i / 2;
    while (lb < rb) {
      int mid = (lb + rb) / 2;
      int pos = i - mid * 2;
      if (2 * (sum2[i] + sum2[pos - 1] - a[1]) < sum[n])
        rb = mid;
      else
        lb = mid + 1;
    }
    ans += i / 2 - lb;
  }
  // contiguous C
  for (int i = 1; i <= 2; i++) {
    for (int j = i; j <= n; j++) {
      ans += (2 * (sum[j] - sum[i - 1]) < sum[n]);
    }
  }
  for (int i = 3; i <= n; i++) {
    ans += (2 * (sum[n] - sum[i - 1]) < sum[n]);
  }
  printf("%lld\n", (ans + 1) % mod);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}