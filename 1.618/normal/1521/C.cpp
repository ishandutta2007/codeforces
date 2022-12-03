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

#define maxn 10005
int n, p[maxn];

int qmax(int x, int y) {
  printf("? 1 %d %d %d\n", x, y, n - 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == -1)
    exit(0);
  return res;
}

int qmin(int x, int y) {
  printf("? 2 %d %d %d\n", x, y, 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == -1)
    exit(0);
  return res;
}

void solve() {
  scanf("%d", &n);
  int min12 = min(qmin(1, 2), qmin(2, 1)),
      max12 = max(qmax(1, 2), qmax(2, 1)),
      min31 = min(qmin(1 ,3), qmin(3, 1)),
      max31 = max(qmax(1, 3), qmax(3, 1));
  if (min12 == min31 || min12 == max31) {
    p[1] = min12;
  } else {
    p[1] = max12;
  }
  if (p[1] == 1) {
    for (int i = 2; i <= n; i++) {
      p[i] = qmax(1, i);
    }
  } else if (p[1] <= n / 2) {
    for (int i = 2; i <= n; i++) {
      p[i] = qmax(1, i);
      if (p[i] == p[1])
        p[i] = qmin(i, 1);
    }
  } else if (p[1] < n) {
    for (int i = 2; i <= n; i++) {
      p[i] = qmin(i, 1);
      if (p[i] == p[1])
        p[i] = qmax(1, i);
    }
  } else {
    for (int i = 2; i <= n; i++) {
      p[i] = qmin(i, 1);
    }
  }
  printf("! ");
  for (int i = 1; i <= n; i++)
    printf("%d%c", p[i], i == n ? '\n' : ' ');
  fflush(stdout);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}