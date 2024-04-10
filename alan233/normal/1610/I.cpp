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

const int N = 300005;

vector<int> adj[N];
int n;

bool vis[N];
int ans, now, edge;

int dep[N], dad[N], SG[N];
void dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1;
  dad[u] = fa;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    SG[u] ^= SG[v] + 1;
  }
}

int main() {
  n = read();
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs1(1, 0);
  ans = SG[1];
  edge = 0;
  vis[1] = 1;
  putchar(ans ? '1' : '2');
//  printf("When i = 1, ans = %d\n", ans);
  rep(k, 2, n) {
    int las = 0, u = k;
    while (!vis[u]) {
      for (auto v: adj[u]) if (v != dad[u] && v != las) ans ^= SG[v] + 1; 
      edge++;
      vis[u] = 1;
      las = u;
      u = dad[u];
    }
    if (las) ans ^= SG[las] + 1;
//     printf("When i = %d, ans = %d, edge = %d\n", k, ans, edge);
    if ((ans ^ (edge & 1 ? 1 : 0))) putchar('1');
    else putchar('2');
  }
  puts("");
  return 0;
}