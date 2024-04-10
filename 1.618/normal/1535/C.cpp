/*


Q.E.D.

start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 200005
int n;
char s[maxn];

void solve() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int l = 1, lst[2] = {0, 0};
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      l = lst[(i & 1) ^ 1] + 1;
      lst[i & 1] = i;
    } else if (s[i] == '1') {
      l = lst[i & 1] + 1;
      lst[(i & 1) ^ 1] = i;
    }
    ans += i - l + 1;
  }
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}