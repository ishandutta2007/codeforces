#include <iostream>

using namespace std;

typedef long long ll;

int MOD = 1; // change if needed

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

const int MAX_N = 505;

int arr [MAX_N];
Modint dp [2][MAX_N][MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m, B;
  cin >> n >> m >> B >> MOD;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= B; k++) {
        dp[(i + 1) % 2][j][k] = 0;
      }
    }
    
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= B; k++) {
        dp[(i + 1) % 2][j][k] += dp[i % 2][j][k];
        if (k + arr[i] <= B) {
          dp[i % 2][j + 1][k + arr[i]] += dp[i % 2][j][k];
        }
      }
    }
  }

  Modint ans (0);
  for (int k = 0; k <= B; k++) {
    ans += dp[n % 2][m][k];
  }

  cout << ans << endl;
}