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

const ll inf = (ll) (1e18) + 7;

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, c;
  cin >> n >> c;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector <ll> dp(n + 1, inf);
  dp[0] = 0;
  multiset <int> q;
  ll s = 0;
  for (int i = 0; i < c; i++) {
    q.insert(a[i]);
    s += a[i];
  }
  for (int i = 0; i < n; i++) {
    dp[i + 1] = min(dp[i + 1], dp[i] + a[i]);
    if (i + c - 1 < n) {
      dp[i + c] = min(dp[i + c], dp[i] + s - *q.begin());
      s -= a[i];
      q.erase(q.find(a[i]));
      if (i + c < n) {
        q.insert(a[i + c]);
        s += a[i + c];
      }
    }
  }
  cout << dp[n] << endl;
}