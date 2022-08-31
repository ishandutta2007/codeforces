#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 3000;

vector <int> g[N];

ll dp[N][N];

vector <int> di[N];
int par[N];
int len[N][N];
int sz[N];

void dfs(int v, int pr) {
  par[v] = pr;
  sz[v] = 1;
  for (int to : g[v]) {
    if (to != pr) {
      di[v].push_back(to);
      dfs(to, v);
      sz[v] += sz[to];
    }
  }
}

void calc_len(int u, int v, int pr, int l) {
  len[u][v] = l;
  for (int to : g[v]) {
    if (to != pr) {
      calc_len(u, to, v, l + 1);
    }
  }
}

bool in(int a, int b, int c) {
  return len[a][b] + len[b][c] == len[a][c];
}

int n;

ll cost(int a, int b) {
  ll l = 1, r = 1;
  for (int x : di[a]) {
    if (!in(a, x, b)) {
      l += sz[x];
    }
  }
  if (par[a] != -1 && !in(a, par[a], b)) {
    l += n - sz[a];
  }
  for (int x : di[b]) {
    if (!in(a, x, b)) {
      r += sz[x];
    }
  }
  if (par[b] != -1 && !in(a, par[b],b)) {
    r += n - sz[b];
  }
  return l * r;
}

ll f(int u, int v) {
  if (dp[u][v]) return dp[u][v];
  for (int to : g[u]) {
    if (to == v) {
      if (par[u] == v) {
        return sz[u] * (n - sz[u]);
      } else {
        return sz[v] * (n - sz[v]);
      }
    }
  }
  ll ans = 0;
  for (int to : g[u]) {
    if (in(u, to, v)) {
      ans = max(ans, f(to, v));
    }
  }
  for (int to : g[v]) {
    if (in(u, to, v)) {
      ans = max(ans, f(u, to));
    }
  }
  return dp[u][v] = cost(u, v) + ans;
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    calc_len(i, i, -1, 0);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans = max(ans, f(i, j));
    }
  }
  cout << ans << '\n';
}