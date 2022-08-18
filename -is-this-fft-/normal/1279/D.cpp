#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

struct Modint {
  ll val;
  
  Modint (ll _val = 0)
    : val(_val % MOD) {}

  Modint operator+ (Modint other) {
    return Modint(val + other.val);
  }

  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }

  Modint operator- () {
    return Modint(MOD - val);
  }

  Modint operator- (Modint other) {
    return Modint(val + MOD - other.val);
  }

  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }

  Modint operator* (Modint other) {
    return Modint(val * other.val);
  }

  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }

  bool operator== (Modint other) {
    return val == other.val;
  }

  bool operator!= (Modint other) {
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

const int MAX_N = 1E6 + 5;

int wishc [MAX_N]; // kids
vector<int> adj [MAX_N]; // gifts;

int main () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> wishc[i];
    for (int j = 0; j < wishc[i]; j++) {
      int k;
      cin >> k;

      adj[k].push_back(i);
    }
  }

  Modint ans (0);
  Modint invn = inv(Modint(n));
  for (int i = 1; i <= MAX_N; i++) {
    for (int k : adj[i]) {
      ans += invn * inv(Modint(wishc[k])) * Modint((int) adj[i].size()) * invn;
    }
  }
  cout << ans << endl;
}