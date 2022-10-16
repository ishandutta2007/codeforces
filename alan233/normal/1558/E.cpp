// Author: wlzhouzhuan
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
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 1005;
vector<int> adj[N];
int a[N], b[N], n, m;

bool ok[N], vis[N];
ll cur;

int chk() {
  int cnt = 0;
  for (int i = 1; i <= n; i++) if (ok[i]) cnt++;
  return cnt;
}
bool dfs(int u, int lst) {
  if (vis[u] || ok[u]) return 1;
  if (cur <= a[u]) return 0;
  cur += b[u];
  vis[u] = 1;
  for (auto v: adj[u]) if (v != lst && dfs(v, u)) {
    ok[u] = 1, vis[u] = 0;
    return 1;
  }
  cur -= b[u];
  vis[u] = 0;
  return 0;
} 
bool check(int mid) {
  rep(i, 1, n) ok[i] = 0, vis[i] = 0;
  ok[1] = 1;
  cur = mid;
  while (chk() != n) {
    for (int i = 1; i <= n; i++) {
      if (ok[i]) {
        for (auto j: adj[i]) {
          if (!ok[j] && dfs(j, i))
            goto end;
        }
      } 
    }
    return 0; 
    end: ;
  }
  return 1;
} 

void solve() {
  n = read(), m = read();
  rep(i, 2, n) a[i] = read();
  rep(i, 2, n) b[i] = read();
  rep(i, 1, n) adj[i].clear();
  rep(i, 1, m) {
    int u = read(), v = read();
    adj[u].pb(v), adj[v].pb(u);
  }
  int l = 1, r = 1e9 + 5;
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  print(l, '\n');
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}