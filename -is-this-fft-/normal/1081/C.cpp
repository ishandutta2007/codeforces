#include <iostream>

using namespace std;

typedef long long llong;

const int MOD = 998244353;
struct modint {
  llong val;

  modint () {
    val = 0;
  }

  modint (llong _val) {
    val = _val;
  }
};

modint operator+ (modint p, modint q) {
  return modint((p.val + q.val) % MOD);
}

modint operator- (modint p, modint q) {
  return modint((p.val - q.val + MOD) % MOD);
}

modint operator- (modint p) {
  return modint(0) - p;
}

modint operator* (modint p, modint q) {
  return modint((p.val * q.val) % MOD);
}

modint operator^ (modint p, int q) {
  modint pows [30];

  pows[0] = p;
  for (int i = 1; i < 30; i++) {
    pows[i] = pows[i - 1] * pows[i - 1];
  }

  modint ans (1);
  for (int i = 0; i < 30; i++) {
    if (q & 1 << i) {
      ans = ans * pows[i];
    }
  }

  return ans;
}

modint operator/ (modint p, modint q) {
  return p * (q ^ (MOD - 2));
}

const int maxn = 2005;

modint dp [maxn][maxn];

int main () {
  int bricks, colors, k;
  cin >> bricks >> colors >> k;

  dp[1][0] = modint(colors);
  for (int i = 2; i <= bricks; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j != 0) {
        dp[i][j] = dp[i][j] + modint(colors - 1) * dp[i - 1][j - 1];
      }
    }
  }

  cout << dp[bricks][k].val << endl;
}