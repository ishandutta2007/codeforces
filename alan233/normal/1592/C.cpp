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

const int N = 100005;
vector<int> adj[N];
int a[N], qwq[N], dep[N], n, k;

bool ban[N];
void dfs1(int u, int fa) {
  qwq[u] = a[u];
  dep[u] = dep[fa] + 1;
  for (auto v: adj[u]) {
    if (v == fa || ban[v]) continue;
    dfs1(v, u);
    qwq[u] ^= qwq[v];
  } 
}
int flag;
void dfs2(int u, int fa) {
  if (qwq[u] == 0) {
    flag = u;
    return ;
  }
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs2(v, u);
  }
}
void dfs3(int u, int fa, int aim) {
  if (qwq[u] == aim) {
    if (!flag || dep[flag] < dep[u]) {
      flag = u;
    }
  }
  for (auto v: adj[u]) {
    if (v == fa || ban[v]) continue;
    dfs3(v, u, aim);
  }
}

void solve() {
  n = read(), k = read();
  rep(i, 1, n) ban[i] = false, adj[i].clear();
  int all = 0;
  rep(i, 1, n) a[i] = read(), all ^= a[i];
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  dfs1(1, 0);
  if (all == 0) {
    flag = 0;
    dfs2(1, 0);
    if (flag) {
      puts("YES");
    } else {
      puts("NO");
    }
  } else {
    if (k < 3) {
      puts("NO");
      return ;
    }
    flag = 0;
    dfs3(1, 0, all);
    if (!flag || flag == 1) {
      puts("NO"); return ;
    }
    ban[flag] = true, dfs1(1, 0);
    flag = 0;
    dfs3(1, 0, all);
    if (flag) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}