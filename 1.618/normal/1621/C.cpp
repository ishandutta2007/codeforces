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

#define maxn 10005
int n, p[maxn];

int query(int i) {
  printf("? %d\n", i);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  if (!x)
    exit(0);
  return x;
}

void solve() {
  memset(p, 0, sizeof(p));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    if (p[i])
      continue;
    vector<int> lis;
    int st = query(i);
    while (true) {
      int x = query(i);
      lis.push_back(x);
      if (x == st)
        break;
    }
    for (int i = 0; i + 1 < (int)lis.size(); i++)
      p[lis[i]] = lis[i + 1];
    p[lis.back()] = lis[0];
  }
  printf("! ");
  for (int i = 1; i <= n; i++)
    printf("%d%c", p[i], " \n"[i == n]);
  fflush(stdout);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}