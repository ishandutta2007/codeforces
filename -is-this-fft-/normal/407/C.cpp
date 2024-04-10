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

const int MAX_N = 1e5 + 5;
const int MAX_K = 110; // TEMP

Modint fact [MAX_N];
Modint ifact [MAX_N];

Modint choose (int n, int k) {
  return fact[n] * ifact[k] * ifact[n - k];
}

int arr [MAX_N];
Modint table [MAX_N][MAX_K];

int main () {
  fact[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = fact[i - 1] * Modint(i);
  }

  for (int i = 0; i < MAX_N; i++) {
    ifact[i] = inv(fact[i]);
  }

  ios::sync_with_stdio(false);

  int n, qc;
  cin >> n >> qc;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < qc; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    k--;

    table[l][k + 1] += Modint(1);
    int w = r - l;
    for (int j = k + 1; j >= 0; j--) {
      table[r + 1][j] -= choose(k - j + w + 1, w);
    }
  }

  for (int j = MAX_K - 2; j >= 0; j--) {
    for (int i = 1; i <= n; i++) {
      table[i][j] += table[i - 1][j] + table[i][j + 1];
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << table[i][0] + Modint(arr[i]) << " ";
  }
  cout << '\n';
}