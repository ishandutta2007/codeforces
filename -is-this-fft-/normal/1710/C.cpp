#include <iostream>

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

const int MAX_N = 2e5 + 5;

const int XO_SEEN = 0;
const int YO_SEEN = 1;
const int XY_SEEN = 2;

const int A_PASS = 3;
const int B_PASS = 4;
const int C_PASS = 5;

const int BITC = 6;

Modint dp [MAX_N][1 << BITC];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  string s;
  cin >> s;

  int n = s.size();
  
  dp[0][0] = Modint(1);
  for (int i = 0; i < n; i++) {
    int cur = s[i] - '0';
    for (int flags = 0; flags < 1 << BITC; flags++) {
      for (int choice = 0; choice < 1 << 3; choice++) {
        int a = choice & 1;
        int b = (choice >> 1) & 1;
        int c = (choice >> 2) & 1;

        if (!(flags & 1 << A_PASS) && a > cur) continue;
        if (!(flags & 1 << B_PASS) && b > cur) continue;
        if (!(flags & 1 << C_PASS) && c > cur) continue;
        
        int x = a ^ c;
        int y = b ^ c;

        int nxt = flags;
        if (x && !y) nxt |= 1 << XO_SEEN;
        if (!x && y) nxt |= 1 << YO_SEEN;
        if (x && y) nxt |= 1 << XY_SEEN;
        if (cur == 1) {
          if (a == 0) nxt |= 1 << A_PASS;
          if (b == 0) nxt |= 1 << B_PASS;
          if (c == 0) nxt |= 1 << C_PASS;
        }

        dp[i + 1][nxt] += dp[i][flags];
      }
    }
  }

  Modint ans (0);
  for (int flags = 0; flags < 1 << BITC; flags++) {
    if (!(flags & 1 << XO_SEEN)) continue;
    if (!(flags & 1 << YO_SEEN)) continue;
    if (!(flags & 1 << XY_SEEN)) continue;
    ans += dp[n][flags];
  }

  cout << ans << '\n';
}