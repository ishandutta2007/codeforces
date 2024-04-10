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

const int MAX_N = 1e5 + 5;

int color [MAX_N];
vector<int> adj [MAX_N];
Modint dp [MAX_N][2];

void calc_dp (int u) {
  dp[u][0] = Modint(1);
  dp[u][1] = Modint(0);

  for (int nxt : adj[u]) {
    calc_dp(nxt);

    dp[u][1] *= dp[nxt][0];
    dp[u][1] += dp[u][0] * dp[nxt][1];
    dp[u][0] *= dp[nxt][0];
  }

  if (color[u]) {
    dp[u][1] = dp[u][0];
    //  dp[u][0] = Modint(1);
  } else {
    dp[u][0] += dp[u][1];
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;

    adj[p].push_back(i);
  }

  for (int i = 0; i < n; i++) {
    cin >> color[i];
  }

  calc_dp(0);

  /*
  for (int i = 0; i < n; i++) {
    cerr << " " << dp[i][0] << " " << dp[i][1] << endl;
  }
  */
  
  cout << dp[0][1] << endl;
}