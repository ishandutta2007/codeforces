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
  int n, k;
  cin >> n >> k;
  vector <int> r(n);
  for (int i = 0; i < n; i++) cin >> r[i];
  vector <vector <int> > g(n);
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector <int> t = r;
  sort(t.begin(), t.end());
  auto a = r;
  for (int i = 0; i < n; i++) {
    int ans = 0;
    {
      int l = -1, r = n - 1;
      while (l < r - 1) {
        int m = (l + r) / 2;
        if (t[m] >= a[i]) {
          r = m;
        } else {
          l = m;
        }
      }
      ans = r;
    }
    for (int x : g[i]) {
      if (r[x] < r[i]) ans--;
    }
    cout << ans << ' ';
  }
  cout << '\n';
}