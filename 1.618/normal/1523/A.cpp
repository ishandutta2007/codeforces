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

#define maxn 1010
int n, m;
char s[maxn], t[maxn];

void go() {
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0' && int(s[i - 1] == '1') + int(s[i + 1] == '1') == 1)
      t[i] = '1';
    else
      t[i] = s[i];
  }
  strcpy(s + 1, t + 1);
}

void solve() {
  memset(s, 0, sizeof(s));
  memset(t, 0, sizeof(t));
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  chmin(m, n);
  while (m--)
    go();
  printf("%s\n", s + 1);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}