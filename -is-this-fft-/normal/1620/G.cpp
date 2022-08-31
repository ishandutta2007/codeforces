#include <iostream>
#include <string>
#include <array>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

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

const int MAX_N = 23;
const int ALPHA = 26;

typedef array<short, ALPHA> String;

String strings [1 << MAX_N];
Modint arr [1 << MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    for (char c : s) {
      strings[1 << i][c - 'a']++;
    }
  }

  for (int mask = 1; mask < 1 << n; mask++) {
    if (__builtin_popcount(mask) > 1) {
      int lsb = mask & -mask;
      strings[mask] = strings[mask ^ lsb];
      for (int i = 0; i < ALPHA; i++) {
        strings[mask][i] = min(strings[mask][i], strings[lsb][i]);
      }
    }

    arr[mask] = Modint(1);
    for (int i = 0; i < ALPHA; i++) {
      arr[mask] *= Modint(strings[mask][i] + 1);
    }
    
    if (__builtin_popcount(mask) % 2 == 0) {
      arr[mask] = -arr[mask];
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < 1 << n; i++) {
      if (i & 1 << k) {
        arr[i] += arr[i ^ (1 << k)];
      }
    }
  }

  ll hash = 0;
  for (int mask = 0; mask < 1 << n; mask++) {
    ll val = arr[mask].val;
    ll sumset = 0;
    for (int i = 0; i < n; i++) {
      if (mask & 1 << i) {
        sumset += i + 1;
      }
    }
    hash ^= val * sumset * __builtin_popcount(mask);
  }

  cout << hash << '\n';
}