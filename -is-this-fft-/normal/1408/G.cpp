#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 998244353; // change if needed

struct Modint {
  ll val;
  
  Modint (ll _val = 0)
    : val(_val % MOD) {}

  Modint operator+ (Modint other) const {
    return Modint(val + other.val);
  }

  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }

  Modint operator- () const {
    return Modint(MOD - val);
  }

  Modint operator- (Modint other) const {
    return Modint(val + MOD - other.val);
  }

  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }

  Modint operator* (Modint other) const {
    return Modint(val * other.val);
  }

  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }

  bool operator== (Modint other) const {
    return val == other.val;
  }

  bool operator!= (Modint other) const {
    return val != other.val;
  }
};

Modint exp (Modint a, int k) {
  if (k == 0) {
    return Modint(1);
  } else if (k % 2 == 0) {
    Modint half = exp(a, k / 2);
    return half * half;
  } else {
    return a * exp(a, k - 1);
  }
}

Modint inv (Modint a) {
  return exp(a, MOD - 2);
}

ostream& operator<< (ostream& out, Modint p) {
  out << p.val;
  return out;
}

const int MAX_N = 3e3 + 5;

int pairc (int x) {
  return (x * (x - 1)) / 2;
}

vector<Modint> conv (const vector<Modint> &a, const vector<Modint> &b) {
  vector<Modint> ans ((int) a.size() + (int) b.size() - 1, Modint(0));
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < (int) b.size(); j++) {
      ans[i + j] += a[i] * b[j];
    }
  }
  return ans;
}

namespace Tree {
  vector<int> adj [MAX_N];

  void add_edge (int u, int v) {
    adj[u].push_back(v);
  }

  vector<Modint> dp [MAX_N];
  void dfs (int u) {
    dp[u] = {Modint(1), Modint(0)};
    for (int nxt : adj[u]) {
      dfs(nxt);
      dp[u] = conv(dp[u], dp[nxt]);
    }
    dp[u][0] = Modint(0);
    dp[u][1] += Modint(1);
  }
}

namespace DSU {
  int root [MAX_N];
  int sz [MAX_N];
  int eds [MAX_N];
  vector<int> clusters [MAX_N];

  int cluster_id;
  void make_cluster (int u) {
    cluster_id++;
    for (int x : clusters[u]) {
      Tree::add_edge(cluster_id, x);
    }
    clusters[u].clear();
    clusters[u].push_back(cluster_id);
  }
  
  int find (int u) {
    if (root[u] != u) {
      root[u] = find(root[u]);
    }
    return root[u];
  }

  void merge (int u, int v) {
    u = find(u);
    v = find(v);

    if (u != v) {
      if (sz[u] < sz[v]) {
        swap(u, v);
      }

      eds[u] += eds[v];
      sz[u] += sz[v];
      root[v] = u;
      for (int x : clusters[v]) {
        clusters[u].push_back(x);
      }
    }

    eds[u]++;
    if (eds[u] == pairc(sz[u])) {
      make_cluster(u);
    }
  }
}

int cost [MAX_N][MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> cost[i][j];
    }
  }

  vector<pair<int, pair<int, int>>> edges;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      edges.push_back(make_pair(cost[i][j], make_pair(i, j)));
    }
  }

  sort(edges.begin(), edges.end());

  for (int i = 1; i <= n; i++) {
    DSU::root[i] = i;
    DSU::sz[i] = 1;
    DSU::make_cluster(i);
  }

  for (auto e : edges) {
    int u = e.second.first;
    int v = e.second.second;

    DSU::merge(u, v);
  }

  int root = DSU::clusters[DSU::find(1)][0];
  Tree::dfs(root);

  for (int i = 1; i <= n; i++) {
    cout << Tree::dp[root][i] << " ";
  }
  cout << endl;
}