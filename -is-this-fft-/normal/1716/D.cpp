#include <iostream>

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

const int MAX_N = 2e5 + 5;

Modint dp [2][MAX_N];
Modint ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, K;
  cin >> n >> K;

  int mn = 0, cur = 0;
  dp[cur][0] = 1;
  for (int i = K; mn + i <= n; i++) {
    int nxt = !cur;
    for (int j = mn; j + i <= n; j++) {
      dp[nxt][j + i] = dp[cur][j] + dp[nxt][j];
    }

    mn += i;
    for (int j = mn; j <= n; j++) {
      ans[j] += dp[nxt][j];
      dp[cur][j] = 0;
    }
    
    cur = !cur;
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}