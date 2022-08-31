#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 2e6 + 7;

vector <int> g[N], rg[N];

void add_edge(int a, int b) {
  g[a].push_back(b);
  rg[b].push_back(a);
}

bool u[N];

vector <int> t;

void dfs(int v) {
  u[v] = true;
  for (int to : g[v]) {
    if (!u[to]) {
      dfs(to);
    }
  }
  t.push_back(v);
}

bool vis[N];
int comp[N];
vector <int> orz[N];

int sz = 0;

void rdfs(int v) {
  vis[v] = true;
  comp[v] = sz;
  orz[sz].push_back(v);
  for (int to : rg[v]) {
    if (!vis[to]) {
      rdfs(to);
    }
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      g[i].clear();
      rg[i].clear();
      u[i] = 0;
      vis[i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      add_edge(a, b);
    }
    t.clear();
    for (int i = 0; i < n; i++) {
      if (!u[i]) {
        dfs(i);
      }
    }
    reverse(t.begin(), t.end());
    sz = 0;
    for (int v : t) {
      if (!vis[v]) {
        orz[sz].clear();
        rdfs(v);
        sz++;
      }
    }
    bool good = false;
    for (int i = 0; i < n; i++) {
      if (comp[i] != comp[0]) {
        good = true;
      }
    }
    if (!good) {
      cout << "No\n";
    } else {
      vector <bool> good(sz, true);
      for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
          if (comp[i] != comp[j]) {
            good[comp[i]] = false;
          }
        }
      }
      for (int i = 0; i < sz; i++) {
        if (good[i]) {
          cout << "Yes\n";
          cout << (int) orz[i].size() << ' ' << n - (int) orz[i].size() << '\n';
          vector <bool> dead(n);
          for (int x : orz[i]) {
            cout << x + 1 << ' ';
            dead[x] = true;
          }
          cout << '\n';
          for (int i = 0; i < n; i++) {
            if (!dead[i]) {
              cout << i + 1 << ' ';
            }
          }
          cout << '\n';
          break;
        }
      }
    }
  }
}