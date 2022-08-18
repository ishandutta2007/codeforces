#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;

const ll MOD = 3006703054056749LL;

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

const Modint BASE (31);
const int MAX_N = 5e3 + 5;

bool can [MAX_N][MAX_N];
int dp [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, a, b;
  cin >> n >> a >> b;

  string s;
  cin >> s;

  Modint sub (1);
  for (int k = 1; k <= n; k++) {
    unordered_map<ll, short> fst;
    sub *= BASE;
    Modint hsh (0);
    for (int i = 0; i < k; i++) {
      hsh *= BASE;
      hsh += Modint(s[i] - 'a');
    }
    fst[hsh.val] = k;
    
    for (int i = k; i < n; i++) {
      hsh *= BASE;
      hsh += Modint(s[i] - 'a');
      hsh -= sub * Modint(s[i - k] - 'a');

      if (fst.count(hsh.val) == 0) {
        fst[hsh.val] = i + 1;
      } else if (fst[hsh.val] < i - k + 2) {
        can[i - k + 2][i + 1] = 1;
      }
    }
  }

  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = a + dp[i - 1];
    for (int j = 2; j <= i; j++) {
      int l = j;
      int r = i;
      if (can[l][r]) {
        dp[i] = min(dp[i], b + dp[l - 1]);
      }
    }
  }
  cout << dp[n] << endl;
}