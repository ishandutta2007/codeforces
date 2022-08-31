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

const int N = 3e5 + 7;

int fenw[N];

int get(int x) {
  int sum = 0;
  for (; x < N; x = (x | (x + 1))) {
    sum += fenw[x];
  }
  return sum;
}

void inc(int x, int y) {
  for (; x >= 0; x = (x & (x + 1)) - 1) {
    fenw[x] += y;
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector <int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) a[i]--;
  vector <int> val(n);
  for (int i = 0; i < n; i++) {
    if (a[i] <= i) {
      val[i] = i - a[i];
    } else {
      val[i] = n + 1;
    }
  }
  vector <vector <pair <int, int> > > need(n);
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    int l = x, r = n - 1 - y;
    need[r].push_back({l, i});
  }
  vector <int> ans(q);
  for (int i = 0; i < n; i++) {
    int vl = -1, vr = i + 1;
    while (vl < vr - 1) {
      int vm = (vl + vr) / 2;
      if (val[i] <= get(vm)) {
        vl = vm;
      } else {
        vr = vm;
      }
    }
    inc(vl, 1);
    for (auto c : need[i]) {
      ans[c.second] = get(c.first);
    }
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
}