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

struct pt {
  ll x, y;
};

pt operator - (const pt &a, const pt &b) {
  return {a.x - b.x, a.y - b.y};
}

ll operator ^ (const pt &a, const pt &b) {
  return a.x * (ll) b.y - a.y * (ll) b.x;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  /*
  vector <pt> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  */
  auto ask_triang = [&] (int i, int j, int k) {
#ifdef iq
    pt a = p[j] - p[i], b = p[k] - p[i];
    return abs(a ^ b);
#endif
    i++, j++, k++;
    cout << 1 << ' ' << i << ' ' << j << ' ' << k << endl;
    ll x;
    cin >> x;
    return x;
  };
  auto ask_mul = [&] (int i, int j, int k) {
#ifdef iq
    pt a = p[j] - p[i], b = p[k] - p[i];
    return (a ^ b);
#endif
    i++, j++, k++;
    cout << 2 << ' ' << i << ' ' << j << ' ' << k << endl;
    ll x;
    cin >> x;
    return x;
  };
  int best = 1;
  for (int i = 2; i < n; i++) {
    if (ask_mul(0, best, i) < 0) {
      best = i;
    }
  }
  ll suka = -1;
  int go = -1;
  vector <ll> val(n);
  for (int i = 0; i < n; i++) {
    if (i != best && i) {
      ll cur = ask_triang(0, best, i);
      val[i] = cur;
      if (cur > suka) {
        suka = cur;
        go = i;
      }
    }
  }
  vector <ll> l, r;
  for (int i = 0; i < n; i++) {
    if (i && i != best && i != go) {
      if (ask_mul(go, 0, i) > 0) {
        l.push_back(i);
      } else {
        r.push_back(i);
      }
    }
  }
  sort(l.begin(), l.end(), [&] (int x, int y) {
    return val[x] < val[y];
  });
  sort(r.begin(), r.end(), [&] (int x, int y) {
    return val[x] < val[y];
  });
  vector <int> ans = {0, best};
  for (int x : l) ans.push_back(x);
  ans.push_back(go);
  reverse(r.begin(), r.end());
  for (int x : r) ans.push_back(x);
  cout << 0 << ' ';
  for (int x : ans) {
    cout << x + 1 << ' ';
  }
  cout << endl;
}