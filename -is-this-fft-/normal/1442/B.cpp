#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

const int MOD = 998244353; // change if needed

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

const int MAX_N = 2e5 + 5;

int Ap [MAX_N], B [MAX_N];

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;

    Ap[x] = i;
  }

  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;

    B[i] = Ap[x];
  }

  set<int> future;
  for (int i = 1; i <= m; i++) {
    future.insert(B[i]);
  }

  Modint ans (1);
  for (int i = 1; i <= m; i++) {
    int cur = B[i];
    future.erase(cur);

    int mul = 2;
    if (cur - 1 == 0 || future.count(cur - 1)) mul--;
    if (cur == n || future.count(cur + 1)) mul--;
    ans *= Modint(mul);
  }
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}