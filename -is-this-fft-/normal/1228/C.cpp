#include <iostream>
#include <vector>

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

const int MAX_P = 4e4 + 5;

int sieve [MAX_P];
vector<int> primes;

vector<int> factor (int x) {
  vector<int> ans;
  for (int p : primes) {
    if (x % p == 0) {
      ans.push_back(p);
      while (x % p == 0) {
        x /= p;
      }
    }
  }

  if (x != 1) ans.push_back(x);

  return ans;
}

ll count (ll p, ll n) {
  return n / p;
}

int blog (ll x) {
  return 63 - __builtin_clzll(x);
}

int main () {
  ios::sync_with_stdio(false);

  for (int i = 2; i < MAX_P; i++) {
    if (!sieve[i]) {
      primes.push_back(i);
      for (int j = i; j < MAX_P; j += i) {
        sieve[j] = 1;
      }
    }
  }

  int x;
  ll n;
  cin >> x >> n;

  Modint ans (1);
  vector<int> factors = factor(x);
  for (int p : factors) {
    ll cur = p;
    while (cur <= n) {
      ans *= exp(Modint(p), count((ll) cur, n));

      if (blog(cur) + blog(p) > 60) break;
      cur *= p;
    }
  }

  cout << ans << endl;
}