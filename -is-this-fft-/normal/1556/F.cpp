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

const int MAX_N = 14;

int str [MAX_N];
Modint prob [MAX_N][MAX_N];

// prob that sub dominates mask
Modint dprob (int mask, int sub) {
  Modint ans (1);
  int oth = mask ^ sub;
  for (int i = 0; i < MAX_N; i++) {
    if (!(sub & 1 << i)) continue;
    for (int j = 0; j < MAX_N; j++) {
      if (!(oth & 1 << j)) continue;
      ans *= prob[i][j];
    }
  }
  return ans;
}

Modint dp [1 << MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      prob[i][j] = Modint(str[i]) * inv(Modint(str[i] + str[j]));
    }
  }

  int all = (1 << n) - 1;
  for (int mask = 1; mask < 1 << n; mask++) {
    dp[mask] = Modint(1);
    for (int sub = (mask - 1) & mask; sub > 0; sub = (sub - 1) & mask) {
      dp[mask] -= dprob(mask, sub) * dp[sub];
    }
  }

  Modint ans (0);
  for (int mask = 1; mask < 1 << n; mask++) {
    Modint cprob = dprob(all, mask) * dp[mask];
    ans += Modint(__builtin_popcount(mask)) * cprob;
  }
  cout << ans << endl;
}