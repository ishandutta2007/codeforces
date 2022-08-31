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

const int MAX_N = 1e3 + 5;

Modint dpl [MAX_N][MAX_N]; // dpl[i][j] is the # of things with power i exiting j to the left
Modint dpr [MAX_N][MAX_N]; // dpr[i][j] is the # of things with power i exiting j to the right

void solve () {
  int n, K;
  cin >> n >> K;

  for (int i = 0; i <= K + 2; i++) {
    for (int j = 0; j <= n + 2; j++) {
      dpl[i][j] = Modint(0);
      dpr[i][j] = Modint(0);
    }
  }

  dpr[K][0] = Modint(1);
  for (int i = K; i >= 1; i--) {
    for (int j = 0; j < n; j++) {
      if (j > 0) {
        dpr[i][j] += dpr[i][j - 1];
      }

      if (j < n - 1) {
        dpr[i][j] += dpl[i + 1][j + 1];
      }
    }

    for (int j = n - 1; j >= 0; j--) {
      if (j < n - 1) {
        dpl[i][j] += dpl[i][j + 1];
      }

      if (j > 0) {
        dpl[i][j] += dpr[i + 1][j - 1];
      }
    }
  }
  
  Modint ans (0);
  for (int i = 1; i <= K; i++) {
    ans += dpr[i][n - 1];
    ans += dpl[i][0];
  }

  if (K > 1) {
    ans += Modint(1);
  }
  
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}