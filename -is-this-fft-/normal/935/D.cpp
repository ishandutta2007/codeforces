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

int a [MAX_N], b [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  
  Modint ans (0);
  Modint curp (1);
  for (int i = 0; i < n; i++) {
    if (a[i] == 0 && b[i] == 0) {
      Modint eq = inv(Modint(m));
      Modint g = (Modint(1) - eq) * inv(2);

      ans += curp * g;
      curp *= eq;
    } else if (a[i] == 0) {
      Modint eq = inv(Modint(m));
      Modint g = Modint(m - b[i]) * inv(Modint(m));
      
      ans += curp * g;
      curp *= eq;      
    } else if (b[i] == 0) {
      Modint eq = inv(Modint(m));
      Modint g = Modint(a[i] - 1) * inv(Modint(m));
      
      ans += curp * g;
      curp *= eq;
    } else if (a[i] > b[i]) {
      ans += curp;
      break;
    } else if (a[i] < b[i]) {
      break;
    } else if (a[i] == b[i]) {
      
    }
  }

  cout << ans << endl;
}