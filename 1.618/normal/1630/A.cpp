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

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k == n - 1) {
    if (n == 4) 
      puts("-1");
    else {
      printf("%d %d\n", n - 1, n - 2);
      puts("1 3");
      printf("0 %d\n", (n - 1) ^ 3);
      for (int i = 2; i < n / 2; i++) {
        if (i != 3)
          printf("%d %d\n", i, (n - 1) ^ i);
      }
    }
    return;
  }
  printf("%d %d\n", n - 1, k);
  if (k)
    printf("0 %d\n", (n - 1) ^ k);
  for (int i = 1; i < n / 2; i++) {
    if (i != k && i != ((n - 1) ^ k))
      printf("%d %d\n", i, (n - 1) ^ i);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}