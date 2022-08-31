#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long llong;

const int MAX_BIT = 1005;
const int MOD = 1000000007;

llong ncr [MAX_BIT][MAX_BIT];
llong bell [MAX_BIT];
string st [MAX_BIT];

int main () {
  ncr[0][0] = 1;
  for (int i = 1; i < MAX_BIT; i++) {
    ncr[i][0] = 1;
    for (int j = 1; j < MAX_BIT; j++) {
      ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
      ncr[i][j] %= MOD;
    }
  }

  bell[0] = 1;
  for (int i = 1; i < MAX_BIT; i++) {
    bell[i] = 0;
    for (int j = 0; j < i; j++) {
      bell[i] += (ncr[i - 1][j] * bell[j]) % MOD;
      bell[i] %= MOD;
    }
  }

  int bitc, height;
  cin >> bitc >> height;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < bitc; j++) {
      char c;
      cin >> c;

      st[j] += c;
    }
  }

  sort(st, st + bitc);

  vector<int> setsz (1, 1);
  for (int i = 1; i < bitc; i++) {
    if (st[i] == st[i - 1]) {
      setsz.back()++;
    } else {
      setsz.push_back(1);
    }
  }

  llong ans = 1;
  for (int i : setsz) {
    ans *= bell[i];
    ans %= MOD;
  }

  cout << ans << endl;
}