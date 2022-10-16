// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define SZ(x) (int(x.size()))
#define fir first
#define sec second

int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

ull hsh[N], choose[10][10];
vector<pii> adj[N];
int n, m, k;

ull all; int ans;
void dfs(int u, ull sum) {
  if (u == k + 1) {
    if (all == sum) ans++;
    return ;
  }
  for (int i = 1; i <= u; i++) {
    dfs(u + 1, sum + choose[u][i]);
  }  
}

int main() {
  n = read(), m = read(), k = read();
  rep(i, 1, m) {
    int u = read(), v = read(), w = read();
    adj[u].pb({w, v});
  }
  rep(i, 1, n) hsh[i] = rng(), all += hsh[i];
  rep(i, 1, n) {
    sort(adj[i].begin(), adj[i].end());
    rep(j, 0, SZ(adj[i]) - 1) {
      choose[SZ(adj[i])][j + 1] += hsh[adj[i][j].sec];
    }
  }
  dfs(1, 0);
  printf("%d\n", ans);
  return 0;
}