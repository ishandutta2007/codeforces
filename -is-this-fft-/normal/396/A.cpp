#include <iostream>
#include <vector>
#include <map>

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

const int MAX_P = 4e4 + 5; // >sqrt(10^9)

int sieve [MAX_P];

map<int, int> cnt_p;
vector<int> smallp;

void factorize (int x) {
  for (int p : smallp) {
    while (x % p == 0) {
      cnt_p[p]++;
      x /= p;
    }
  }

  if (x != 1) {
    cnt_p[x]++;
  }
}

int arr [MAX_P];

Modint fact [MAX_P];
Modint ifact [MAX_P];

Modint choose (int n, int k) {
  return fact[n] * ifact[k] * ifact[n - k];
}

Modint starbar (int n, int k) {
  return choose(n + k - 1, n - 1);
}

int main () {
  for (int i = 2; i < MAX_P; i++) {
    if (!sieve[i]) {
      smallp.push_back(i);
      for (int j = i; j < MAX_P; j += i) {
        sieve[j] = 1;
      }
    }
  }

  fact[0] = Modint(1);
  for (int i = 1; i < MAX_P; i++) {
    fact[i] = fact[i - 1] * Modint(i);
  }

  for (int i = 0; i < MAX_P; i++) {
    ifact[i] = inv(fact[i]);
  }

  ios::sync_with_stdio(false);
  
  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    cin >> arr[i];
    factorize(arr[i]);
  }

  Modint ans (1);
  for (auto it = cnt_p.begin(); it != cnt_p.end(); it++) {
    ans *= starbar(m, it->second);
  }

  cout << ans << endl;
}