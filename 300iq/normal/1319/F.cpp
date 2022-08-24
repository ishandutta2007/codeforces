#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf = 1e9;
const int N = 2e5 + 7;
const int K = 20;

int st[N][K];
vector <int> g[N];
int tin[N], tout[N];

int tt = 0;

int dep[N];

void dfs(int v, int pr) {
  tin[v] = tt++;
  st[v][0] = pr;
  for (int i= 1; i < K; i++) {
    st[v][i] = st[st[v][i - 1]][i - 1];
  }
  for (int to : g[v]) {
    if (to != pr) {
      dep[to] = dep[v] + 1;
      dfs(to, v);
    }
  }
  tout[v] = tt++;
}

bool park(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
  if (park(a, b)) return a;
  for (int i = K - 1; i >= 0; i--) {
    if (!park(st[a][i], b)) {
      a = st[a][i];
    }
  }
  return st[a][0];
}

int main() {
#ifdef iq
	freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector <int> ind(n, -1);
  dfs(0, 0);
  int q;
  cin >> q;
  while (q--) {
    int k, m;
    cin >> k >> m;
    vector <int> v(k), s(k);
    vector <int> verts;
    for (int i = 0; i < k; i++) {
      cin >> v[i] >> s[i];
      v[i]--;
      verts.push_back(v[i]);
    }
    vector <int> u(m);
    for (int i = 0; i < m; i++) {
      cin >> u[i];
      u[i]--;
      verts.push_back(u[i]);
    }
    auto f = [] (vector <int> &verts) {
      sort(verts.begin(), verts.end());
      verts.resize(unique(verts.begin(), verts.end()) - verts.begin());
    };
    f(verts);
    vector <vector <pair <int, int> > > gr;
    auto add_edge = [&] (int a, int b, int c) {
      gr[a].push_back({b, c});
      gr[b].push_back({a, c});
    };
    auto build = [&] (vector <int> v) {
      sort(v.begin(), v.end(), [&] (int x, int y) {
        return tin[x] < tin[y];
      });
      vector <int> nv = v;
      for (int i = 1; i < (int) v.size(); i++) {
        nv.push_back(lca(v[i - 1], v[i]));
      }
      f(nv);
      sort(nv.begin(), nv.end(), [&] (int x, int y) {
        return tin[x] < tin[y];
      });
      gr.resize(nv.size());
      vector <int> st;
      for (int i = 0; i < (int) nv.size(); i++) {
        ind[nv[i]] = i;
        if (i == 0) {
          st.push_back(i);
        } else {
          while (!st.empty() && !park(nv[st.back()], nv[i])) {
            st.pop_back();
          }
          assert(!st.empty());
          add_edge(st.back(), i, dep[nv[i]] - dep[nv[st.back()]]);
          st.push_back(i);
        }
      }
    };
    build(verts);
    vector <int> col(gr.size(), -1);
    for (int i = 0; i < k; i++) {
      col[ind[v[i]]] = i;
    }
    set <pair <ll, pair <int, pair <int, int> > > > q;
    ll cur_time = 0;
    function<void(int,int,int)> spread = [&] (int v, int len, int id) {
      col[v] = id;
      for (auto c : gr[v]) {
        if (col[c.first] == -1) {
          if (len + c.second <= s[id]) {
            spread(c.first, len + c.second, id);
          } else {
            int free_gap = s[id] - len;
            int left = c.second - free_gap;
            ll when = cur_time + ((left - 1) / s[id] + 1) * (ll) k;
            int rem = left % s[id];
            if (rem == 0) rem = s[id];
            q.insert({when, {c.first, {id, rem}}});
          }
        }
      }
    };
    for (int i = 0; i < k; i++) {
      cur_time = i;
      spread(ind[v[i]], 0, i);
    }
    while (!q.empty()) {
      int v = q.begin()->second.first;
      int id = q.begin()->second.second.first;
      int ok = q.begin()->second.second.second;
      cur_time = q.begin()->first;
      q.erase(q.begin());
      if (col[v] == -1) {
        spread(v, ok, id);
      }
    }
    for (int i = 0; i < m; i++) {
      cout << col[ind[u[i]]] + 1 << ' ';
    }
    cout << '\n';
  }
}