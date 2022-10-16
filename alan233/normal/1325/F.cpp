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
int n, m, B;

vector<int> num[405];
int dep[N], dad[N];
bool vis[N];
void dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1, num[dep[u] % B].pb(u), dad[u] = fa;
  vis[u] = 1;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    if (!vis[v]) {
      dfs1(v, u);
    } else if (dep[v] < dep[u]) {
      if ((dep[u] - dep[v] + 1) > B) {
        puts("2");
        printf("%d\n", dep[u] - dep[v] + 1);
        while (u != v) printf("%d ", u), u = dad[u];
        printf("%d\n", v);
        exit(0);
      }
    }
  }
}

int main() {
  n = read(), m = read();
  while (B * B <= n) B++;
  B--;
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs1(1, 0);
  int t = 0;
  for (int i = 0; i < B; i++) if (SZ(num[i]) > SZ(num[t])) t = i;
  puts("1");
  num[t].resize(B * B == n ? B : B + 1);
  for (auto u: num[t]) printf("%d ", u);
  puts("");
  return 0;
}