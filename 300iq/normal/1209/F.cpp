#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 2e6 + 7;
const int M = (int) (1e9) + 7;

vector <pair <int, int> > g[N];
int d[N];
int par[N];
int par_id[N];

int ans[N];


const int K = 22;

int st[N][K];

map <int, int> trie[N];
int vert[N];
int ch[N];
int dep[N];

int sz = 1;

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back({b, i});
    g[b].push_back({a, i});
  }
  for (int i = 0; i < n; i++) {
    d[i] = 1e9;
    par[i] = -1;
  }
  d[0] = 0;
  vector <int> ord;
  set <pair <int, int> > q;
  q.insert({0, 0});
  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());
    ord.push_back(v);
    for (auto c : g[v]) {
      int to = c.first;
      int len = to_string(c.second).size();
      if (d[to] > d[v] + len) {
        q.erase({d[to], to});
        d[to] = d[v] + len;
        q.insert({d[to], to});;
      }
    }
  }
  auto cmp = [&] (int u, int v) {
    /*
    if (dep[u] >= dep[v]) {
      int len = (dep[u] - dep[v]);
      for (int i = 0; i < K; i++) 
        if ((len >> i) & 1) {
          u = st[u][i];
        }
    } else {
      int len = (dep[v] - dep[u]);
      for (int i = 0; i < K; i++)
        if ((len >> i) & 1) {
          v = st[v][i];
        }
    }
    */
    for (int i = K - 1; i >= 0; i--) {
      if (st[u][i] != st[v][i]) {
        u = st[u][i], v = st[v][i];
      }
    }
    return ch[u] < ch[v];
  };
  auto add = [&] (int v, int par, string s) {
    int x = v;
    v = vert[par];
    int len = (int) s.size();
    for (int i = 0; i < len; i++) {
      if (!trie[v].count(s[i])) {
        trie[v][s[i]] = sz++;
        st[trie[v][s[i]]][0] = v;
        v = trie[v][s[i]];
        ch[v] = s[i];
        for (int i = 1; i < K; i++) {
          st[v][i] = st[st[v][i - 1]][i - 1];
        }
      } else {
        v = trie[v][s[i]];
      }
    }
    vert[x] = v;
  };
  for (int v : ord) {
    par[v] = -1;
    for (auto c : g[v]) {
      int to = c.first;
      if (d[to] == d[v] - (int) to_string(c.second).size()) {
        int was = vert[v];
        add(v, to, to_string(c.second));
        if (par[v] == -1 || cmp(vert[v], was)) {
          par[v] = to;
          par_id[v] = c.second;
        } else {
          vert[v] = was;
        }
      }
    }
    if (par[v] != -1) {
      int len = to_string(par_id[v]).size();
      int x= 1;
      for (int i = 0; i < len; i++) {
        x = (x * (ll) 10) % M;
      }
      ans[v] = (ans[par[v]] * (ll) x + par_id[v]) % M;
    }
  }
  for (int i = 1; i < n; i++) {
    cout << ans[i] << '\n';
  }
}