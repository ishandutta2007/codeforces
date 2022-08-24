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

const int N = 2000;
const int mod = 1e9 + 7;

vector <int> g[N];
bool on[N];
int dp[N];

int calc(int v, int pr) {
  if (!on[v]) return 0;
  ll ans = 1;
  for (int x : g[v]) {
    if (x != pr) {
      ans *= (calc(x, v) + 1);
      ans %= mod;
    }
  }
  return ans;
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int d, n;
  cin >> d >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector <int> ord;
  for (int i = 0; i < n; i++) {
    ord.push_back(i);
  }
  sort(ord.begin(), ord.end(), [&] (int x, int y) {
    return a[x] < a[y];
  });
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int v = ord[i];
    for (int j = i; j < n; j++) {
      if (a[ord[j]] - a[ord[i]] > d) {
        break;
      }
      on[ord[j]] = true;
    }
    ans += calc(v, -1);
    if (ans >= mod) ans -= mod;
    for (int j = i; j < n; j++) {
      if (a[ord[j]] - a[ord[i]] > d) {
        break;
      }
      on[ord[j]] = false;
    }
  }
  cout << ans << '\n';
}