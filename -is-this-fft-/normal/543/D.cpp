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

Modint dp [MAX_N];
int czero [MAX_N];
Modint wozero [MAX_N];

Modint updp [MAX_N];
Modint ans [MAX_N];

vector<int> adj [MAX_N];

void calc_dp (int u, int p) {
  dp[u] = Modint(1);
  wozero[u] = Modint(1);
  
  for (int nxt : adj[u]) {
    if (nxt != p) {
      calc_dp(nxt, u);
      if (Modint(1) + dp[nxt] == Modint(0)) {
        czero[u]++;
      } else {
        wozero[u] *= Modint(1) + dp[nxt];
      }
      dp[u] *= Modint(1) + dp[nxt];
    }
  }
}

void calc_updp (int u, int p) {
  for (int nxt : adj[u]) {
    if (nxt != p) {
      if (Modint(1) + dp[nxt] == Modint(0)) {
        if (czero[u] == 1) {
          updp[nxt] = wozero[u] * (Modint(1) + updp[u]);
        } else {
          updp[nxt] = Modint(0);
        }
      } else {
        updp[nxt] = dp[u] * (Modint(1) + updp[u]) * inv(Modint(1) + dp[nxt]);
      }
      
      calc_updp(nxt, u);
    }
  }

  ans[u] = dp[u] * (Modint(1) + updp[u]);
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;

    adj[p].push_back(i);
    adj[i].push_back(p);
  }

  calc_dp(1, 0);
  calc_updp(1, 0);

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}