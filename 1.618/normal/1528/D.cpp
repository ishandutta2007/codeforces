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

#define maxn 605
#define mp make_pair
typedef pair<int, int> P;
int n, m, w[maxn][maxn], dis[maxn];
bool vis[maxn];

int query(int u, int v, int r) {
  return w[u][(v - r + n) % n];
}

void work(int s) {
  memset(vis, 0, sizeof(vis));
  memset(dis, 0x3f, sizeof(dis));
  dis[s] = 0;
  for (int i = 0; i < n; i++) {
    int u = -1;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && (u == -1 || dis[u] > dis[j]))
        u = j;
    }
    vis[u] = true;
    for (int v = 0; v < n; v++)
      chmin(dis[v], dis[u] + query(u, v, dis[u] % n));
  }
  for (int i = 0; i < n; i++) {
    printf("%d%c", dis[i], i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  scanf("%d%d", &n, &m);
  memset(w, 0x3f, sizeof(w));
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    w[a][b] = c;
  }
  for (int i = 0; i < n; i++) {
    int j = min_element(w[i], w[i] + n) - w[i];
    for (int k = 1; k < n; k++) {
      chmin(w[i][(j + k) % n], w[i][(j + k - 1) % n] + 1);
    }
  }
  for (int i = 0; i < n; i++)
    work(i);
  return 0;
}