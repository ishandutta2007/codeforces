#include <iostream>
#include <vector>

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

void solve () {
  int n, S;
  cin >> n >> S;

  vector<int> a (n), b (n);
  vector<int> ap (n), bp (n, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;

    ap[a[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] != -1) {
      b[i]--;
      bp[b[i]] = i;
    }
  }

  swap(a, ap);
  swap(b, bp);

  vector<int> add (n, 0);
  for (int i = 0; i < n; i++) {
    if (bp[i] == -1) {
      add[max(ap[i] - S, 0)]++;
    }
  }

  Modint ans = 1;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur += add[i];
    if (b[i] == -1) {
      ans *= cur;
      cur--;
    } else {
      if (ap[b[i]] > i + S) {
        ans *= 0;
      }
    }
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}