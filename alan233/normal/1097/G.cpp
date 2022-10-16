// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("popcnt")
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
ll read() {
  ll x = 0, f = 0; char ch = getchar();
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
const int mod = 1e9 + 7;

inline void add(int &x, int y) {
  x += y; if (x >= mod) x -= mod; 
}
inline void sub(int &x, int y) {
  x -= y; if (x < 0) x += mod;
}

vector<int> adj[N];
int n, K;

int S[205][205];

int f[N][205], sz[N], tmp[N], ans[N];
void dfs(int u, int fa) {
//  printf("dfs %d %d\n", u, fa);
  sz[u] = 1, f[u][0] = 2;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs(v, u);
    memset(tmp, 0, 4 * (K + 1));
    for (int j = 0; j <= K && j <= sz[u]; j++) {
      for (int k = 0; j + k <= K && k <= sz[v]; k++) {
        add(tmp[j + k], 1ll * f[u][j] * f[v][k] % mod);
      }
    }
    memcpy(f[u], tmp, 4 * (K + 1));
    for (int j = 0; j <= K; j++) {
      sub(ans[j], f[v][j]);
    }
    sz[u] += sz[v];
  }
  for (int i = 0; i <= K; i++) add(ans[i], f[u][i]);
  for (int i = K; i >= 1; i--) add(f[u][i], f[u][i - 1]);
  sub(f[u][1], 1);
}

int main() {
  n = read(), K = read();
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(1, 0);
  S[0][0] = 1;
//  cerr << "!\n";
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= i; j++)
      S[i][j] = (S[i - 1][j - 1] + 1ll * j * S[i - 1][j]) % mod;
  }
  int ANS = 0, factor = 1;
  for (int i = 1; i <= K; i++) {
    factor = 1ll * factor * i % mod;
    add(ANS, 1ll * factor * S[K][i] % mod * ans[i] % mod);
  } 
  print(ANS, '\n');
  return 0;
}