// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
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
char readc() {
  char ch = getchar();
  while (ch != 'W' && ch != 'B') ch = getchar();
  return ch == 'B';
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 1005;
const int inf = 1e9;

int a[N][N], n, m;

struct Edge {
  int to, nxt, flow;
} edge[5000005];
int head[N], h[N], etot = 1;
void add(int u, int v, int flow) {
  edge[++etot] = {v, head[u], flow};
  head[u] = etot;
}
void adde(int u, int v, int flow) {
  add(u, v, flow), add(v, u, 0);
} 

int S, T;

int dep[N];
queue <int> q;
bool bfs(int S, int T) {
  for (int i = 0; i <= T; i++) dep[i] = 1e9, h[i] = head[i];
  q.push(S), dep[S] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = head[u]; i; i = edge[i].nxt) {
      int v = edge[i].to, fl = edge[i].flow;
      if (dep[v] > dep[u] + 1 && fl) {
        dep[v] = dep[u] + 1;
        q.push(v);
      }
    }
  }
  return dep[T] != dep[0];
}
int dfs(int u, int T, int val) {
  if (u == T) return val;
  int over = 0;
  for (int &i = h[u]; i; i = edge[i].nxt) {
    int v = edge[i].to, fl = edge[i].flow;
    if (dep[v] == dep[u] + 1 && fl) {
      int res = dfs(v, T, min(fl, val));
      edge[i].flow -= res, edge[i ^ 1].flow += res;
      val -= res, over += res;
      if (!res) dep[v] = 1e9;
      if (!val) break;
    }
  }
  if (over == 0) dep[u] = 0;
  return over;
}
long long MF;
void Dinic(int S, int T) {
  while (bfs(S, T)) MF += dfs(S, T, inf);
}

int main() {
  n = read(), m = read();
  rep(i, 1, n) {
    rep(j, 1, m) {
      int t = readc();
      a[i - 1][j - 1] ^= t;
      a[i - 1][j] ^= t;
      a[i][j - 1] ^= t;
      a[i][j] ^= t;
    }
  }
  S = n + m + 1, T = n + m + 2;
  int one = 0;
  rep(i, 1, n) {
    rep(j, 1, m) {
      if (a[i][j]) one++;
    }
  }
  rep(i, 1, n - 1) {
    rep(j, 1, m - 1) {
      if (a[i][j] && a[i][m] && a[n][j]) {
        adde(i, n - 1 + j, 1);
      }
    }
  }
  rep(i, 1, n - 1) adde(S, i, 1);
  rep(i, 1, m - 1) adde(n - 1 + i, T, 1);
  Dinic(S, T);
  D("max = %d\n", MF);
  D("one = %d\n", one);
  int ans = inf;
  rep(k, 0, MF) {
    ckmin(ans, 2 * k + (a[n][m] ^ (k & 1)) + one - a[n][m] - 3 * k);
    D("k = %d, qwq = %d\n", k, 2 * k + (a[n][m] ^ (k & 1)) + one - a[n][m] - 3 * k);
  }
  print(ans, '\n');
  return 0;
}