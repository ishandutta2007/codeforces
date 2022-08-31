#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7; // change if needed

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

const int MAX_N = 2e5 + 10;
const int YS = 1e5 + 5;

vector<int> adj [MAX_N];
int vis [MAX_N];

void dfs (int u, int p, int &sz, int &cyc) {
  vis[u] = 1;
  sz++;

  for (int nxt : adj[u]) {
    if (nxt != p) {
      if (vis[nxt]) cyc = 1;
      else dfs(nxt, u, sz, cyc);
    }
  }
}

Modint tpow [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  tpow[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    tpow[i] = Modint(2) * tpow[i - 1];
  }
  
  int n;
  cin >> n;

  map<int, int> xs, ys;
  int curx = 0, cury = YS;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    if (xs.count(x) == 0) {
      xs[x] = curx;
      curx++;
    }

    if (ys.count(y) == 0) {
      ys[y] = cury;
      cury++;
    }

    int u = xs[x];
    int v = ys[y];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  Modint ans (1);
  for (int i = 0; i < curx; i++) {
    if (!vis[i]) {
      int sz = 0, cyc = 0;
      dfs(i, -1, sz, cyc);

      // cerr << i << " " << sz << " " << cyc << endl;

      ans *= tpow[sz] - Modint(1 - cyc);
    }
  }

  for (int i = YS; i < cury; i++) {
    if (!vis[i]) {
      int sz = 0, cyc = 0;
      dfs(i, -1, sz, cyc);

      // cerr << i << " " << sz << " " << cyc << endl;

      ans *= tpow[sz] - Modint(1 - cyc);
    }
  }

  cout << ans << endl;
}