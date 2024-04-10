/*
start thinking:
BULB:
result of thinking:

start coding:
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

#define maxn 105
int n, x, a[maxn];

void solve() {
  scanf("%d%d", &n, &x);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    if (sum == x) {
      if (i == n) {
        puts("NO");
      } else {
        puts("YES");
        for (int j = 1; j < i; j++) {
          printf("%d ", a[j]);
        }
        printf("%d ", a[n]);
        for (int j = i; j < n; j++) {
          printf("%d ", a[j]);
        }
        puts("");
      }
      return;
    }
  }
  puts("YES");
  for (int i = 1; i <= n; i++) {
    printf("%d%c", a[i], i == n ? '\n' : ' ');
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}