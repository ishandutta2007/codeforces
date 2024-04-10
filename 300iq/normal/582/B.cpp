#include <cmath>
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
  int n, T;
  cin >> n >> T;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  multiset <int> q;
  vector <int> ret;
  int dif = 0;
  vector <int> mda;
  for (int x = 0; x < T; x++) {
    for (int i = 0; i < n; i++) {
      auto it = q.upper_bound(a[i]);
      if (it != q.end()) {
        q.erase(it);
      }
      q.insert(a[i]);
    }
    ret.push_back(q.size());
    if (ret.size() >= 2 * n) {
      if (ret.back() - ret[(int) ret.size() - 2] == ret[(int) ret.size() - 2] - ret[(int) ret.size() - 3]) {
        dif = ret.back() - ret[(int) ret.size() - 2];
        break;
      }
    }
  }
  cout << ret.back() + dif * (T - (int) ret.size()) << '\n';
  return 0;
}