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

const int N = 2e5 +7;

vector <int> g[N];


int n;
vector <int> mda(int s) {
  vector <int> dist(n, -1);
  dist[s] = 0;
  queue <int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int to  : g[v]) {
      if (dist[to] == -1) {
        dist[to] = dist[v] + 1;
        q.push(to);
      }
    }
  }
  return dist;
}


int t[4 * N];

void build(int v, int l, int r, vector <pair <int, int> > &e) {
  if (r - l == 1) {
    t[v] = e[l].second;
  } else {
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m, e);
    build(v * 2 + 2, m, r, e);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
  }
}

int get(int v, int l, int r, int tl, int tr) {
  if (tl >= r || tr <= l) {
    return -1e9;
  }
  if (tl >= l && tr <= r) {
    return t[v];
  } else {
    int tm = (tl + tr ) / 2;
    return max(get(v * 2 + 1, l, r, tl, tm), get(v * 2 + 2, l, r, tm, tr));
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, k;
  cin >> n >> m >> k;
  vector <int> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < m; i++) {
    int s, t;
    cin >> s >> t;
    s--, t--;
    g[s].push_back(t);
    g[t].push_back(s);
  }
  auto l = mda(0);
  auto r = mda(n - 1);
  vector <pair <int, int> > e;
  for (int i = 0; i < k; i++) {
    e.push_back({l[a[i]], r[a[i]]});
  }
  sort(e.begin(), e.end());
  build(0, 0, k, e);
  auto check = [&] (int x) {
    if (l[n - 1] < x) {
      return false;
    }
    x--;
    multiset <int> q;
    int vl = 0;
    for (int i = 0; i < (int) e.size(); i++) {
      if (i && e[i].second + e[i - 1].first >= x) {
        int l = -1, r = i - 1;
        while (l < r - 1) {
          int m = (l + r) / 2;
          if (e[m].first + e[i].second >= x) {
            r = m;
          } else {
            l = m;
          }
        }
        if (get(0, r, i, 0, k) + e[i].first >= x) {
          return true;
        }
      }
      q.insert(e[i].second);
    }
    return false;
    /*
    int a = 1e9;
    int b = 1e9;
    for (auto c : e) {
      if (a + c.second < x) {
        return false;
      }
      if (b + c.first < x) {
        return false;
      }
      a = min(a, c.first);
      b = min(b, c.second);
    }
    return true;
    */
  };
  int vl = 0, vr = n + 7;
  while (vl < vr - 1) {
    int m = (vl + vr) / 2;
    if (check(m)) {
      vl = m;
    } else {
      vr = m;
    }
  }
  cout << vl << endl;
}