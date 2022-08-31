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

const int N = 5e5 + 10;

set <int> g[N];
vector <int> s[N];
set <int> unvis;

void dfs(int v) {
  unvis.erase(v);
  vector <int> children;
  for (int x : unvis) {
    if (!g[v].count(x)) {
      children.push_back(x);
    }
  }
  for (int x : children) unvis.erase(x);
  for (int x : children) {
    s[v].push_back(x);
    dfs(x);
  }
}

bool alive[N];
bool root[N];
int star_id[N];
vector <vector <int> > stars;

void solve_monkas(int v, int pr) {
  vector <int> guys;
  for (int x : s[v]) {
    solve_monkas(x, v);
    if (alive[x]) {
      guys.push_back(x);
    }
  }
  if (guys.size() > 0) {
    vector <int> cur = guys;
    cur.push_back(v);
    for (int x : cur) {
      star_id[x] = stars.size();
    }
    stars.push_back(cur);
    alive[v] = false;
  } else {
    if (pr == -1) {
      if (!s[v].empty()) {
        int me = s[v][0];
        stars[star_id[me]].insert(stars[star_id[me]].begin(), v);
      } else {
        stars.push_back({v});
      }
    }
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
    while (t--) {
    int n, m;
    cin >> n >> m;
    stars.clear();
    for (int i = 0; i < n; i++) g[i].clear(), s[i].clear(), alive[i] = true;
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      g[a].insert(b);
      g[b].insert(a);
    }
    unvis.clear();
    for (int i = 0; i < n; i++) unvis.insert(i);
    for (int i = 0; i < n; i++) {
      if (unvis.count(i)) {
        dfs(i);
        solve_monkas(i, -1);
      }
    }
    vector <int> a, b;
    for (auto c : stars) {
      for (int i = 0; i < (int) c.size(); i++) {
        a.push_back(c[i]);
      }
      b.push_back(c.back());
      for (int i = 0; i + 1 < (int) c.size(); i++) {
        b.push_back(c[i]);
      }
    }
    auto print = [&] (vector <int> p) {
      vector <int> rp(n);
      for (int i = 0; i < n; i++) rp[p[i]] = i;
      for (int i = 0; i < n; i++) cout << rp[i] + 1 << ' ';
      cout << '\n';
    };
    print(a);
    print(b);
  }
}