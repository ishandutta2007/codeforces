#include <iostream>
#include <set>

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

const int MAX_N = 2e3 + 5;

Modint dp [MAX_N][MAX_N];
int arr [MAX_N];

int main () {
  dp[0][0] = Modint(1);
  for (int k = 1; k < MAX_N; k++) {
    for (int a = 0; a <= k; a++) {
      int b = k - a;

      if (a == 0) {
        dp[a][b] = Modint(b) * dp[0][b - 1];
      } else {
        dp[a][b] = Modint(0);
        if (a >= 2) {
          dp[a][b] += Modint(a - 1) * dp[a - 2][b + 1];
        }
        if (a >= 1) {
          dp[a][b] += Modint(b) * dp[a - 1][b];
        }
      }
    }
  }

  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  set<int> exist;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (arr[i] != -1) {
      exist.insert(arr[i]);
    }
  }

  int A = 0, B = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == -1) {
      if (exist.count(i)) {
        B++;
      } else {
        A++;
      }
    }
  }

  cout << dp[A][B] << endl;
}