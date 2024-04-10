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

const int MAX_N = 105;

Modint choose [MAX_N][MAX_N];
int arr [10];
Modint dp [11][MAX_N];

int main () {
  choose[0][0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    choose[i][0] = Modint(1);
    for (int j = 1; j < MAX_N; j++) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < 10; i++) {
    cin >> arr[i];
  }

  Modint ans (0);
  for (int k = 0; k < n; k++) { // length beyond the first digit
    for (int a = 1; a < 10; a++) { // first digit
      bool reduced = false;
      if (arr[a] != 0) {
        arr[a]--;
        reduced = true;
      }

      // init dp
      for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= k; j++) {
          dp[i][j] = Modint(0);
        }
      }
      dp[0][0] = Modint(1);

      // calc dp
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j + arr[i] <= k; j++) {
          for (int d = arr[i]; j + d <= k; d++) {
            dp[i + 1][j + d] += choose[k - j][d] * dp[i][j];
          }
        }
      }

      ans += dp[10][k];

      if (reduced) {
        arr[a]++;
      }
    }
  }

  cout << ans << endl;
}