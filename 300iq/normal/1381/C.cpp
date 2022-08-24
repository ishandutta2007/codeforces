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
    int n, x, y;
    cin >> n >> x >> y;
    vector <int> b(n);
    vector <int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      b[i]--;
      cnt[b[i]]++;
    }
    int trash = 0;
    for (int i = 0; i <= n; i++) if (!cnt[i]) trash = i;
    int left = n - x;
    int need = y - x;
    int ok = n - x;
    int bound = (2 * left - need) / 2;
    int sum = 0;
    vector <int> ned(n + 1);
    for (int i = 0; i <= n; i++) {
      int grab = min(cnt[i], min(left, bound));
      ned[i] = cnt[i] - grab;
      left -= grab;
    }
    if (!left) {
      vector <int> ans(n);
      vector <pair <int, int> > guys;
      for (int i = 0; i < n; i++) {
        if (ned[b[i]]) {
          ans[i] = b[i];
          ned[b[i]]--;
        } else {
          ans[i] = trash;
          guys.push_back({b[i], i});
        }
      }
      sort(guys.begin(), guys.end());
      vector <int> vals;
      for (int i = 0; i < (int) guys.size(); i++) {
        vals.push_back(guys[i].first);
      }
      rotate(vals.begin(), vals.begin() + ok / 2, vals.end());
      int tot = 0;
      for (int i = 0; i < (int) vals.size(); i++) {
        if (guys[i].first != vals[i] && tot < need) {
          ans[guys[i].second] = vals[i];
          tot++;
        }
      }
      assert(tot == need);
      cout << "YES\n";
      for (int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
      cout << '\n';
    } else {
      cout << "NO\n";
    }
  }
}