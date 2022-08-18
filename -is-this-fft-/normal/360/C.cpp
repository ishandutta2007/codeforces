#include <iostream>

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

const int MAX_N = 2e3 + 5;

Modint _dp [MAX_N][MAX_N];

Modint &dp (int i, int a, int k) {
  return _dp[i - a][k];
}

Modint &dp (int i, int k) {
  return _dp[i][k];
}

int arr [MAX_N];

int cnt_l (int a) {
  return a;
}

int cnt_g (int a) {
  return 26 - a - 1;
}

Modint cum [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, K;
  cin >> n >> K;

  string s;
  cin >> s;

  for (int i = 1; i <= n; i++) {
    arr[i] = s[i - 1] - 'a';
  }

  /*
  dp(0, 0) = Modint(1);
  for (int i = 0; i < n; i++) {
    for (int k = 0; k <= K; k++) {
      for (int a = 1; k + a * (n - i) <= K && a - 1 <= i; k++) {
        dp(i + 1, k + a * (n - i)) += Modint(cnt_g(arr[i + 1])) * dp(i, a - 1, k);
      }

      cum[k] += dp(i, k);
      dp(i + 1, k) += Modint(cnt_l(arr[i + 1])) * cum[k];
    }
  }
  */  

  dp(0, 0, 0) = Modint(1);
  for (int i = 0; i < n; i++) {
    for (int k = 0; k <= K; k++) {
      for (int a = 0; k + (a + 1) * (n - i) <= K && a <= i; a++) {
        dp(i + 1, 0, k + (a + 1) * (n - i)) += Modint(cnt_g(arr[i + 1])) * dp(i, a, k);
      }

      cum[k] += dp(i, k);
      dp(i + 1, 0, k) += Modint(cnt_l(arr[i + 1])) * cum[k];
      /*
      for (int a = 0; a <= i; a++) {
        dp(i + 1, 0, k) += Modint(cnt_l(arr[i + 1])) * dp(i, a, k);
      }
      */
    }
  }

  Modint ans (0);
  for (int a = 0; a <= n; a++) {
    ans += dp(n, a, K);
  }
  cout << ans << endl;
}