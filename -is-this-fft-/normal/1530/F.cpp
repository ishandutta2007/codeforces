#include <iostream>

using namespace std;

const int MOD = 31607;

#ifdef DEBUG
typedef double Modint;

Modint inv (Modint a) {
  return 1.0 / a;
}
#else
struct Modint {
  int val;
  
  Modint (int _val = 0)
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
#endif

const int MAX_N = 21;

int n;
Modint grid [MAX_N][MAX_N];

// probability of being row-dead if we consider
// only the columns in mask
Modint rdead [1 << MAX_N];
Modint cdead [1 << MAX_N];
Modint rowp [MAX_N];
Modint p_alive [1 << MAX_N][MAX_N];

Modint calc_dead_prob () {
  for (int mask = 0; mask < 1 << n; mask++) {
    int lsb = mask & -mask;
    int bit = 31 - __builtin_clz(lsb);

    rdead[mask] = Modint(1);
    for (int i = 0; i < n; i++) {
      if (mask == 0) {
        p_alive[mask][i] = Modint(1);
      } else {
        p_alive[mask][i] = p_alive[mask - (1 << bit)][i] * grid[i][bit];
      }
      rdead[mask] *= Modint(1) - p_alive[mask][i];
    }
  }
  
  for (int j = 0; j < n; j++) {
    rowp[j] = Modint(1);
    for (int i = 0; i < n; i++) {
      rowp[j] *= grid[i][j];
    }
  }
  
  int flip = (1 << n) - 1;
  for (int mask = 0; mask < 1 << n; mask++) { // subset of cols
    cdead[mask] = rdead[flip ^ mask];
    for (int j = 0; j < n; j++) {
      if (mask & 1 << j) {
        cdead[mask] *= rowp[j];
      }
    }
  }

  // inverse sum over supsets
  for (int j = n - 1; j >= 0; j--) {
    int E = 1 << j;
    for (int mask = flip; mask >= 0; mask--) {
      if (!(mask & E)) {
        cdead[mask] -= cdead[mask | E];
      }
    }
  }

  return cdead[0];
}

Modint given;
Modint ogrid [MAX_N][MAX_N];

void mark_diag () {
  for (int i = 0; i < n; i++) {
    given *= grid[i][i];
    grid[i][i] = Modint(1);
  }
}

void mark_adiag () {
  for (int i = 0; i < n; i++) {
    given *= grid[i][n - i - 1];
    grid[i][n - i - 1] = Modint(1);
  }
}

void unmark_diag () {
  for (int i = 0; i < n; i++) {
    given *= grid[i][i];
    grid[i][i] = ogrid[i][i];
    given *= inv(grid[i][i]);
  }
}

int main () {
  ios::sync_with_stdio(false);

  Modint i1e4 = inv(Modint(10000));
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;

      grid[i][j] = Modint(x) * i1e4;
      ogrid[i][j] = grid[i][j];
    }
  }

  Modint ans = calc_dead_prob();
  given = Modint(1);
  
  mark_diag();
  ans -= given * calc_dead_prob();
  unmark_diag();

  mark_adiag();
  ans -= given * calc_dead_prob();

  mark_diag();
  ans += given * calc_dead_prob();

  cout << Modint(1) - ans << endl;
}