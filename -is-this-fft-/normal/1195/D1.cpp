#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

struct Modint {
  ll val;
  
  Modint (ll _val = 0)
    : val(_val % MOD) {}

  Modint operator+ (Modint other) {
    return Modint(val + other.val);
  }

  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }

  Modint operator- () {
    return Modint(MOD - val);
  }

  Modint operator- (Modint other) {
    return Modint(val + MOD - other.val);
  }

  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }

  Modint operator* (Modint other) {
    return Modint(val * other.val);
  }

  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }

  bool operator== (Modint other) {
    return val == other.val;
  }

  bool operator!= (Modint other) {
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

string arr [MAX_N];
Modint pot [25];
int cntl [15];

int main () {
  pot[0] = Modint(1);
  for (int i = 1; i < 25; i++) {
    pot[i] = pot[i - 1] * Modint(10);
  }
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    cntl[arr[i].size()]++;
    reverse(arr[i].begin(), arr[i].end());
  }

  Modint ans (0);

  // current as left argument
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int) arr[i].size(); j++) {
      for (int k = 0; k <= 10; k++) {
        if (j < k) {
          ans += Modint(cntl[k]) * pot[2 * j + 1] * Modint(arr[i][j] - '0');
        } else {
          ans += Modint(cntl[k]) * pot[2 * k + j - k] * Modint(arr[i][j] - '0');
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int) arr[i].size(); j++) {
      for (int k = 0; k <= 10; k++) {
        if (j < k) {
          ans += Modint(cntl[k]) * pot[2 * j] * Modint(arr[i][j] - '0');
        } else {
          ans += Modint(cntl[k]) * pot[2 * k + j - k] * Modint(arr[i][j] - '0');
        }
      }
    }
  }

  cout << ans << endl;
}