/*


Q.E.D.
*/
/*
BULB: 10min
result of thinking: Pure.
MO.
 
start coding: 13:47
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

#define maxk 100005
#define maxn 1005
#define mp make_pair
typedef pair<int, int> P;
int n, m, k, ans[maxn][maxn];
P a[maxk]; // (cnt of i, i).

void solve() {
  scanf("%d%d", &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a + 1, a + k + 1, greater<P>());
  n = 0;
  while (n * n - (n / 2) * (n / 2) < m ||
         ((n + 1) / 2) * n < a[1].first)
    n++;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans[i][j] = 0;
    }
  }
  if (n == 1) {
    ans[1][1] = a[1].second;
  } else {
    int cx = 1, cy = 2;
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= a[i].first; j++) {
        ans[cx][cy] = a[i].second;
        if (cy % 2 == 0) {
          if (cy + 2 <= n) {
            cy += 2;
          } else if (cx + 2 <= n) {
            cx += 2, cy = 2;
          } else {
            cx = 1, cy = 1;
          }
        } else if (cx & 1) {
          if (cy + 2 <= n) {
            cy += 2;
          } else if (cx + 2 <= n) {
            cx += 2, cy = 1;
          } else {
            cx = 2, cy = 1;
          }
        } else {
          if (cy + 2 <= n) {
            cy += 2;
          } else if (cx + 2 <= n) {
            cx += 2, cy = 1;
          }
        }
      }
    }
  }
  printf("%d\n", n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d%c", ans[i][j], j == n ? '\n' : ' ');
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}