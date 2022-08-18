#include <iostream>

using namespace std;

typedef long long ll;

int MOD = 1;

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

const int MAX_N = 405;

Modint choose [MAX_N][MAX_N];
Modint conc [MAX_N]; // # of concave permutations length n
Modint dp [MAX_N][MAX_N][2]; // length, # picked, last picked

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n >> MOD;

  choose[0][0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    choose[i][0] = Modint(1);
    for (int j = 1; j < MAX_N; j++) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
  }

  for (int i = 1; i < MAX_N; i++) {
    for (int j = 0; j < i; j++) {
      int l = j;
      int r = i - j - 1;
      conc[i] += choose[l + r][l];
    }
  }

  dp[0][0][0] = Modint(1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j][0] = dp[i - 1][j][1];

      for (int k = 1; k <= j; k++) {
        dp[i][j][1] += dp[i - k][j - k][0] * choose[j][k] * conc[k];
      }
    }
  }

  Modint ans (0);
  for (int j = 0; j <= n; j++) {
    ans += dp[n][j][1];
  }

  cout << ans << endl;
}