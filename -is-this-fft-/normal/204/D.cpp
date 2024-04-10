#include <iostream>
#include <vector>
#include <algorithm>

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

vector<Modint> calc_dp (const vector<char> &arr, int K) {
  int n = arr.size();
  
  vector<Modint> c (n + 1, Modint(0));
  vector<Modint> cumc (n + 1, Modint(0));
  vector<Modint> dp (n, Modint(0));
  c[0] = Modint(1);
  cumc[0] = Modint(1);

  int lastW = -1;
  for (int i = 0; i < n; i++) {
    if (arr[i] != 'W') {
      // B or X
      if (lastW <= i - K) {
        dp[i] = c[i - K + 1];
      }
    }

    if (arr[i] != 'B') {
      // W or X
      int l = max(-1, max(lastW, i - K));
      c[i + 1] = cumc[i];
      if (l != -1) {
        c[i + 1] -= cumc[l];
      }
    }

    cumc[i + 1] = cumc[i] + c[i + 1];
    if (arr[i] == 'W') lastW = i;
  }

  return dp;
}

char flip (char c) {
  switch (c) {
  case 'B':
    return 'W';
  case 'W':
    return 'B';
  }
  return c;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, K;
  cin >> n >> K;

  vector<char> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  auto ldp = calc_dp(arr, K);
  for (int i = 0; i < n; i++) {
    arr[i] = flip(arr[i]);
  }
  reverse(arr.begin(), arr.end());
  auto rdp = calc_dp(arr, K);
  reverse(rdp.begin(), rdp.end());
  reverse(arr.begin(), arr.end());

  Modint srdp (0), ans (0);
  for (int i = n - 1; i >= 0; i--) {
    ans += ldp[i] * srdp;
    if (arr[i] == 'X') {
      srdp *= Modint(2);
    }
    srdp += rdp[i];
  }

  cout << ans << endl;
}