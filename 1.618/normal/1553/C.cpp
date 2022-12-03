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

int calc(int S) {
  static int cnt[2];
  cnt[0] = cnt[1] = 0;
  for (int i = 0; i < 10; i++) {
    cnt[i & 1] += S >> i & 1;
    if (cnt[0] + ((9 - i) >> 1) < cnt[1])
      return i + 1;
    if (cnt[0] > cnt[1] + ((10 - i) >> 1))
      return i + 1;
  }
  return 10;
}

int f[1035];
char s[15];

void solve() {
  scanf("%s", s);
  int ans = 10;
  for (int S = 0; S < (1 << 10); S++) {
    bool ok = true;
    for (int i = 0; i < 10; i++) {
      if ((S >> i & 1) && (s[i] == '0'))
        ok = false;
      if (!(S >> i & 1) && (s[i] == '1'))
        ok = false;
    }
    if (ok)
      chmin(ans, f[S]);
  }
  printf("%d\n", ans);
}

int main() {
  for (int i = 0; i < (1 << 10); i++)
    f[i] = calc(i);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}