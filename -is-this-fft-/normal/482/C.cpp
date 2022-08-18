#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_L = 20;
const int MAX_N = 50;

ll bads [1 << MAX_L];
ld dp [1 << MAX_L];
string arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int len = arr[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll match = 0;
      for (int k = 0; k < len; k++) {
        if (arr[i][k] == arr[j][k]) {
          match |= 1 << k;
        }
      }
      bads[match] |= 1LL << i;
      bads[match] |= 1LL << j;
    }
  }

  for (int mask = (1 << len) - 1; mask >= 0; mask--) {
    for (int j = 0; j < len; j++) {
      if (!(mask & 1 << j)) {
        bads[mask] |= bads[mask | 1 << j];
      }
    }

    int cnt_bad = __builtin_popcountll(bads[mask]);
    if (cnt_bad != 0) {
      int cnt_free = len - __builtin_popcount(mask);
      for (int j = 0; j < len; j++) {
        if (!(mask & 1 << j)) {
          int their_bad = __builtin_popcountll(bads[mask | 1 << j]);
          dp[mask] += 1 + ((ld) their_bad / (ld) cnt_bad) * dp[mask | 1 << j];
        }
      }

      if (cnt_free != 0) {
        dp[mask] /= (ld) cnt_free;
      }
    }
  }

  cout << fixed << setprecision(12) << dp[0] << endl;
}