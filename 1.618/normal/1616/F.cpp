/*
start thinking:
BULB:
result of thinking: Lost. .

"=>, =>"
 x + y + z  0 (mod 3).

start coding:
AC:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 68
int n, m;
int eid[maxn][maxn], a[2135][265], r, x[265];

bool gauss() {
  int k = 1;
  for (int i = 1; i <= m; i++) {
    if (k > r)
      break;
    int pivot = k;
    for (int j = k + 1; j <= r; j++) {
      if (abs(a[j][i]) > abs(a[pivot][i]))
        pivot = j;
    }
    for (int j = 1; j <= m + 1; j++)
      swap(a[pivot][j], a[k][j]);
    if (!a[k][i])
      continue;
    for (int j = 1; j <= r; j++) {
      if (j != k) {
        int rate = (3 - a[j][i]) * a[k][i];
        for (int l = i; l <= m + 1; l++) {
          (a[j][l] += rate * a[k][l]) %= 3;
        }
      }
    }
    k++;
  }
  for (int i = k; i <= r; i++) {
    if (a[i][m + 1])
      return false;
  }
  memset(x, 0, sizeof(x));
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        x[j] = a[i][j] * a[i][m + 1] % 3;
        break;
      }
    }
  }
  return true;
}

void solve() {
  r = 0;
  memset(eid, 0, sizeof(eid));
  memset(a, 0, sizeof(a));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    if (u > v)
      swap(u, v);
    eid[u][v] = i;
    if (~c) {
      a[++r][i] = 1;
      a[r][m + 1] = c - 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      for (int k = j + 1; k <= n; k++) {
        if (eid[i][j] && eid[i][k] && eid[j][k]) {
          a[r][eid[i][j]] = a[r][eid[i][k]] = a[++r][eid[j][k]] = 1;
        }
      }
    }
  }
  if (!gauss()) {
    puts("-1");
    return;
  }
  for (int i = 1; i <= m; i++) {
    printf("%d%c", x[i] + 1, " \n"[i == m]);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}