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

const int N = 1e6 + 10;
const ll inf = (ll) (1e18);

ll dp[N];
ll ndp[N], zdp[N];
ll f[6];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  for (int i = 0; i < 6; i++) cin >> f[i];
  vector <int> coef, coef2;
  {
    int need = 3 * k;
    for (int pw = 1; pw < (1 << 30); pw *= 2) {
      if (need >= pw) {
        coef.push_back(pw);
        need -= pw;
      }
    }
    coef.push_back(need);
  }
  {
    int need = 3 * (k - 1);
    for (int pw = 1; pw < (1 << 30); pw *= 2) {
      if (need >= pw) {
        coef2.push_back(pw);
        need -= pw;
      }
    }
    coef2.push_back(need);
  }
  for (int i = 0; i < N; i++) {
    dp[i] = -inf;
  }
  dp[0] = 0;
  ll pw = 1;
  for (int i = 0; i < 6; i++) {
    for (int i = 0; i < N; i++) zdp[i] = dp[i];
    for (int x : coef) {
      for (int p = N - 1; p >= 0; p--) {
        if (p + 3 * pw * x < N) {
          dp[p + 3 * pw * x] = max(dp[p + 3 * pw * x], dp[p] + x * f[i]);
        }
      }
    }
    for (int x : coef2) {
      for (int p = N - 1; p >= 0; p--) {
        if (p + 3 * pw * x < N) {
          zdp[p + 3 * pw * x] = max(zdp[p + 3 * pw * x], zdp[p] + x * f[i]);
        }
      }
    }
    for (int i = 0; i < N; i++) {
      for (int p = 0; p < 10; p++) {
        if (i + p * pw < N) {
          dp[i + p * pw] = max(dp[i + p * pw], zdp[i]);
        }
      }
    }
    pw *= 10;
  }
  int q;
  cin >> q;
  while (q--) {
    int s;
    cin >> s;
    cout << dp[s] << '\n';
  }
}