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

const int N = 3e5;
const int inf = 1e9 + 7;

vector <int> g[N];

int ans = 0;

int dfs(int v, int pr, int ban) {
  if (v == ban) {
    return -inf;
  }
  int sum = 1;
  for (int to : g[v]) {
    if (to != pr) {
      int go = dfs(to, v, ban);
      if (pr != -1) {
        sum += go;
      } else {
        if (go >= 0) {
          ans += go;
        }
      }
    }
  }
  return sum;
}

int calc(int x, int y) {
  ans = 1;
  dfs(x, -1, y);
  return ans;
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  x--, y--;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout << n * (ll) (n - 1) - calc(x, y) * (ll) calc(y, x) << '\n';
 }