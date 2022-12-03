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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 300005
typedef pair<int, ll> Pil;
int q, a[maxn], c[maxn], par[19][maxn];

Pil query(int u, int w) {
  if (!a[u])
    return mp(0, 0);
  int v = u;
  for (int i = 18; i >= 0; i--) {
    if (a[par[i][v]])
      v = par[i][v];
  }
  if (a[v] < w) {
    int tmp = a[v];
    a[v] = 0;
    Pil ret = query(u, w - tmp);
    return mp(ret.first + tmp, ret.second + (ll)tmp * c[v]);
  }
  a[v] -= w;
  return mp(w, (ll)w * c[v]);
}

int main() {
  scanf("%d%d%d", &q, a + 1, c + 1);
  for (int i = 2; i <= q + 1; i++) {
    int fl, x, y, z;
    scanf("%d", &fl);
    if (fl == 1) {
      scanf("%d%d%d", &x, &y, &z);
      par[0][i] = x + 1;
      a[i] = y;
      c[i] = z;
      for (int j = 1; j <= 18; j++)
        par[j][i] = par[j - 1][par[j - 1][i]];
    } else {
      scanf("%d%d", &x, &y);
      Pil ans = query(x + 1, y);
      printf("%d %lld\n\n", ans.first, ans.second);
      fflush(stdout);
    }
  }
  return 0;
}