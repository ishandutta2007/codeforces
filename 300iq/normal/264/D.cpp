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

const int N = 1e6 + 7;

int fenw[4][4][N];

void inc(int a, int b, int x, int y) {
  for (; x < N; x = (x | (x + 1))) {
    fenw[a][b][x] += y;
  }
}

int get(int a, int b, int x) {
  int s = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1) {
    s += fenw[a][b][x];
  }
  return s;
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  int n = (int) a.size(), m = (int) b.size();
  vector <int> l(n, -1);
  vector <int> r(m, -1);
  int ptr = 0;
  for (int i = 0; i < n; i++) {
    l[i] = ptr;
    if (a[i] == b[ptr]) {
      if (ptr == m - 1) {
        break;
      } else {
        ptr++;
      }
    }
  }
  ptr = 0;
  for (int i = 0; i < m; i++) {
    r[i] = ptr;
    if (b[i] == a[ptr]) {
      if (ptr == n - 1) {
        break;
      } else {
        ptr++;
      }
    }
  }
  auto f = [&] (char c) {
    if (c == 'R') return 0;
    if (c == 'G') return 1;
    if (c == 'B') return 2;
  };
  ll ans = 0;
  int id = -1;
  vector <int> _a(m), _b(m);
  for (int i = 0; i < m; i++) {
    if (r[i] != -1) {
      _a[i] = (i >= 1 ? f(b[i - 1]) : 3);
      _b[i] = f(b[i]);
      inc(_a[i], _b[i], r[i], 1);
    }
  }
  for (int x = 0; x < n; x++) {
    if (l[x] == -1) break;
    while (id + 1 < l[x]) {
      id++;
      if (r[id] != -1)
        inc(_a[id], _b[id], r[id], -1);
    }
    int _a = (x >= 1 ? f(a[x - 1]) : 3);
    int _b = f(a[x]);
    for (int t = 0; t < 4; t++) {
      for (int d = 0; d < 4; d++) {
        if ((t != _b || d != _a) || _a == _b) {
          ans += get(t, d, x);
        }
      }
    }
  }
  /*
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if (l[x] != -1 && r[y] != -1) {
        if (y >= l[x] && x >= r[y]) {
          ans++;
        }
      }
    }
  }
  */
  cout << ans << endl;
}