#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 1e5 + 20;
const int inf = 1e9;

int dp[N][2][2];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    for (int i = 0; i < n; i++) {
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          dp[i][a][b] = -inf;
        }
      }
    }
    dp[0][0][0] = 0;
    dp[0][0][1] = 1;
    for (int i = 1; i < n; i++) {
      for (int i2 = 0; i2 < 2; i2++) {
        for (int i1 = 0; i1 < 2; i1++) {
          if (dp[i-1][i2][i1] == -inf) continue;
          for (int me = 0; me < 2; me++) {
            if (me && i1 && s[i] == s[i - 1]) continue;
            if (me && i2 && s[i] == s[i - 2]) continue;
            dp[i][i1][me] = max(dp[i][i1][me], dp[i - 1][i2][i1] + me);
          }
        }
      }
    }
    int ans= 0;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
      ans = max(ans, dp[n -1][i][j]);
    cout << n-ans << '\n';
  }
}