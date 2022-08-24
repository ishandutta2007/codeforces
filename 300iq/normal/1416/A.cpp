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
    vector <vector <int> > pos(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x--;
      pos[x].push_back(i);
    }
    vector <int> ans(n + 1, n);
    for (int i = 0; i < n; i++) {
      if (!pos[i].empty()) {
        int val = max(pos[i][0], n - pos[i].back() - 1);
        for (int t = 1; t < (int) pos[i].size(); t++) {
          val = max(val, pos[i][t] - pos[i][t - 1] - 1);
        }
        ans[val + 1] = min(ans[val + 1], i);
      }
    }
    for (int i = 1; i <= n; i++) {
      ans[i] = min(ans[i], ans[i - 1]);
      if (ans[i] == n) cout << -1 << ' ';
      else cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
  }
}