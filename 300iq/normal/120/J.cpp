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
#else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cerr << n << endl;
  vector <int> type(n), otype(n);
  vector <pair <int, int> > e(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    int a = 0, b = 0;
    if (x < 0) {
      a = 1;
      x *= -1;
    }
    if (y < 0) {
      b = 1;
      y *= -1;
    }
    int t = 0;
    if (!a && !b) {
      t = 0;
    } else if (a && !b) {
      t = 1;
    } else if (!a && b) {
      t = 2;
    }  else {
      t = 3;
    }
    e[i] = make_pair(x, y);
    type[i] = t;
    if (t == 0) {
      otype[i] = 3;
    } else if (t == 1) {
      otype[i] = 2;
    } else if (t == 2) {
      otype[i] = 1;
    }  else {
      otype[i] = 0;
    }
  }
  vector <int> ord;
  for (int i = 0; i < n; i++)  {
    ord.push_back(i);
  }
  auto f= [&] (pair <int, int> a ){
    return a.first * (ll) a.first + a.second * (ll) a.second;
  };
  sort(ord.begin(), ord.end(), [&] (int i, int j) {
    return f(e[i]) < f(e[j]);
  });
  ll best = 1e18;
  int x = -1, y = -1;
  auto relax = [&] (int i, int j) {
    auto val = f(make_pair(e[i].first - e[j].first, e[i].second - e[j].second));
    if (val < best) {
      best = val;
      x = i, y = j;
    }
  };
  for (int i = 0; i < (int) ord.size(); i++) {
    for (int j = max(0, i - 300); j < i; j++) {
      relax(ord[i], ord[j]);
    }
  }
  cout << x + 1 << ' ' << type[x] + 1 << ' ' << y + 1 << ' ' << otype[y] + 1 << '\n';
}