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

const int MAX_P = 4e4 + 5;

bool sieve [MAX_P];
vector<int> smallp;

void precalc_sieve () {
  for (int i = 2; i < MAX_P; i++) {
    if (!sieve[i]) {
      smallp.push_back(i);
      for (int k = i; k < MAX_P; k += i) {
        sieve[k] = 1;
      }
    }
  }
}

struct Factor {
  int prime, cnt = 0, prod = 1;

  Factor () {}

  Factor (int _prime) : prime(_prime) {}
};

vector<Factor> factorize (int x) {
  vector<Factor> ans;
  for (int p : smallp) {
    if (x % p == 0) {
      ans.push_back(Factor(p));
      while (x % p == 0) {
        ans.back().cnt++;
        ans.back().prod *= p;

        x /= p;
      }
    }
  }

  if (x != 1) {
    ans.push_back(Factor(x));
    ans.back().cnt = 1;
    ans.back().prod = x;
  }

  return ans;
}

struct Prog {
  ll init, diff, n;

  ll end () {
    return init + diff * (n - 1);
  }
};

ll pmod (ll a, ll b) {
  ll x = a % b;
  if (x < 0) x += b;
  return x;
}

void solve () {
  Prog b, c;
  
  cin >> b.init >> b.diff >> b.n;
  cin >> c.init >> c.diff >> c.n;

  if (c.diff % b.diff != 0) {
    cout << 0 << '\n';
    return;
  }

  if (pmod(b.init, b.diff) != pmod(c.init, b.diff)) {
    cout << 0 << '\n';
    return;
  }

  if (c.init < b.init) {
    cout << 0 << '\n';
    return;
  }

  if (c.end() > b.end()) {
    cout << 0 << '\n';
    return;
  }

  if (c.init - c.diff < b.init) {
    cout << -1 << '\n';
    return;
  }
  
  if (c.end() + c.diff > b.end()) {
    cout << -1 << '\n';
    return;
  }

  Modint ans = 1;
  auto nf = factorize(c.diff);
  for (auto f : nf) {
    if (b.diff % f.prod != 0) {
      // skip, no choice
    } else {
      auto p = Modint(f.prime);
      auto pp = Modint(f.prod);

      ans *= (pp * pp * p * p - 1) * inv(p * p - 1);
    }
  }

  cout << ans << '\n';
}

int main () {
  precalc_sieve();
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}