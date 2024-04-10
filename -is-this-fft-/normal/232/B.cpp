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

Modint exp (Modint a, ll k) {
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

const int MAX_N = 105;
const int MAX_K = 1e4 + 5;

Modint choose [MAX_N][MAX_N];
Modint dp [MAX_N][MAX_K];
Modint muls [2][MAX_N];

int main () {
  choose[0][0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    choose[i][0] = Modint(1);
    for (int j = 1; j < MAX_N; j++) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
  }
  
  int n, K;
  ll m;
  cin >> n >> m >> K;

  ll apps = m / n;
  for (int i = 0; i < 2; i++) {
    for (int k = 0; k <= n; k++) {
      muls[i][k] = exp(choose[n][k], apps + i);
    }
  }
  
  dp[0][0] = Modint(1);
  for (int i = 0; i < n; i++) {
    int small = i < m % n;
    
    for (int j = 0; j <= K; j++) {
      for (int k = 0; k <= n && j + k <= K; k++) {
        dp[i + 1][j + k] += dp[i][j] * muls[small][k];
      }
    }
  }

  cout << dp[n][K] << endl;
}