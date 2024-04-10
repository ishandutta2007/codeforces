/*


Q.E.D.

start thinking:
BULB:
result of thinking:

#vp

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

#define maxn 55
int n, a[maxn];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  bool inc = true;
  for (int i = 1; i <= n; i++) {
    if (a[i] != i)
      inc = false;
  }
  if (inc) {
    puts("0");
    return;
  }
  if (a[1] == 1 || a[n] == n) {
    puts("1");
    return;
  }
  if (a[1] == n && a[n] == 1) {
    puts("3");
    return;
  }
  puts("2");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve(); 
  return 0;
}