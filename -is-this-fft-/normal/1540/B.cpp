#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7; 

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

Modint _inv (Modint a) {
  return exp(a, MOD - 2);
}

ostream& operator<< (ostream& out, Modint p) {
  out << p.val;
  return out;
}

const int MAX_N = 405;
const int MAX_LG = 8;

Modint inv [MAX_N];
vector<int> adj [MAX_N];

int lvl [MAX_N];
int par [MAX_N];
int jmp [MAX_N][MAX_LG];

void build (int u, int p) {
  lvl[u] = 1 + lvl[p];
  par[u] = p;

  jmp[u][0] = p;
  for (int k = 1; k < MAX_LG; k++) {
    jmp[u][k] = jmp[jmp[u][k - 1]][k - 1];
  }

  for (int nxt : adj[u]) {
    if (nxt != p) {
      build(nxt, u);
    }
  }
}

int lca (int u, int v) {
  if (lvl[u] < lvl[v]) {
    swap(u, v);
  }

  int diff = lvl[u] - lvl[v];
  for (int k = 0; k < MAX_LG; k++) {
    if (diff & 1 << k) {
      u = jmp[u][k];
    }
  }

  if (u == v) return u;

  for (int k = MAX_LG - 1; k >= 0; k--) {
    if (jmp[u][k] != jmp[v][k]) {
      u = jmp[u][k];
      v = jmp[v][k];
    }
  }

  return par[u];
}

Modint wins [MAX_N][MAX_N];

Modint add (int u, int v, int lc) {
  if (u > v) {
    swap(u, v);
  }

  // calculate probability that v comes before u
  return wins[lvl[v] - lvl[lc]][lvl[u] - lvl[lc]];
}

Modint add (int u, int v) {
  return add(u, v, lca(u, v));
}

Modint solve (int u, int n) {
  build(u, 0);
  
  Modint ans (0);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans += add(i, j);
    }
  }
  return ans;
}

Modint i2p [MAX_N];
Modint fact [MAX_N];
Modint ifact [MAX_N];

Modint choose (int n, int k) {
  return fact[n] * ifact[k] * ifact[n - k];
}

int main () {
  Modint i2 = _inv(Modint(2));
  i2p[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    i2p[i] = i2p[i - 1] * i2;
  }

  fact[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = fact[i - 1] * Modint(i);
  }

  for (int i = 0; i < MAX_N; i++) {
    ifact[i] = _inv(fact[i]);
  }

  for (int i = 1; i < MAX_N; i++) {
    inv[i] = _inv(Modint(i));
  }

  for (int i = 0; i < MAX_N; i++) {
    wins[0][i] = Modint(1);
  }

  for (int a = 1; a < MAX_N; a++) {
    for (int b = 1; a + b < MAX_N; b++) {
      for (int k = a - 1; k <= a - 1 + b - 1; k++) {
        wins[a][b] += i2p[k] * choose(k, a - 1);
      }
      wins[a][b] *= i2;
    }
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  Modint ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += inv[n] * solve(i, n);
  }
  cout << ans << endl;
}