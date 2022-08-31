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

const int MAX_K = 70;
const int MAX_N = 1e3 + 5;

Modint dp [MAX_K][MAX_N]; // # of pieces, # of spaces
Modint choose [MAX_N + MAX_K][MAX_N];
Modint fact [MAX_K];

Modint memo [MAX_K][MAX_N];
bool seen [MAX_K][MAX_N];


void solve () {
  int n, K;
  cin >> n >> K;

  if (K >= MAX_K) {
    cout << 0 << '\n';
    return;
  }

  if (seen[K][n]) {
    cout << memo[K][n] << '\n';
    return;
  }

  Modint ans (0);
  for (int i = 0; i <= n; i++) {
    ans += dp[K][i] * choose[n - i + K][K] * fact[K];
  }

  seen[K][n] = true;
  memo[K][n] = ans;
  cout << ans << '\n';
}

int main () {
  dp[0][0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) { // piece size
    for (int k = MAX_K - 2; k >= 0; k--) {
      for (int j = 0; j + i < MAX_N; j++) {
        dp[k + 1][i + j] += dp[k][j];
      }
    }
  }

  choose[0][0] = Modint(1);
  for (int i = 1; i < MAX_N + MAX_K; i++) {
    choose[i][0] = Modint(1);
    for (int j = 1; j < MAX_N; j++) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
  }

  fact[0] = Modint(1);
  for (int i = 1; i < MAX_K; i++) {
    fact[i] = fact[i - 1] * Modint(i);
  }
  
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}