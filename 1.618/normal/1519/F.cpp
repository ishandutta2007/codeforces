/*


Q.E.D.
*/
/*
BULB: 0.5h 
result of thinking: Aided.
#(bad) #dp #MeetInTheMiddle #FMT 

start coding: 09:20
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

const int inf = 0x3f3f3f3f;
int pow5[11], n, m, a[7], b[7], c[7][7], f1[1953135], f2[1953135];

bool valid(int al, int ar, int state) {
  for (int i = 1; i <= m; i++) {
    if (state / pow5[m - i] % 5 > b[i])
      return false;
  }
  for (int i = al; i <= ar; i++) {
    if (state / pow5[m + ar - i] % 5 > a[i])
      return false;
  }
  return true;
}

int main() {
  pow5[0] = 1;
  for (int i = 1; i <= 9; i++)
    pow5[i] = pow5[i - 1] * 5;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  for (int i = 1; i <= m; i++)
    scanf("%d", b + i);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &c[i][j]);
    }
  }
  if (n <= 3) {
    memset(f1, 0x3f, sizeof(f1));
    f1[0] = 0;
    for (int u = 1; u <= n; u++) {
      for (int v = 1; v <= m; v++) {
        for (int i = pow5[n + m] - 1; i >= 0; i--) {
          if (!valid(1, n, i))
            continue;
          int maxFlow = min(a[u] - i / pow5[m + n - u] % 5,
                            b[v] - i / pow5[m - v] % 5);
          for (int d = 1; d <= maxFlow; d++) {
            chmin(f1[i + d * (pow5[m + n - u] + pow5[m - v])], 
                  f1[i] + c[u][v]);
          }
        }
      }
    }
    int ans = inf, aFULL = 0;
    for (int i = 1; i <= n; i++)
      aFULL += pow5[m + n - i] * a[i];
    for (int i = 0; i < pow5[m]; i++) {
      if (valid(1, n, i)) {
        chmin(ans, f1[aFULL + i]);
      }
    }
    printf("%d\n", ans < inf ? ans : -1);
    return 0;
  }
  memset(f1, 0x3f, sizeof(f1));
  f1[0] = 0;
  for (int u = 1; u <= 3; u++) {
    for (int v = 1; v <= m; v++) {
      for (int i = pow5[3 + m] - 1; i >= 0; i--) {
        if (!valid(1, 3, i))
          continue;
        int maxFlow = min(a[u] - i / pow5[3 + m - u] % 5,
                          b[v] - i / pow5[m - v] % 5);
        for (int d = 1; d <= maxFlow; d++) {
          chmin(f1[i + d * (pow5[3 + m - u] + pow5[m - v])],
                f1[i] + c[u][v]);
        }
      }
    }
  }
  memset(f2, 0x3f, sizeof(f2));
  f2[0] = 0;
  for (int u = 4; u <= n; u++) {
    for (int v = 1; v <= m; v++) {
      for (int i = pow5[n - 3 + m] - 1; i >= 0; i--) {
        if (!valid(4, n, i))
          continue;
        int maxFlow = min(a[u] - i / pow5[m + n - u] % 5,
                          b[v] - i / pow5[m - v] % 5);
        for (int d = 1; d <= maxFlow; d++) {
          chmin(f2[i + d * (pow5[m + n - u] + pow5[m - v])],
                f2[i] + c[u][v]);
        }
      }
    }
  }
  int a1FULL = 0, a2FULL = 0, bFULL = 0, ans = inf;
  for (int i = 1; i <= 3; i++)
    a1FULL += a[i] * pow5[3 + m - i];
  for (int i = 4; i <= n; i++)
    a2FULL += a[i] * pow5[n + m - i];
  for (int i = 1; i <= m; i++)
    bFULL += b[i] * pow5[m - i];
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < pow5[m]; j++) {
      if (valid(4, n, j) && j / pow5[m - i] % 5) {
        chmin(f2[a2FULL + j], f2[a2FULL + j - pow5[m - i]]);
      }
    }
  }
  for (int i = 0; i < pow5[m]; i++) {
    if (valid(1, 3, i)) {
      chmin(ans, f1[a1FULL + i] + f2[a2FULL + bFULL - i]);
    }
  }
  printf("%d\n", ans < inf ? ans : -1);
  return 0;
}