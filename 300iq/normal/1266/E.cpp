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

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map <pair <int, int>, int> q;
  ll ret = 0;
  for (int i = 0; i < n; i++) ret += a[i];
  int qt;
  cin >> qt;
  while (qt--) {
    int s, t, u;
    cin >> s >> t >> u;
    s--;
    u--;
    if (q.count({s, t})) {
      int v = q[{s, t}];
      ret -= max(0, a[v]);
      a[v]++;
      ret += max(0, a[v]);
      q.erase({s, t});
    }
    if (u != -1) {
      ret -= max(0, a[u]);
      q[{s, t}] = u;
      a[u]--;
      ret += max(0, a[u]);
    }
    cout << ret << '\n';
  }
}