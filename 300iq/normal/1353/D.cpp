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
    set <pair <int, pair <int, int> > > q;
    q.insert({-n, {0, n - 1}});
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      auto it = *q.begin();
      q.erase(q.begin());
      int l = it.second.first, r = it.second.second;
      int mid = ((l + r) / 2);
      a[mid] = i + 1;
      if (l < mid) q.insert({l - mid, {l, mid - 1}});
      if (mid < r) q.insert({(mid + 1) - r - 1, {mid + 1, r}});
    }
    for (int i= 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
  }
}