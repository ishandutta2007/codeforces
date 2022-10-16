// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 605;

ll W[N][N], H[N][N], dis[N];
bool vis[N];
int n, m;

void dijkstra(int u) {
  dis[u] = 0, vis[u] = 0;
  for (int i = 1; i < n; i++) {
    int aim = -1;
    for (int j = 1; j <= n; j++) {
      if (!vis[j] && (aim == -1 || dis[j] < dis[aim])) {
        aim = j;
      }
    }
    vis[aim] = 1;
    for (int j = 1; j <= n; j++) {
      if (!vis[j]) {
        int w = (j - dis[aim] % n + n - 1) % n + 1;
        ckmin(dis[j], dis[aim] + H[aim][w]);
      }
    }
  }
}

int main() {
  memset(W, 0x3f, sizeof(W)), memset(H, 0x3f, sizeof(H));
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int u = read() + 1, v = read() + 1, w = read();
    W[u][v] = w;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k < n; k++) {
        ckmin(H[i][j], k + W[i][(j - k + n - 1) % n + 1]);
      }
    }
  }
  
  for (int i = 1; i <= n; i++) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dijkstra(i);
    for (int j = 1; j <= n; j++)
      printf("%lld ", dis[j]);
    putchar('\n');
  }
  return 0;
  
}