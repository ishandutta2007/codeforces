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

const int INF = 1e9 + 5;
const int MAX_N = 405;

bool conn [MAX_N][MAX_N];
int dist [MAX_N][MAX_N];
vector<int> adj [MAX_N];

int cat [MAX_N];
int height [MAX_N];

bool bycat (int p, int q) {
  if (cat[p] != cat[q]) {
    return cat[p] < cat[q];
  }
  return p < q;
}

Modint solve (int x, int y, int n) {
  int D = dist[x][y];
  vector<int> roots;
  for (int i = 1; i <= n; i++) {
    cat[i] = dist[x][i] - dist[y][i];
    height[i] = dist[x][i] + dist[y][i] - D;
    if (height[i] % 2 != 0) {
      return Modint(0);
    }
    height[i] /= 2;
    if (height[i] < 0) {
      return Modint(0);
    }
    if (height[i] == 0) {
      roots.push_back(i);
    }
  }

  if (roots.empty()) {
    return Modint(0);
  }
  
  sort(roots.begin(), roots.end(), bycat);
  if (cat[roots.front()] != -D) {
    return Modint(0);
  }
  if (cat[roots.back()] != D) {
    return Modint(0);
  }

  int K = roots.size();
  for (int i = 0; i < K - 1; i++) {
    if (cat[roots[i + 1]] - cat[roots[i]] != 2) {
      return Modint(0);
    }

    if (!conn[roots[i + 1]][roots[i]]) {
      return Modint(0);
    }
  }

  Modint ans (1);
  for (int i = 1; i <= n; i++) {
    if (height[i] == 0) {
      continue;
    }

    int cnt = 0;
    for (auto nxt : adj[i]) {
      if (cat[nxt] == cat[i] && height[nxt] == height[i] - 1) {
        cnt++;
      }
    }
    ans *= Modint(cnt);
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = INF;
    }
  }

  for (int i = 1; i <= n; i++) {
    dist[i][i] = 0;
  }
  
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);

    conn[u][v] = 1;
    conn[v][u] = 1;

    dist[u][v] = 1;
    dist[v][u] = 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << solve(i, j, n) << " ";
    }
    cout << '\n';
  }
}