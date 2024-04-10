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
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector <pair <int, int> > ans;
  set <int> mts;
  set <int> thrs;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 1) {
      ans.push_back({n - 1 - i, i});
      mts.insert(i);
      thrs.insert(i);
    } else if (a[i] == 2) {
      if (mts.empty()) {
        cout << -1 << '\n';
        return 0;
      }
      int x = *mts.begin();
      mts.erase(x);
      thrs.erase(x);
      ans.push_back({n - 1 - x, i});
      thrs.insert(i);
    } else if (a[i] == 3) {
      if (thrs.empty()) {
        cout << -1 << '\n';
        return 0;
      }
      int x = *thrs.begin();
      mts.erase(x);
      thrs.erase(x);
      ans.push_back({n - 1 - i, i});
      ans.push_back({n - 1 - i, x});
      thrs.insert(i);
    }
  }
  cout << ans.size() << '\n';
  for (auto c : ans) {
    cout << n - 1 - c.first + 1 << ' ' << c.second + 1 << '\n';
  }
}