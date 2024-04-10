/*


Q.E.D.
*/
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

#define maxn 100005
int n, a[maxn];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  int j = min_element(a + 1, a + n + 1) - a;
  printf("%d\n", n - 1);
  for (int i = 1; i <= n; i++) {
    if (i == j) continue;
    printf("%d %d %d %d\n", i, j, abs(i - j) + a[j], a[j]);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}