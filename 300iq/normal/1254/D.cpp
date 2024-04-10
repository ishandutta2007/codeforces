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

const int N = 150000 + 7;

vector <int> g[N];
vector <int> son[N];
int tin[N], tout[N];
int sz[N];

int tt = 0;

void dfs(int v, int pr) {
  tin[v] = tt++;
  sz[v] = 1;
  for (int to : g[v]) {
    if (to != pr) {
      son[v].push_back(to);
      dfs(to, v);
      sz[v] += sz[to];
    }
  }
  tout[v] = tt;
}

const int M = 998244353;

int mul(int a, int b) {
  return (a * (ll) b) % M;
}

int add(int a, int b) {
  int c = a + b;
  if (c < 0) c += M;
  if (c >= M) c -= M;
  return c;
}

int pw(int a, int n) {
  int res = 1;
  while (n) {
    if (n % 2 == 0) {
      a = mul(a, a);
      n /= 2;
    } else {
      res = mul(res, a);
      n--;
    }
  }
  return res;
}

int inv(int x) {
  return pw(x, M - 2);
}

int fenw[N];

void inc(int x, int y) {
  for (; x < N; x = (x | (x + 1))) {
    fenw[x] = add(fenw[x], y);
  }
}

int get(int x) {
  int ans = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1) {
    ans = add(ans, fenw[x]);
  }
  return ans;
}

int ug[N];
int val[N];

const int T = 100;

int ok[T][N];

int iv;

int n, q;

void to_fs(int v, int pr, int id) {
  ug[v] = 1;
  for (int to : g[v]) {
    if (to != pr) {
      to_fs(to, v, id);
      ug[v] += ug[to];
    }
  }
}

void zhfs(int v, int pr, int id) {
  if (pr == -1) {
    val[v] = -1;
  } else {
    if (val[pr] != -1) {
      val[v] = val[pr];
    } else {
      val[v] = n - ug[v];
    }
  }
  if (val[v] != -1) {
    ok[id][v] = mul(val[v], iv);
  } else {
    ok[id][v] = 1;
  }
  for (int to : g[v]) {
    if (to != pr) {
      zhfs(to, v, id);
    }
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int a = rnd() % i, b = i;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  vector <int> p;
  for (int i = 0; i < n; i++) {
    p.push_back(i);
  }
  sort(p.begin(), p.end(), [&] (int u, int v) {
    return g[u].size() > g[v].size();
  });
  vector <bool> heavy(n);
  iv = inv(n);
  for (int i = 0; i < min(n, T); i++) {
    heavy[p[i]] = true;
    to_fs(p[i], -1, i);
    zhfs(p[i], -1, i);
  }
  vector <int> b(n);
  vector <int> glob(n);
  for (int i = 0; i < q; i++) {
    int t = 1;
    cin >> t;
    if (t == 1) {
      int v = rnd() % n, d = 1;
      cin >> v >> d;
      v--;
      if (!heavy[v]) {
        for (int x : son[v]) {
          int val = mul(d, mul(n - sz[x], iv));
          inc(tin[x], val);
          inc(tout[x], -val);
        }
        inc(tin[v], d);
        inc(tin[v] + 1, -d);
        int val = mul(d, mul(sz[v], iv));
        inc(0, val);
        inc(tin[v], -val);
        inc(tout[v], val);
      } else {
        glob[v] = add(glob[v], d);
      }
    } else {
      int v;
      cin >> v;
      v--;
      int sum = get(tin[v]);
      for (int i = 0; i < min(n, T); i++) {
        sum = add(sum, mul(glob[p[i]], ok[i][v]));
      }
      cout << sum << '\n';
    }
  }
}