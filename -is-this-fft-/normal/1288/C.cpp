#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7; // change if needed

struct Modint {
  ll val;
  
  Modint (ll _val = 0)
    : val(_val % MOD) {}

  Modint operator+ (Modint other) {
    return Modint(val + other.val);
  }

  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }

  Modint operator- () {
    return Modint(MOD - val);
  }

  Modint operator- (Modint other) {
    return Modint(val + MOD - other.val);
  }

  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }

  Modint operator* (Modint other) {
    return Modint(val * other.val);
  }

  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }

  bool operator== (Modint other) {
    return val == other.val;
  }

  bool operator!= (Modint other) {
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

const int MAX_N = 1005;
const int MAX_M = 22;

Modint dp [MAX_M][MAX_N];

int main () {
  int n, m;
  cin >> n >> m;
  m *= 2;

  dp[0][1] = Modint(1);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = Modint(0);
      for (int k = 1; k <= j; k++) {
        dp[i][j] += dp[i - 1][k];
      }
    }
  }
  
  Modint ans (0);
  for (int i = 1; i <= n; i++) {
    ans += dp[m][i];
  }

  cout << ans << endl;
}