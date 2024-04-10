/*


Q.E.D.

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

#define maxn 1005
int n;
char s[maxn];
 
void solve() {
  scanf("%d%s", &n, s + 1);
  int tot = 0, same0 = 0;
  for (int i = 1; i < n + 1 - i; i++) {
    tot += (s[i] != s[n + 1 - i]);
    same0 += (s[i] == '0' && s[n + 1 - i] == '0');
  }
  bool palin = (tot == 0);
  if (n & 1)
    tot += (s[(n + 1) / 2] == '0');
  if (tot == 0) {
    puts("BOB");
  } else if (tot == 1) {
    if (same0)
      puts("ALICE");
    else if (palin)
      puts("BOB");
    else
      puts("ALICE");
  } else if (tot == 2) {
    if (same0)
      puts("ALICE");
    else if ((n & 1) && (s[(n + 1) / 2] == '0'))
      puts("DRAW");
    else
      puts("ALICE");
  } else {
    puts("ALICE");
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}