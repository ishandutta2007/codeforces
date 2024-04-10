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
int n;

bool sqr(int x) {
  return int(sqrt(x)) * int(sqrt(x)) == x;
}

void solve() {
  scanf("%d", &n);
  if (n % 2 == 0 && sqr(n / 2)) puts("YES");
  else if (n % 4 == 0 && sqr(n / 4)) puts("YES");
  else puts("NO");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}