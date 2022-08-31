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
  if (p.val < 0) p.val += MOD;
  out << p.val;
  return out;
}

typedef vector<Modint> Poly;

Poly operator+ (Poly p, Poly q) {
  Poly ans (max(p.size(), q.size()), Modint(0));
  
  for (int i = 0; i < (int) p.size(); i++) {
    ans[i] += p[i];
  }
  for (int i = 0; i < (int) q.size(); i++) {
    ans[i] += q[i];
  }

  return ans;
}

Poly operator- (Poly p) {
  for (int i = 0; i < (int) p.size(); i++) {
    p[i] = -p[i];
  }
  return p;
}

Poly operator- (Poly p, Poly q) {
  return p + (-q);
}

Poly operator* (Modint k, Poly p) {
  for (int i = 0; i < (int) p.size(); i++) {
    p[i] *= k;
  }
  return p;
}

Modint eval (Poly p, Modint x) {
  Modint ans = 0;
  for (int i = (int) p.size() - 1; i >= 0; i--) {
    ans *= x;
    ans += p[i];
  }
  return ans;
}

Poly dispp [4] =
  {{Modint(1)},
   {Modint(1), Modint(1)},
   {Modint(1), Modint(2), Modint(1)},
   {Modint(1), Modint(3), Modint(3), Modint(1)}};

// P(x + y) as a polynomial of x
Poly displace (Poly p, Modint y) {
  Poly ans (p.size(), Modint(0));
  for (int i = 0; i < (int) p.size(); i++) {
    Modint yp = 1;
    for (int j = i; j >= 0; j--) {
      ans[j] += p[i] * yp * dispp[i][j];
      yp *= y;
    }
  }
  return ans;
}

Poly genPm (Modint m) {
  Poly ans = {Modint(0), m * m + Modint(3) * m + Modint(2), - Modint(2) * m - Modint(3), Modint(1)};
  ans = inv(2) * ans;
  Poly add = {Modint(0), -(inv(4) + inv(12)), inv(4) + inv(4), -inv(6)};
  add = displace(add, -Modint(m));
  ans = ans + add;
  return ans;
}

ll sq (ll x) {
  return x * x;
}

const int MAX_SQ = 1e6 + 5;

int main () {
  ios::sync_with_stdio(false);

  ll m;
  cin >> m;
 
  Poly Pm = genPm(Modint(m));


  int ny = 0;
  Modint ans (0);
  Poly gen (0);
  for (int x = MAX_SQ; x >= 0; x--) {
    while (sq(x) + sq(ny) <= m) {
      if (ny != 0) {
        gen = gen + Modint(2) * displace(Pm, Modint(sq(ny)));
      } else {
        gen = gen + displace(Pm, Modint(sq(ny)));        
      }
      ny++;
    }

    if (x != 0) {
      ans += Modint(2) * eval(gen, Modint(sq(x)));
    } else {
      ans += eval(gen, Modint(sq(x)));
    }
  }

  cout << ans << endl;
}