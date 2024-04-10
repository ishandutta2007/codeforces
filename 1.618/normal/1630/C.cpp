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

#define maxn 200005
int n, a[maxn], ed[maxn], maxed[maxn], f[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    ed[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    maxed[i] = max(maxed[i - 1], ed[a[i]]);
  }
  for (int i = n; i >= 1; i--) {
    f[i] = f[i + 1] + 1;
    if (maxed[i] > i) {
      chmin(f[i], f[maxed[i]] + 1);
      chmin(f[i], f[maxed[i] + 1] + 2);
    }
  }
  printf("%d\n", n - f[1]);
  return 0;
}