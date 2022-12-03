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

#define maxn 262155
char s[maxn];
int k, n, f[maxn << 1], q;

int main() {
  scanf("%d", &k);
  n = 1 << k;
  scanf("%s", s + 1);
  reverse(s + 1, s + n);
  fill(f + n, f + 2 * n, 1);
  for (int i = n - 1; i >= 1; i--) {
    f[i] = 0;
    if (s[i] != '0')
      f[i] += f[i << 1];
    if (s[i] != '1')
      f[i] += f[i << 1 | 1];
  }
  scanf("%d", &q);
  while (q--) {
    int p;
    char c;
    scanf("%d %c", &p, &c);
    p = n - p;
    s[p] = c;
    for (int i = p; i; i >>= 1) {
      f[i] = 0;
      if (s[i] != '0')
        f[i] += f[i << 1];
      if (s[i] != '1')
        f[i] += f[i << 1 | 1];
    }
    printf("%d\n", f[1]);
  }
  return 0;
}