#include <iostream>
#include <vector>
#include <tuple>

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

void fwht_and (vector<Modint> &a, bool invert) {
  int n = a.size();
  for (int step = 1; step < n; step *= 2) {
    for (int i = 0; i < n; i += 2 * step) {
      for (int j = i; j < i + step; j++) {
        auto &u = a[j];
        auto &v = a[j + step];
        tie(u, v) = invert ? make_pair(v - u, u) : make_pair(v, u + v);
      }
    }
  }
}

void fwht_xor (vector<Modint> &a, bool invert) {
  int n = a.size();
  for (int step = 1; step < n; step *= 2) {
    for (int i = 0; i < n; i += 2 * step) {
      for (int j = i; j < i + step; j++) {
        auto &u = a[j];
        auto &v = a[j + step];
        tie(u, v) = make_pair(u + v, u - v);
      }
    }
  }

  if (invert) {
    auto in = inv(Modint(n));
    for (int i = 0; i < n; i++) {
      a[i] *= in;
    }
  }
}

const int MAX_N = 1e6 + 5;
const int MAX_A = 1 << 17;

Modint fib [MAX_A];

int main () {
  fib[1] = Modint(1);
  for (int i = 2; i < MAX_A; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  
  vector<Modint> cnt (MAX_A, Modint(0));
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    cnt[x] += Modint(1);
  }

  vector<Modint> mab (MAX_A, Modint(0));
  for (int i = 0; i < MAX_A; i++) {
    for (int j = i; true; j = (j - 1) & i) {
      mab[i] += cnt[j] * cnt[i - j];
      if (j == 0) {
        break;
      }
    }
    mab[i] *= fib[i];
  }

  vector<Modint> mde (MAX_A);
  fwht_xor(cnt, false);
  for (int i = 0; i < MAX_A; i++) {
    mde[i] = cnt[i] * cnt[i];
  }
  fwht_xor(cnt, true);
  fwht_xor(mde, true);
  for (int i = 0; i < MAX_A; i++) {
    mde[i] *= fib[i];
  }

  vector<Modint> mc = cnt;
  for (int i = 0; i < MAX_A; i++) {
    mc[i] *= fib[i];
  }

  fwht_and(mab, false);
  fwht_and(mc, false);
  fwht_and(mde, false);
  vector<Modint> ans (MAX_A);
  for (int i = 0; i < MAX_A; i++) {
    ans[i] = mab[i] * mc[i] * mde[i];
  }
  fwht_and(ans, true);

  Modint anss (0);
  for (int i = 0; i < MAX_A; i++) {
    if (__builtin_popcount(i) == 1) {
      anss += ans[i];
    }
  }

  cout << anss << endl;
}