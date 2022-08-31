#include <iostream>
#include <vector>

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

const int MAX_N = 2e5 + 5;

Modint arr [MAX_N];

vector<int> adj [MAX_N];
int color [MAX_N];
int cnt [MAX_N][2];

void paint (int u, int p, int c) {
  color[u] = c;
  cnt[u][c]++;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      paint(nxt, u, !c);
      for (int k = 0; k < 2; k++) {
        cnt[u][k] += cnt[nxt][k];
      }
    }
  }
}

int subc (int u) {
  return cnt[u][0] + cnt[u][1];
}

Modint ans;
void dfs (int u, int p) {
  for (int nxt : adj[u]) {
    if (nxt != p) {
      dfs(nxt, u);
    }
  }

  Modint cur (0);
  for (int nxt : adj[u]) {
    if (nxt != p) {
      // consider the number of vertices outside that subtree
      Modint oth = subc(1) - subc(nxt);
      cur += Modint(cnt[nxt][color[u]]) * oth;
      cur -= Modint(cnt[nxt][!color[u]]) * oth;
    }
  }

  {
    Modint oth = subc(u);
    vector<Modint> cnts = {cnt[1][0] - cnt[u][0], cnt[1][1] - cnt[u][1]};
    cur += cnts[color[u]] * oth;
    cur -= cnts[!color[u]] * oth;
  }

  cur += subc(1);
  ans += cur * arr[u];
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;

    if (x < 0) x += MOD;
    arr[i] = Modint(x);
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
  }

  paint(1, 0, 0);
  dfs(1, 0);

  cout << ans << endl;
}