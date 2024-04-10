#include <iostream>

typedef long long ll;

using namespace std;

const int MOD = 1e9 + 7; // change if needed

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

const int MAX_N = 2e5 + 5;

Modint ways [MAX_N][3];
Modint cnt [3];

int main () {
  int n, l, r;
  cin >> n >> l >> r;

  for (int i = 0; i < 3; i++) {
    cnt[i] = Modint(r / 3);
  }
  for (int i = 0; i <= r % 3; i++) {
    cnt[i] += Modint(1);
  }

  for (int i = 0; i < 3; i++) {
    cnt[i] -= Modint((l - 1) / 3);
  }
  for (int i = 0; i <= (l - 1) % 3; i++) {
    cnt[i] -= Modint(1);
  }
  
  ways[0][0] = Modint(1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        ways[i + 1][(j + k) % 3] += ways[i][j] * cnt[k];
      }
    }
  }

  cout << ways[n][0] << endl;
}