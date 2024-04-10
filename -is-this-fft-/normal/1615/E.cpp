#include <iostream>
#include <vector>

using namespace std;

class Segtree {
  int n;
  vector<pair<int, int>> tree;
  vector<int> lfend;
  vector<int> rgend;
  vector<int> lazy;

  void propagate (int u) {
    if (u < n) {
      lazy[2 * u] += lazy[u];
      lazy[2 * u + 1] += lazy[u];
    }

    tree[u].first += lazy[u];
    lazy[u] = 0;
  }
  
public:
  Segtree (int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<pair<int, int>> (2 * n);
    lfend = vector<int> (2 * n);
    rgend = vector<int> (2 * n);
    lazy = vector<int> (2 * n, 0);

    for (int i = n; i < 2 * n; i++) {
      lfend[i] = i - n;
      rgend[i] = i - n;
      tree[i] = make_pair(0, i - n);
    }

    for (int i = n - 1; i > 0; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
      tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
  }

  pair<int, int> query (int ql, int qr, int u = 1) {
    propagate(u);

    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return make_pair(0, 0);
    if (ql == lfend[u] && qr == rgend[u]) return tree[u];
    return max(query(ql, qr, 2 * u),
               query(ql, qr, 2 * u + 1));
  }

  void update (int ql, int qr, int val, int u = 1) {
    propagate(u);

    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return;
    if (ql == lfend[u] && qr == rgend[u]) {
      lazy[u] += val;
      propagate(u);
      return;
    }

    update(ql, qr, val, 2 * u);
    update(ql, qr, val, 2 * u + 1);
    tree[u] = max(tree[2 * u], tree[2 * u + 1]);
  }
};

typedef long long ll;

const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];
int sta [MAX_N], fin [MAX_N], ista [MAX_N];
int par [MAX_N];

void dfs (int u, int p, int &cur) {
  cur++;
  sta[u] = cur;
  ista[sta[u]] = u;
  par[u] = p;
  for (int nxt : adj[u]) {
    if (nxt == p) continue;
    dfs(nxt, u, cur);
  }
  
  fin[u] = cur;
}

const ll INF = 1e18 + 1000;

bool vis [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, K;
  cin >> n >> K;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int cur = 0;
  dfs(1, 0, cur);

  Segtree tree (n + 1);
  for (int i = 1; i <= n; i++) {
    tree.update(sta[i], fin[i], 1);
  }

  vis[0] = true;
  ll avail = n, ans = -INF;
  for (int i = 0; i < K; i++) {
    auto mn = tree.query(sta[1], fin[1]);
    int u = ista[mn.second];
    avail -= mn.first;

    for (int v = u; !vis[v]; v = par[v]) {
      tree.update(sta[v], fin[v], -1);
      vis[v] = true;
    }

    ll blue = min(avail, (ll) n / 2);
    ll red = i + 1;
    ll x = red * (n - red) - blue * (n - blue);
    ans = max(ans, red * (n - red) - blue * (n - blue));
    // cerr << " " << avail << " " << x << endl;
  }

  cout << ans << '\n';
}