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

#define maxn 100005
int ns, nt;
char s[maxn], t[maxn];

int fin(int j, char c) {
  while (j >= 1 && s[j] != c)
    j -= 2;
  return j;
}

void solve() {
  scanf("%s", s + 1);
  ns = strlen(s + 1);
  scanf("%s", t + 1);
  nt = strlen(t + 1);
  for (int i = nt, j = ns; i >= 1; i--) {
    j = fin(j, t[i]) - 1;
    if (j < 0) {
      puts("No");
      return;
    }
  }
  puts("Yes");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}