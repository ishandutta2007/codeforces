#include <iostream>
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

bool is_palin (int x) {
  if (x % 10 == 0) {
    return false;
  }

  int ox = x;
  int y = 0;
  while (x != 0) {
    y *= 10;
    y += x % 10;
    x /= 10;
  }

  return ox == y;
}

vector<int> palins;

const int MAX_N = 4e4 + 5;

Modint dp [MAX_N];

void solve () {
  int m;
  cin >> m;

  cout << dp[m] << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 1; i < MAX_N; i++) {
    if (is_palin(i)) {
      palins.push_back(i);
    }
  }

  dp[0] = 1;
  for (int p : palins) {
    for (int i = 0; i < MAX_N && i + p < MAX_N; i++) {
      dp[i + p] += dp[i];
    }
  }

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}