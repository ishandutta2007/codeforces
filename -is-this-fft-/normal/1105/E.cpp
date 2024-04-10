#include <iostream>
#include <string>
#include <map>

using namespace std;

const int MAX_N = 40;
const int HALF = 20;

typedef long long ll;

ll conn [MAX_N];
int dp [1 << HALF];

int main () {
  ios::sync_with_stdio(false);

  int q, n;
  cin >> q >> n;

  map<string, int> idx;
  ll buf = 0;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;

    if (t == 1) {
      for (int j = 0; j < n; j++) {
        if (buf & 1LL << j) {
          conn[j] |= buf;
        }
      }
      buf = 0;
    } else {
      string str;
      cin >> str;

      if (idx.count(str) == 0) {
        int id = (int) idx.size();
        idx[str] = id;
      }

      buf |= 1LL << idx[str];
    }
  }
  for (int j = 0; j < n; j++) {
    if (buf & 1LL << j) {
      conn[j] |= buf;
    }
  }
  
  int ans = 0;
  for (ll mask = 0; mask < 1LL << min(n, HALF); mask++) {
    // check independence
    int ok = 1;
    for (int j = 0; j < min(n, HALF); j++) {
      if (mask & 1LL << j) {
        if (!((mask & conn[j]) == (1LL << j))) {
          ok = 0;
        }
      }
    }

    if (ok) {
      dp[mask] = __builtin_popcountll(mask);
      ans = max(ans, __builtin_popcountll(mask));
    }
  }

  if (n > HALF) {
    for (int k = 0; k < HALF; k++) {
      int m = 1 << k;
      for (int i = 0; i < 1 << HALF; i++) {
        if (i & m) {
          dp[i] = max(dp[i], dp[i - m]);
        }
      }
    }

    for (ll mask = 0; mask < 1LL << n; mask += 1LL << HALF) {
      // check independence, calc allowed bits in other half
      int ok = 1;
      ll forb = 0;
      for (int j = HALF; j < n; j++) {
        if (mask & 1LL << j) {
          forb |= conn[j];
          if (!((mask & conn[j]) == (1LL << j))) {
            ok = 0;
          }
        }
      }

      if (ok) {
        ll oth = (~forb) & ((1LL << HALF) - 1);
        ans = max(ans, __builtin_popcountll(mask) + dp[oth]);
      }
    }
  }

  cout << ans << endl;
}