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

const int N = 200 + 10;

vector <pair <int, int> > g[N];
int col[N];

void dfs(int v, int c) {
  if (col[v] != -1) {
    if (col[v] != c) {
      cout << "NO\n";
      exit(0);
    }
    return;
  }
  col[v] = c;
  for (auto z : g[v]) {
    dfs(z.first, c ^ 1);
  }
}

vector <pair <int, int> > gr[N];

void add_ineq(int a, int b, int c) {//xb - xa >= c
  gr[a].push_back({b, c});
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) col[i] = -1;
  vector <pair <int, int> > ord;
  vector <pair <int, int> > ex;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    ord.push_back({a, b});
    if (c == 1)
      ex.push_back({a, b});
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  dfs(0, 0);
  for (auto c : ord) {
    if (col[c.first] != 0) swap(c.first, c.second);
    add_ineq(c.second, c.first, 0);
    add_ineq(c.first, c.second, -1);
  }
  for (auto c : ex) {
    if (col[c.first] == 0) {
      add_ineq(c.first, c.second, 0);
    } else {
      add_ineq(c.first, c.second, 1);
      //add_ineq(c.second, c.first, 1);
    }
  }
  int ans = -1;
  vector <int> ret;
  for (int who = 0; who < n; who++) {
    vector <int> d(n);
    d[who] = 3 * m;
    for (int it = 0; it < 3 * n; it++) {
      auto was = d;
      for (int i = 0; i < n; i++) {
        for (auto c : gr[i]) {
          d[c.first] = max(d[c.first], d[i] + c.second);
        }
      }
      if (was != d && it >= n) {
        cout << "NO\n";
        return 0;
      }
    }
    for (int i = 0; i < n; i++) d[i] = 2 * d[i] + col[i];
    int ok = *min_element(d.begin(), d.end());
    for (int i = 0; i < n; i++) d[i] -= ok;
    if (*max_element(d.begin(), d.end()) > ans) {
      ans = *max_element(d.begin(), d.end());
      ret = d;
    }
  }
  cout << "YES\n";
  cout << ans << '\n';
  for (int i = 0; i < n; i++) cout << ret[i] << ' ';
    cout << '\n';
  /*
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    if (col[i] == 0) {
      cout << 2 * d[i] << ' ';
    } else {
      cout << 2 * d[i] + 1 << ' ';
    }
  }
  cout << '\n';
  */
}