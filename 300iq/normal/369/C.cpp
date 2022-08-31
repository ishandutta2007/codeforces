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

const int N = 1e5;

vector <pair <int, int> > g[N];
int ok[N];
int par[N];
int dep[N];

vector <int> ans;

bool dfs(int v, int pr) {
  bool good = false;
  for (auto c : g[v]) {
    int to = c.first;
    if (to != pr) {
      par[to] = v;
      dep[to] = dep[v] + 1;
      ok[to] = c.second;
      bool t = dfs(to, v);
      if (!t) {
        if (ok[to]) {
          ans.push_back(to);
          good = true;
        }
      }
      if (t) good = true;
    }
  }
  return good;
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    c--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  dfs(0, -1);
  cout << ans.size() << endl;
  for (int x : ans) {
    cout << x + 1 << ' ';
  }
  cout << endl;
}