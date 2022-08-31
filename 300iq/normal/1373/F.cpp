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
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    ll need = 0;
    for (int i = 0; i < n; i++) need += a[i];
    ll cur = 0;
    for (int i = 0; i < n; i++) cur += b[i];
    const ll inf = (ll) (1e18) + 7;
    ll ans = inf;
    for (int fir = 0; fir < 2; fir++) {
      vector <ll> dp(2, inf);
      dp[fir] = cur;
      for (int i = 0; i < n; i++) {
        int j = (i + n - 1) % n;
        vector <ll> ndp(2, inf);
        for (int was = 0; was < 2; was++) {
          for (int here = 0; here < 2; here++) {
            ll cost = dp[was];
            if (!here) cost += a[i];
            if (!here && !was) cost -= b[j];
            ndp[here] = min(ndp[here], cost);
          }
        }
        dp = ndp;
      }
      ans = min(ans, dp[fir]);
    }
    if (ans == need) cout << "YES\n";
    else cout << "NO\n";
  }
}