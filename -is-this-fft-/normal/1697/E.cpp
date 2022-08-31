#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 998244353; 

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

struct Graph {
  int n;
  vector<vector<int>> adj;

  void top_dfs (int pos, vector<int> &result,
                vector<bool> &explr, vector<vector<int>> &revadj) {
    if (explr[pos]) return;
    explr[pos] = true;
    for (auto next : revadj[pos]) {
      top_dfs(next, result, explr, revadj);
    }
    result.push_back(pos);
  }
  
public:
  Graph (int _n) : n(_n), adj(_n, vector<int> (0)) {}

  void add_edge (int u, int v) {
    adj[u].push_back(v);
  }

  vector<int> topsort () {
    vector<vector<int>> revadj (n);
    for (int u = 0; u < n; u++) {
      for (auto v : adj[u]) {
        revadj[v].push_back(u);
      }
    }

    vector<int> result;
    vector<bool> explr (n, false);
    for (int i = 0; i < n; i++) {
      top_dfs(i, result, explr, revadj);
    }
    reverse(result.begin(), result.end());
    return result;
  }
  
  vector<vector<int>> scc () {
    vector<int> order = topsort();
    reverse(order.begin(), order.end());
    vector<bool> explr (n, false);
    vector<vector<int>> res;
    for (auto it = order.rbegin(); it != order.rend();
         ++it) {
      vector<int> comp;
      top_dfs(*it, comp, explr, adj);
      sort(comp.begin(), comp.end());
      res.push_back(comp);
    }
    sort(res.begin(), res.end());
    return res;
  }
};

typedef pair<int, int> Point;
#define x first
#define y second

int d (Point p, Point q) {
  return abs(p.x - q.x) + abs(p.y - q.y);
}

const int INF = 1e9 + 5;
const int MAX_N = 105;

Point pos [MAX_N];
int dist [MAX_N][MAX_N];

bool conn [MAX_N][MAX_N];

Modint dp [MAX_N][MAX_N];

Modint fact [MAX_N];
Modint ifact [MAX_N];

int main () {
  fact[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = fact[i - 1] * i;
  }

  for (int i = 0; i < MAX_N; i++) {
    ifact[i] = inv(fact[i]);
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> pos[i].x >> pos[i].y;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = d(pos[i], pos[j]);
    }
  }

  Graph G (n);
  for (int i = 0; i < n; i++) {
    int mn = INF;
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;

      mn = min(mn, dist[i][j]);
    }

    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;

      if (dist[i][j] == mn) {
        conn[i][j] = 1;
        G.add_edge(i, j);
      }
    }
  }

  vector<int> pcs;
  auto sccs = G.scc();
  for (const auto &comp : sccs) {
    if (comp.empty()) {
      continue;
    }
    
    bool ok = true;
    vector<int> is_in (n, 0);
    for (int u : comp) {
      is_in[u] = true;
    }
    
    for (int u : comp) {
      for (int v = 0; v < n; v++) {
        if (is_in[v]) {
          if (u != v && !conn[u][v]) {
            ok = false;
          }
        } else {
          if (conn[u][v]) {
            ok = false;
          }
        }
      }
    }

    if (ok) {
      pcs.push_back(comp.size());
    } else {
      for (int u : comp)
        pcs.push_back(1);
    }
  }

  dp[0][0] = 1;
  for (int i = 0; i < (int) pcs.size(); i++) {
    int sz = pcs[i];
    for (int j = 0; j < n; j++) {
      if (j + 1 < MAX_N)
        dp[i + 1][j + 1] += dp[i][j] * (n - j);

      if (sz != 1 && j + sz <= n)
        dp[i + 1][j + sz] += dp[i][j] * fact[n - j] * ifact[n - j - sz];
    }
  }

  Modint ans (0);
  int m = pcs.size();
  for (int j = 0; j <= n; j++) {
    ans += dp[m][j];
  }

  cout << ans << endl;
}