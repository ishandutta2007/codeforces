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

const int N = 5e5 + 20;

int dsu[N];
int col[N];
int done[N];
int sz[N];

int get(int v) {
  if (v == dsu[v]) {
    return v;
  } else {
    return dsu[v] = get(dsu[v]);
  }
}

int get_col(int v) {
  if (v == dsu[v]) {
    return col[v];
  } else {
    return col[v] ^ get_col(dsu[v]);
  }
}

void uni(int u, int v) {
  int sw = 0;
  if (get_col(u) == get_col(v)) sw = 1;
  int x = get(u), y = get(v);
  if (sz[x] > sz[y]) swap(x, y);
  dsu[x] = y;
  col[x] ^= sw;
  sz[y] += sz[x];
  done[y] |= done[x];
}

const int M = 1e9 + 7;

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) dsu[i] = i, col[i] = 0, done[i] = 0, sz[i] = 1;
  vector <int> ids;
  ll ans = 1;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    int u, v;
    if (k == 1) {
      int x;
      cin >> x;
      x--;
      u = v = x;
    } else {
      cin >> u >> v;
      u--, v--;
    }
    if (get(u) != get(v)) {
      if (!done[get(u)] || !done[get(v)]) {
        uni(u, v);
        ans = (ans * (ll) 2) % M;
        ids.push_back(i);
      }
    } else if (u == v) {
      if (!done[get(u)]) {
        done[get(u)] = 1;
        ans = (ans * (ll) 2) % M;
        ids.push_back(i);
      }
    }
  }
  cout << ans << ' ' << ids.size() << '\n';
  for (int i : ids) cout << i + 1 << ' ';
  cout << '\n';
}