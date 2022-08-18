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

const int MAX_N = 1e3 + 5;

void failure () {
  cout << 0 << endl;
  exit(0);
}

int grid [MAX_N][MAX_N];
int rs [MAX_N];
int cs [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int h, w;
  cin >> h >> w;

  for (int i = 0; i < h; i++) {
    cin >> rs[i];
  }

  for (int i = 0; i < w; i++) {
    cin >> cs[i];
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < rs[i]; j++) {
      grid[i][j] = 1;
    }
    grid[i][rs[i]] = -1;
  }

  for (int i = 0; i < w; i++) {
    for (int j = 0; j < cs[i]; j++) {
      if (grid[j][i] == -1) failure();
      grid[j][i] = 1;
    }

    if (grid[cs[i]][i] == 1) failure();
    grid[cs[i]][i] = -1;
  }

  int c0 = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == 0) c0++;
    }
  }

  cout << exp(Modint(2), c0) << endl;
}