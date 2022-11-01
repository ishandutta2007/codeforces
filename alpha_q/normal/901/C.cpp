#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 300005;

vector <int> g[N];
vector <int> cyc[N];
bitset <N> vis;
int n, m, q, tot, par[N];
int id[N], cnt[N], sz[N], last[N];

void dfs (int u, int from = 0) {
  vis[u] = 1;
  // cout << u << endl;
  // cout << "------\n";
  for (int v : g[u]) {
    if (v == from) continue;
    if (vis[v]) {
      if (id[v] != -1) continue;
      cyc[++tot].push_back(v);
      id[v] = tot;
      int w = u;
      // cout << "????\n";
      // cout << u << " " << v << endl;
      // if (u != 3 and u != 8) exit(0);
      while (w != v) {
        // cout << w << " " << par[w] << endl;
        assert(id[w] == -1);
        cyc[tot].push_back(w);
        id[w] = tot;
        w = par[w];
      }
      sz[tot] = cyc[tot].size();
      // if (u != 3 and u != 8) exit(0);
      continue;
    }
    par[v] = u;
    dfs(v, u);
  }
}

bool bad (int u) {
  if (id[u] == -1) return 0;
  int at = id[u];
  if (cnt[at] + 1 < sz[at]) {
    ++cnt[at];
    return 0;
  }
  return 1;
}

int nodeSz[N + N];
vector <ll> t[N + N];
vector <ll> sum[N + N];

void init (void) {
  for (int i = 0; i < n; ++i) {
    t[n + i].push_back(last[i + 1]);
  }
  for (int i = n - 1; i; --i) {
    merge(t[i << 1].begin(), t[i << 1].end(), t[i << 1 | 1].begin(), t[i << 1 | 1].end(), back_inserter(t[i]));
  }
  for (int i = 1; i < n + n; ++i) {
    nodeSz[i] = t[i].size();
    sum[i].push_back(t[i][0]);
    for (int j = 1; j < nodeSz[i]; ++j) {
      sum[i].push_back(sum[i][j - 1] + t[i][j]);
    }
  }
}

ll getSum (int u, int l, int r) {
  if (l > r or r >= nodeSz[u]) return 0;
  if (l == 0) return sum[u][r];
  return sum[u][r] - sum[u][l - 1];
}

ll query (int l, int r, ll x) {
  ll ans = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      int pos = upper_bound(t[l].begin(), t[l].end(), x) - t[l].begin();
      ans += getSum(l, 0, pos - 1);
      ans += (nodeSz[l] - pos) * x;
      ++l;
    }
    if (r & 1) {
      --r;
      int pos = upper_bound(t[r].begin(), t[r].end(), x) - t[r].begin();
      ans += getSum(r, 0, pos - 1);
      ans += (nodeSz[r] - pos) * x;
    }
  }
  return ans;
}

ll rangeSum (ll l, ll r) {
  return (r * (r + 1) - l * (l - 1)) / 2;
}

int main() {
  scanf("%d %d", &n, &m);
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(id, -1, sizeof id);
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) dfs(i);
  }
  // for (int i = 1; i <= tot; ++i) {
  //   cout << i << " --> ";
  //   for (int j : cyc[i]) cout << j << " ";
  //   cout << endl;
  // }
  bad(1);
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j < n) {
      if (bad(j + 1)) {
        break;
      }
      ++j;
    }
    last[i] = j;
    if (id[i] != -1) --cnt[id[i]];
    if (j == i) ++j;
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout << i << " --> " << last[i] << endl;
  // }
  init();
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    ll res = query(l - 1, r, r) + r - l + 1 - rangeSum(l, r);
    printf("%lld\n", res);
  }
  return 0;
}