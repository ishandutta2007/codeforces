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

struct pt {
  int x, y;
};

pt operator - (const pt &a, const pt &b) {
  return {a.x - b.x, a.y - b.y};
}

ll dot(pt a, pt b) {
  return a.x * (ll) b.x + a.y * (ll) b.y;
}

bool good(pt a, pt b, pt c) {
  return dot(b - a, c - b) < 0;
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <pt> p;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p.push_back({x, y});
  }
  vector <int> perm(n);
  for (int i= 0; i < n; i++) perm[i] = i;
  shuffle(perm.begin(), perm.end(), rnd);
  function<void(int)> fix = [&] (int i) {
    if (i + 2 >= n || i < 0) return;
    if (good(p[perm[i]], p[perm[i + 1]], p[perm[i + 2]])) {
      return;
    }
    swap(perm[i + 1], perm[i + 2]);
    fix(i - 1);
    fix(i + 1);
  };
  for (int i = 2; i < n; i++) {
    fix(i - 2);
  }
//  for (int i = 0; i < n; i++) cout << "Segment " << p[perm[i]].x << ' ' << p[perm[i]].y << ' ' << p[perm[i - 1]].x << ' ' << p[perm[i - 1]].y << endl;
  for (int i = 0; i < n; i++) cout << perm[i] + 1 << ' ';
  cout << '\n';
}