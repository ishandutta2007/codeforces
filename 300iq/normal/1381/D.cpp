#include <cmath>
#include <functional>
#include <fstream>
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

const int N = 1e5 + 7;
const int K = 20;

vector <int> g[N];
int tin[N], tout[N];
int st[N][K];
int park[N];
int dep[N];

int tt = 0;

void dfs(int v, int pr) {
  tin[v] = tt++;
  st[v][0] = pr;
  for (int i= 1; i < K; i++) {
    st[v][i] = st[st[v][i - 1]][i - 1];
  }
  for (int to : g[v]) {
    if (to != pr) {
      park[to] = v;
      dep[to] = dep[v] + 1;
      dfs(to, v);
    }
  }
  tout[v] = tt++;
}

bool anc(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
  if (anc(a, b)) return a;
  for (int i = K - 1; i >= 0; i--) {
    if (!anc(st[a][i], b)) a = st[a][i];
  }
  return st[a][0];
}

int f(int a, int b) {
  return  dep[a] + dep[b] - 2 * dep[lca(a, b)];
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(0, 0);
    set <pair <int, int> > q;
    bool good = false;
    function<void(int,int)> naive = [&] (int a, int b) {
      if (good) return;
      if (q.count({a, b}) ) return;
      if (q.count({b, a}) || clock() / (double) CLOCKS_PER_SEC >= 0.9) {
        good = true;
        return;
      }
      q.insert({a, b});
      int na = -1, nb = -1;
      for (int x : g[a]) {
        if (f(a, x) + f(x, b) == f(a, b)) {
          na = x;
          break;
        }
      }
      for (int x : g[b]) {
        if (f(b, x) + f(x, a) == f(a, b)) {
          nb = x;
          break;
        }
      }
      for (int x : g[a]) {
        if (x == na) continue;
        naive(x, nb);
      }
      for (int x : g[b]) {
        if (x == nb) continue;
        naive(na, x);
      }
    };
    naive(a, b);
    if (good) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}