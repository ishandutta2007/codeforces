#include <iostream>

using namespace std;

const int MOD = 998244353;

typedef long long llong;

struct modint {
  llong val;

  modint () {
    val = 0;
  }

  modint (llong _val) {
    val = _val % MOD;
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

const int MAX_N = 1005;

modint ncr [MAX_N][MAX_N];
modint dp [MAX_N];

int main () {
  ncr[0][0] = modint(1);
  for (int i = 1; i < MAX_N; i++) {
    ncr[i][0] = modint(1);
    for (int j = 1; j < MAX_N; j++) {
      ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
    }
  }

  int length;
  cin >> length;
  
  modint ans (0);
  for (int i = 0; i < length; i++) {
    int num;
    cin >> num;

    for (int j = i + 1; j <= length; j++) {
      if (num > 0 && num <= j - i - 1) {
        dp[j] = dp[j] + (dp[i] + modint(1)) * ncr[j - i - 1][num];
      }
    }
  }

  cout << dp[length].val << endl;
}