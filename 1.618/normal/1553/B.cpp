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
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}

#define maxs 505
int ns, nt;
char s[maxs], t[maxs << 1];

bool check(int x, int y) {
  for (int i = x; i <= y; i++) {
    if (s[i] != t[i - x + 1])
      return false;
  }
  for (int j = y - 1; j >= 0; j--) {
    if (y - x + y - j + 1 > nt)
      return true;
    if (s[j] != t[y - x + y - j + 1])
      return false;
  }
  return false;
}

void solve() {
  scanf("%s", s + 1);
  ns = strlen(s + 1);
  scanf("%s", t + 1);
  nt = strlen(t + 1);
  for (int i = 1; i <= ns; i++) {
    for (int j = i; j <= ns; j++) {
      if (check(i, j)) {
        puts("Yes");
        return;
      }
    }
  }
  puts("No");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}