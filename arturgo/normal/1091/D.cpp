#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#define int long long
using namespace std;

const int MAXI = 1000 * 1000 + 42;
const int MOD = 998244353;

int facto[MAXI];

int invMod(int a) {
  int curMod = MOD - 2;

  int res = 1;
  int val = a;
  for(int puis = 0;puis <= 30;puis++) {
    if(curMod % 2 == 1) {
      res = (val * res) % MOD;
    }
    curMod /= 2;
    val = (val * val) % MOD;
  }
  return res;
}

signed main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  facto[0] = 1;
  for(int i = 1;i < MAXI;i++) {
    facto[i] = (facto[i - 1] * i) % MOD;
  }

  int somme = 1;

  for(int i = 0;i < n;i++) {
    somme = ((somme + facto[n] - facto[n] * invMod(facto[n - i])) % MOD + MOD) % MOD;
  }

  cout << somme << endl;
  return 0;
}