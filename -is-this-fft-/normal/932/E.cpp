#include <iostream>
#include <deque>

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

typedef deque<Modint> Poly;

Poly operator+ (Poly p, Poly q) {
  Poly ans = p;
  for (int i = 0; i < (int) min(p.size(), q.size()); i++) {
    ans[i] += q[i];
  }
  return ans;
}

Poly operator* (Modint k, Poly p) {
  for (int i = 0; i < (int) p.size(); i++) {
    p[i] *= k;
  }
  return p;
}

// formal derivative
Poly ddx (Poly p) {
  if (p.empty()) return p;
  for (int i = 0; i < (int) p.size(); i++) {
    p[i] *= Modint(i);
  }
  p.pop_front();
  return p;
}

// xp(x)
Poly shift (Poly p) {
  p.push_front(Modint(0));
  return p;
}

const int MAX_N = 5e3 + 5;

Modint fact [MAX_N];
Modint ifact [MAX_N];

Modint choose (int n, int k) {
  return fact[n] * ifact[k] * ifact[n - k];
}

int main () {
  ios::sync_with_stdio(false);

  fact[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = fact[i - 1] * Modint(i);
  }

  for (int i = 0; i < MAX_N; i++) {
    ifact[i] = inv(fact[i]);
  }
  
  int n, K;
  cin >> n >> K;

  if (n <= K) {
    Modint ans (0);
    for (int k = 0; k <= n; k++) {
      ans += choose(n, k) * exp(k, K);
    }
    cout << ans << endl;
  } else {
    // polynomial magic
    int pw = n;
    Poly side (1, Modint(1));

    for (int k = 0; k < K; k++) {
      auto Qd = ddx(side);
      side = shift(Modint(pw) * side + shift(Qd) + Qd);
      pw--;
    }

    Modint ans (0);
    for (Modint c : side) {
      ans += c;
    }
    ans *= exp(Modint(2), pw);
    cout << ans << endl;
  }
}