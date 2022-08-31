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

const int N = 4003;

bitset <N> dp;

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    dp.reset();
    int n;
    cin >> n;
    vector <int> p(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      cin >> p[i];
      p[i]--;
    }
    vector <vector <int> > els;
    for (int i = 0; i < 2 * n; i++) {
      if (els.empty() || p[i] > els.back()[0]) {
        els.push_back({p[i]});
      } else {
        els.back().push_back(p[i]);
      }
    }
    dp[0] = 1;
    for (auto c : els) {
      dp |= dp << (int) c.size();
    }
    if (dp[n]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}