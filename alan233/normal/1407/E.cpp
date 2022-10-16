// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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
#define poly vector<int>
#define SZ(x) (int(x.size()))
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

const int N = 500005;

vector<int> adj[N][2];
int n, m;
 
int col[N], dis[N];
void bfs(int s) {
  memset(col, -1, sizeof(col));
  memset(dis, -1, sizeof(dis));
  queue<int> q; q.push(s);
  dis[s] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
//    printf("bfs u = %d, dis = %d\n", u, dis[u]);
    for (auto op: {0, 1}) {
      for (auto v: adj[u][op]) {
        if (!~col[v]) col[v] = op ^ 1;
        else if (col[v] == op && !~dis[v]) {
          dis[v] = dis[u] + 1;
          q.push(v);
        } 
      }
    }
  }
}

int main() {
  n = read(), m = read();
  rep(i, 1, m) {
    int u = read(), v = read(), w = read();
    adj[v][w].pb(u);
  }
  bfs(n);
  printf("%d\n", dis[1]);
  rep(i, 1, n) {
    if (col[i] == -1) col[i] = 0;
    printf("%d", col[i]);
  }
  puts("");
  return 0;
}