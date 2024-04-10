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

const int N = 5e5 + 7;

vector <int> g[N];
int dp[N];

void dfs(int v, int pr) {
  dp[v] = 0;
  for (int to : g[v]) {
    if (to != pr) {
      dfs(to, v);
      dp[v] = max(dp[v], dp[to] + 1);
    }
  }
}

int ans[3 * N], bns[3 * N];

int diam = 0;


int fenw[N];

void inc(int x, int y) {
  for (; x >= 0; x = (x & (x + 1)) - 1) {
    fenw[x] += y;
  }
}

int get(int x) {
  int ret = 0;
  for (; x < N; x = (x | (x + 1))) {
    ret += fenw[x];
  }
  return ret;
}

void solve(int v, int pr, int up) {
  int a = 0, b = 0;
  vector <int> ret = {up, 0};
  for (int to : g[v]) {
    if (to != pr) {
      int x = dp[to] + 1;
      if (x > a) swap(x, a);
      if (x > b) swap(x, b);
      ret.push_back(dp[to] + 1);
    }
  }
  diam = max(diam, a + b);
  sort(ret.rbegin(), ret.rend());
  for (int i = 1; i < (int) ret.size(); i++) {
    int k = 2 * ret[i];
    if (ret[i - 1] > ret[i]) k++;
    ans[k] = max(ans[k], i + 1);
  }
  for (int to : g[v]) {
    if (to != pr) {
      int go = (a == dp[to] + 1 ? b : a);
      solve(to, v, max(up, go) + 1);
    }
  }
  for (int x : ret) {
    if (x) {
      inc(x, 1);
    }
  }
  auto ok = ret;
  vector <int> f(ret.size());
  for (int to : g[v]) {
    if (to != pr) {
      inc(dp[to] + 1, -1);
      vector <int> ret;
      for (int x : g[to]) {
        if (x != v) {
          ret.push_back(dp[x] + 1);
        }
      }
      sort(ret.rbegin(), ret.rend());
      for (int i = 0; i < (int) ret.size(); i++) {
        int l = 0, r = (int) ok.size();
        while (l < r - 1) {
          int m = (l + r) / 2;
          if (ok[m] <= ret[i]) {
            r = m;
          } else {
            l = m;
          }
        }
        if (r != ok.size()) {
          f[r] = max(f[r], i + 1);
        }
      }
      for (int i = 0; i < (int) ret.size(); i++) {
        int cnt = i + 1 + get(ret[i]);
        bns[2 * ret[i]] = max(bns[2 * ret[i]], cnt);
      }
      inc(dp[to] + 1, 1);
    }
  }
  for (int i = 1; i < (int) ret.size(); i++) {
    f[i] = max(f[i], f[i - 1]);
  }
  for (int i = 0; i < (int) ret.size(); i++) {
    bns[2 * ret[i]] = max(bns[2 * ret[i]], i + f[i]);
  }
  for (int x : ret) {
    if (x) {
      inc(x, -1);
    }
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ts = 0;
  {
    int n;
    cin >> n;
    diam = 0;
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) ans[i] = 0, bns[i] = 0;
    for (int i = 1; i < n; i++) {
      int a = rnd() % i, b = i;
      cin >> a >> b;
      a--, b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    /*
    vector <vector <int> > dist(n, vector <int> (n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = n;
      }
    }
    for (int i = 0; i < n; i++) for (int j : g[i]) dist[i][j] = 1;
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    int lim = (1 << n);
    vector <int> b(n + 1, 1);
    for (int mask = 1; mask < lim; mask++) {
      vector <int> t;
      for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1)
          t.push_back(i);
      }
      if (t.size() <= 1) continue;
      vector <int> lt;
      for (int i : t) {
        for (int j : t) {
          if (i != j)
            lt.push_back(dist[i][j]);
        }
      }
      sort(lt.begin(), lt.end());
      if (lt.back() - lt[0] <= 1) {
        b[lt[0]] = max(b[lt[0]], (int) t.size());
      }
      if (lt.back() == lt[0] && lt[0]) {
        b[lt[0] - 1] = max(b[lt[0] - 1], (int) t.size());
      }
    }
    */
    dfs(0, -1);
    solve(0, -1, 0);
    for (int i = n; i >= 1; i--) {
      if (i + 1 <= n)
        ans[i] = max(ans[i], ans[i + 1]);
      if (i + 2 <= n)
        bns[i] = max(bns[i], bns[i + 2]);
    }
    for (int i = 1; i <= n; i++) {
      ans[i] = max(ans[i], bns[i]);
      ans[i] = max(ans[i], 1 + (i <= diam));
    }
    /*
    for (int i = 1; i <= n; i++) {
      if (ans[i] != b[i]) {
        for (int i = 1; i <= n; i++ )cout << ans[i] << ' ';
        cout << endl;
        for (int i = 1; i <= n; i++) cout << b[i] << ' ';
        cout << endl;
        return 0;
      }
    }
    */
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
  }
}