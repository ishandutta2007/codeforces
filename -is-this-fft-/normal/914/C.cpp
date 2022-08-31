#include <iostream>

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

Modint inv (Modint a) {
  return exp(a, MOD - 2);
}

ostream& operator<< (ostream& out, Modint p) {
  out << p.val;
  return out;
}

const int MAX_B = 1e3 + 5;

Modint dp [MAX_B][MAX_B][2]; // position, # of ones, has diverged
int steps [MAX_B];

int main () {
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int n = s.size();
  dp[0][1][0] = Modint(1);
  dp[0][0][1] = Modint(1);
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j <= i + 1; j++) {
      for (int k = 0; k < 2; k++) {
        if (s[i + 1] == '0') {
          dp[i + 1][j][k] += dp[i][j][k];
          if (k) {
            dp[i + 1][j + 1][k] += dp[i][j][k];
          }
        } else {
          dp[i + 1][j + 1][k] += dp[i][j][k];
          dp[i + 1][j][1] += dp[i][j][k];
        }
      }
    }
  }

  if (s == string("1")) {
    dp[n - 1][1][0] -= Modint(1);
  } else {
    dp[n - 1][1][1] -= Modint(1);
  }
  
  for (int i = 2; i < MAX_B; i++) {
    steps[i] = 1 + steps[__builtin_popcount(i)];
  }
  
  int K;
  cin >> K;

  if (K == 0) {
    cout << 1 << endl;
    return 0;
  }

  Modint ans (0);
  for (int i = 1; i < MAX_B; i++) {
    if (K == steps[i] + 1) {
      auto add = dp[n - 1][i][0] + dp[n - 1][i][1];
      ans += add;
    }
  }

  cout << ans << endl;
}