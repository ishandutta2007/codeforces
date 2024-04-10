#include <iostream>
#include <map>
#include <vector>

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

const int MAX_N = 1e5 + 5;

Modint fact [MAX_N];
Modint ifact [MAX_N];

Modint choose (int n, int k) {
  if (k < 0 || n < k) {
    return Modint(0);
  }

  return fact[n] * ifact[k] * ifact[n - k];
}

bool is_lucky (int x) {
  while (x != 0) {
    int dig = x % 10;
    if (dig != 4 && dig != 7) {
      return false;
    }
    x /= 10;
  }
  return true;
}

const int MAX_L = 2e3 + 5;

Modint dp [MAX_L][MAX_L];

int main () {
  fact[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = Modint(i) * fact[i - 1];
  }

  for (int i = 0; i < MAX_N; i++) {
    ifact[i] = inv(fact[i]);
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, K;
  cin >> n >> K;
  
  int coth = 0;
  map<int, int> luckys;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (is_lucky(x)) {
      luckys[x]++;
    } else {
      coth++;
    }
  }

  vector<pair<int, int>> lucky_vec;
  for (auto pr : luckys) {
    lucky_vec.push_back(pr);
  }

  dp[0][0] = Modint(1);
  int lc = lucky_vec.size();
  for (int i = 0; i < lc; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j + 1] += Modint(lucky_vec[i].second) * dp[i][j];
    }
  }
  
  Modint ans (0);
  for (int i = 0; i <= lc; i++) {
    ans += dp[lc][i] * choose(coth, K - i);
  }
  cout << ans << endl;
}