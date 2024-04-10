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

const int N = 600005;

struct Edge {
  int to, nxt, id;
} edge[N << 1];
int head[N], tot;
int deg[N];
void add(int u, int v, int id) {
  edge[++tot] = {v, head[u], id};
  head[u] = tot;
  deg[u]++;
}

struct Info { int u, v, id; };
vector<Info> one, two;
int n, m, mm;

vector<int> tmp, pa[N];
bool visE[N], vis[N];
int ans[N], S;
void dfs1(int u) { // type = 2
  for (int &i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to, id = edge[i].id;
    if ((id && visE[abs(id)]) || (!id && vis[u + v])) continue;
    if (id) visE[abs(id)] = 1;
    if (!id) vis[u + v] = 1;
    ans[abs(id)] = 1 + (id < 0);
    dfs1(v);
    tmp.pb(abs(id));
    if (!u) {
      pa[++mm] = tmp, tmp.clear();
      one.pb({v, S, mm});
    } else if (!v) {
      S = u;
    }
  }
}
void dfs2(int u) { // type = 1
  for (int &i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to, id = edge[i].id;
    if ((id && visE[abs(id)]) || (!id && vis[u + v])) continue;
    if (id) visE[abs(id)] = 1;
    if (!id) vis[u + v] = 1;
    ans[abs(id)] = 1 + (id < 0);
    dfs2(v);
  }
}

int main() {
  n = read(), m = read(), mm = m;
  rep(i, 1, m) {
    int u = read(), v = read(), type = read();
    if (type == 1) one.pb({u, v, i}), deg[u] ^= 1, deg[v] ^= 1;
    else two.pb({u, v, i});
  }
  
  int ANS = 0;
  rep(i, 1, n) if (deg[i] & 1) ANS++;
  memset(deg, 0, sizeof(deg));

  // type = 2
  for (auto [u, v, id]: two) {
    add(u, v, id);
    add(v, u, -id);
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] & 1) {
      add(0, i, 0);
      add(i, 0, 0);
    }
  }
  for (int i = 0; i <= n; i++) {
    dfs1(i);
  }
/*
  printf("mm = %d\n", mm);
  for (int i = m + 1; i <= mm; i++) {
    for (auto it: pa[i])
      printf("%d ", it);
    puts("");
  }
*/
  // type = 1
  tot = 0;
  memset(visE, 0, sizeof(visE));
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i <= n; i++) {
    assert(!head[i]);
    head[i] = 0;
  }
  for (auto [u, v, id]: one) {
    add(u, v, id);
    add(v, u, -id);
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] & 1) {
      add(0, i, 0);
      add(i, 0, 0);
    }
  }
  for (int i = 0; i <= n; i++) {
    dfs2(i);
  }
  for (int i = m + 1; i <= mm; i++) {
    if (ans[i] == 2) {
      for (auto it: pa[i])
        ans[it] = 3 - ans[it];
    }
  }
  printf("%d\n", ANS);
  for (int i = 1; i <= m; i++) putchar('0' + ans[i]);
  return 0;
}

/*
5 5
4 2 2
1 5 1
5 1 2
3 2 1
5 2 2
*/

/*
5 5
4 2 1
3 1 2
3 5 1
2 1 1
4 5 2
*/