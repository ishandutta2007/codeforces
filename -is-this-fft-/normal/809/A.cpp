#include <iostream>
#include <algorithm>

typedef long long llong;

const int MOD = 1000000007;

using namespace std;

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

const int MAX_COMPUTER = 300005;

int computers [MAX_COMPUTER];

int main () {
  ios::sync_with_stdio(false);

  int computerc;
  cin >> computerc;

  for (int i = 0; i < computerc; i++) {
    cin >> computers[i];
  }

  sort(computers, computers + computerc);

  modint ans (0);
  for (int i = 0; i < computerc; i++) {
    ans = ans + (modint(computers[i]) * ((modint(2) ^ i) - modint(1))).val;
    ans = ans - (modint(computers[i]) * ((modint(2) ^ (computerc - i - 1)) - modint(1))).val;
  }

  cout << ans.val << endl;
}