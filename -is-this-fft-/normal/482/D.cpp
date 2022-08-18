#include <iostream>
#include <vector>
#include <algorithm>

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

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
Modint dp [MAX_N][2];

void dfs (int u) {
  for (int nxt : adj[u]) {
    dfs(nxt);
  }

  for (int k = 0; k < 2; k++) {
    vector<Modint> cnt = {Modint(0), Modint(1)};
    for (int nxt : adj[u]) {
      vector<Modint> add = {cnt[0] * dp[nxt][0] + cnt[1] * dp[nxt][1],
                            cnt[1] * dp[nxt][0] + cnt[0] * dp[nxt][1]};
      cnt[0] += add[0];
      cnt[1] += add[1];
    }

    dp[u][0] += cnt[0];
    dp[u][1] += cnt[1];
   
    reverse(adj[u].begin(), adj[u].end());
  }

  // both-ways
  {
    Modint allz = Modint(1);
    vector<Modint> allo = {Modint(0), Modint(1)};

    for (int nxt : adj[u]) {
      allz += allz * dp[nxt][0];
      vector<Modint> add = {allo[1] * dp[nxt][1], allo[0] * dp[nxt][1]};
      allo[0] += add[0];
      allo[1] += add[1];
    }

    dp[u][1] -= allz;
    dp[u][0] -= allo[0];
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;

    adj[p].push_back(i);
  }

  dfs(1);

  cout << dp[1][0] + dp[1][1] << endl;
}