#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

ll tpow [1005];

int main () {
  tpow[0] = 1;
  for (int i = 1; i < 1005; i++) {
    tpow[i] = 2 * tpow[i - 1];
    tpow[i] %= MOD;
  }
  
  int w, h;
  cin >> w >> h;

  cout << (4 * tpow[w - 1] * tpow[h - 1]) % MOD << endl;
}