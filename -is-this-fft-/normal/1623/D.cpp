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

void solve () {
  int n, m;
  cin >> n >> m; // i had >> m >> n here for 30 min, fml
  int x, y, tx, ty;
  cin >> x >> y >> tx >> ty;
  x--; y--; tx--; ty--;
  int _p;
  cin >> _p;

  Modint p = Modint(_p) * inv(Modint(100));

  int ox = x, oy = y;
  int len = 0;
  Modint prob (1), e (0);
  int dx = 1, dy = 1;

  if (x + dx >= n) dx *= -1;
  if (x + dx < 0) dx *= -1;
  if (y + dy >= m) dy *= -1;
  if (y + dy < 0) dy *= -1;

  int odx = dx;
  int ody = dy;

  while (true) {
    if (x == tx || y == ty) {
      e += p * prob * Modint(len);
      prob *= Modint(1) - p;
    }

    x += dx;
    y += dy;
    len++;

    if (x + dx >= n) dx *= -1;
    if (x + dx < 0) dx *= -1;
    if (y + dy >= m) dy *= -1;
    if (y + dy < 0) dy *= -1;
    
    if (ox == x && oy == y && dx == odx && dy == ody) break;
  }
  //cerr << len << endl;

  Modint ans = (prob * len + e) * inv(Modint(1) - prob);
  cout << ans << endl;
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