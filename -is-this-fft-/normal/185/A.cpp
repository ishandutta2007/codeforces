#include <iostream>

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

struct Matrix {
  Modint a, b, c, d;
  
  Matrix (Modint _a = 1, Modint _b = 0, Modint _c = 0, Modint _d = 1)
    : a(_a), b(_b), c(_c), d(_d) {
  }
};


Matrix mul (Matrix p, Matrix q) {
  return Matrix(p.a * q.a + p.b * q.c,
                p.a * q.b + p.b * q.d,
                p.c * q.a + p.d * q.c,
                p.c * q.b + p.d * q.d);
}

Matrix exp (Matrix A, ll k) {
  if (k == 0) {
    return Matrix();
  }

  if (k % 2 == 0) {
    auto half = exp(A, k / 2);
    return mul(half, half);
  }

  return mul(exp(A, k - 1), A);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;

  Matrix ans = exp(Matrix(3, 1, 1, 3), n);
  cout << ans.a << endl;
}