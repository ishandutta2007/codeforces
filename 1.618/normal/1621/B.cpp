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

#define maxn 100005
int n, l[maxn], r[maxn], c[maxn], ans[maxn], minl[maxn], maxr[maxn];

void solve() {
  scanf("%d", &n);
  minl[0] = inf;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", l + i, r + i, c + i);
    minl[i] = min(l[i], minl[i - 1]);
    maxr[i] = max(r[i], maxr[i - 1]);
    ans[i] = inf + inf;
    if (l[i] == minl[i] && r[i] == maxr[i])
      chmin(ans[i], c[i]);
  }
  int cstl = inf, cstr = inf;
  for (int i = 1; i <= n; i++) {
    if (minl[i] < minl[i - 1])
      cstl = inf;
    if (minl[i] == l[i])
      chmin(cstl, c[i]);
    if (maxr[i] > maxr[i - 1])
      cstr = inf;
    if (maxr[i] == r[i])
      chmin(cstr, c[i]);
    chmin(ans[i], cstl + cstr);
    if (minl[i] == minl[i - 1] && maxr[i] == maxr[i - 1])
      chmin(ans[i], ans[i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    printf("%d\n", ans[i]);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}