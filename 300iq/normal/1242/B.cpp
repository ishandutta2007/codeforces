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

const int N = 1e5 + 7;

set <int> g[N];
set <int> vis;
bool u[N];

void dfs(int v) {
  u[v] = 1;
  vis.erase(v);
  vector <int> ret;
  for (int x : vis) {
    if (!g[v].count(x)) {
      ret.push_back(x);
    }
  }
  for (int t : ret) vis.erase(t);
  for (int t : ret) {
    u[t] = true;
    dfs(t);
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].insert(b);
    g[b].insert(a);
  }
  for (int i = 0; i < n; i++) {
    vis.insert(i);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!u[i]) {
      ans++;
      dfs(i);
    }
  }
  cout << ans - 1 << endl;
}