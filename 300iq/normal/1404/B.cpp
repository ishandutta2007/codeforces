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

const int N = 1e5;

vector <int> g[N];
int dp[N];
int dep[N];
int par[N];
int ans = 0;

void dfs(int v, int pr) {
  dp[v] = 0;
  for (int to : g[v]) {
    if (to != pr) {
      dep[to] = dep[v] + 1;
      par[to] = v;
      dfs(to, v);
      ans = max(ans, dp[v] + dp[to] + 1);
      dp[v] = max(dp[v], dp[to] + 1);
    }
  }
  ans = max(ans, dp[v]);
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
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--, b--;
    ans = 0;
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    ans = 0;
    if (db <= 2 * da) {
      cout << "Alice\n";
    } else {
      dep[a] = 0;
      dfs(a, -1);
      if (dep[b] <= da || ans <= 2 * da) {
        cout << "Alice\n";
      } else {
        cout << "Bob\n";
      }
    }
  }
}