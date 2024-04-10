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

const int N = 6e5 + 6;

int t[4 * N];
int d[4 * N];

void upd(int v, int x) {
  t[v] += x;
  d[v] += x;
}

void push(int v) {
  if (d[v]) {
    upd(v * 2 + 1, d[v]);
    upd(v * 2 + 2, d[v]);
    d[v] = 0;
  }
}

void upd(int v, int l, int r, int tl, int tr, int x) {
  if (tl >= r || tr <= l) {
    return;
  }
  if (tl >= l && tr <= r) {
    upd(v, x);
  } else {
    int tm = (tl + tr) / 2;
    push(v);
    upd(v * 2 + 1, l, r, tl, tm, x);
    upd(v * 2 + 2, l, r, tm, tr, x);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
  }
}

int n;

void build(int v, int l, int r) {
  if (r - l == 1) {
    t[v] = -(l - n);
  } else {
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
  }
}

int get(int v, int l, int r, int tl, int tr) {
  if (tl >= r || tr <= l) return 0;
  if (tl >= l && tr <= r) return t[v];
  else {
    push(v);
    int tm = (tl + tr) / 2;
    return max(get(v * 2 + 1, l, r, tl, tm), get(v * 2 + 2, l, r, tm, tr));
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k, m;
  cin >> n >> k >> m;
  build(0, 0, N);
  set <pair <int, int> > q;
  multiset <int> arr;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    int fir_y = n - (y + abs(x - k)) + n;
    if (!q.count({x, y})) {
      q.insert({x, y});
      upd(0, fir_y, N, 0, N, 1);
      arr.insert(fir_y);
    } else {
      q.erase({x, y});
      upd(0, fir_y, N, 0, N, -1);
      arr.erase(arr.find(fir_y));
    }
    if (arr.empty()) cout << 0 << '\n';
    else {
      int ok = *arr.begin();
      cout << max(0, get(0, ok, N, 0, N) - 1) << '\n';
    }
  }
}