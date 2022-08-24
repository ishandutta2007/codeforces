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

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    vector <int> dp(2);
    dp[0] = 1, dp[1] = 1;
    for (int i = 1; i < n; i++) {
      vector <int> cur(2, -1e9);
      for (int was = 0; was < 2; was++) {
        for (int me =0 ; me < 2; me++) {
          if (x[i - 1] + was > x[i] + me) continue;
          cur[me] = max(cur[me], dp[was] + (x[i] + me != x[i -1]+was));
        }
      }
      dp = cur;
    }
    cout << max(dp[0],dp[1])<<'\n';
  }
}