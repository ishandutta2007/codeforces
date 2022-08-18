#include <iostream>
#include <vector>
#include <queue>
#include <set>

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

template<typename T>
using ipq = priority_queue<T, vector<T>, greater<T>>;

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

const int INF = 1e9 + 200;
const int MAX_N = 2e5 + 500 + 5;
const int MAX_LG = 20;

int mintr [MAX_N];
vector<int> adj [MAX_N][2];

void build_mintr (int u, vector<int> &nxt_layer) {
  int K = mintr[u];
  for (int nxt : adj[u][K % 2]) {
    if (mintr[nxt] == INF) {
      mintr[nxt] = K;
      build_mintr(nxt, nxt_layer);
    }
  }

  for (int nxt : adj[u][!(K % 2)]) {
    if (mintr[nxt] == INF) {
      mintr[nxt] = K + 1;
      nxt_layer.push_back(nxt);
    }
  }
}

int _dp [MAX_N][MAX_LG];
int &dp (int u, int K) {
  return _dp[u][K - mintr[u]];
}

void bfs (int K, const vector<int> &layer) {
  ipq<pair<int, int>> PQ;
  for (int u : layer) {
    if (dp(u, K) != INF) {
      PQ.push(make_pair(dp(u, K), u));
    }
  }

  set<int> seen;
  while (!PQ.empty()) {
    auto pr = PQ.top();
    PQ.pop();

    int dist = pr.first;
    int cur = pr.second;
    if (seen.count(cur)) {
      continue;
    }
    seen.insert(cur);

    for (int nxt : adj[cur][K % 2]) {
      if ((K - mintr[nxt] < MAX_LG) && (dp(nxt, K) > dist + 1)) {
        dp(nxt, K) = dist + 1;
        PQ.push(make_pair(dp(nxt, K), nxt));
      }
    }
  }
  
  for (int u : layer) {
    if (K + 1 - mintr[u] < MAX_LG) {
      dp(u, K + 1) = dp(u, K);
    }
  }
}

vector<int> enters [MAX_N];

int main () {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    mintr[i] = INF;
  }
  mintr[1] = 0;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u][0].push_back(v);
    adj[v][1].push_back(u);
  }

  vector<int> layer (1, 1);
  while (!layer.empty()) {
    vector<int> nxt_layer;
    for (int u : layer) {
      build_mintr(u, nxt_layer);
    }
    layer = nxt_layer;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < MAX_LG; j++) {
      _dp[i][j] = INF;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (mintr[i] != INF) {
      enters[mintr[i]].push_back(i);
    }
  }
  
  dp(1, 0) = 0;
  vector<int> cur_layer;
  for (int K = 0; K < mintr[n] + MAX_LG; K++) {
    vector<int> new_layer;
    for (int u : cur_layer) {
      if (K < mintr[u] + MAX_LG) {
        new_layer.push_back(u);
      }
    }
    cur_layer = new_layer;
    for (int u : enters[K]) {
      cur_layer.push_back(u);
    }

    bfs(K, cur_layer);
  }
  
  if (mintr[n] > 30) {
    cout << Modint(dp(n, mintr[n])) + exp(Modint(2), mintr[n]) - Modint(1) << endl;
  } else {
    ll ans = 1e18 + 500;
    for (int i = 0; i < MAX_LG; i++) {
      ans = min(ans, ((1LL << (mintr[n] + i)) - 1) + dp(n, mintr[n] + i));
    }
    cout << Modint(ans) << endl;
  }
}