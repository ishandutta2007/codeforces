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
    vector <vector <int> > a(n, vector <int> (m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    vector <vector <int> > g(n * m);
    auto add_edge = [&] (int a, int b) {
      g[a].push_back(b);
      g[b].push_back(a);
    };
    for (int i = 0; i < n; i++) {
      for (int j= 0; j < m; j++) {
        for (int x = 0; x < n; x++) {
          for (int y = 0; y < m; y++) {
            if (x >= i && y >= j && i + j == (n + m - 2) - x - y) {
              add_edge(i * m + j, x * m + y);
            }
          }
        }
      }
    }
    vector <char> vis(n * m);
    int sum = n * m;
    for (int i = 0; i < n * m; i++) {
      if (!vis[i]) {
        vis[i] = true;
        vector <int> q;
        q.push_back(i);
        for (int z = 0; z < (int) q.size(); z++) {
          int v = q[z];
          for (int to : g[v]) {
            if (!vis[to]) {
              vis[to] = true;
              q.push_back(to);
            }
          }
        }
        map <int, int> mp;
        for (int x : q) {
          mp[a[x / m][x % m]]++;
        }
        int ret = 0;
        for (auto c : mp) {
          ret = max(ret, c.second);
        }
        sum -= ret;
      }
    }
    cout << sum << '\n';
  }
}