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
    vector <string> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector <string> s(n);
    for (int i= 0; i < n; i++) cin >> s[i];
    auto nxt = [&] (int x, int y) {
      if (s[x][y] == 'R') y++;
      else if (s[x][y] == 'L') y--;
      else if (s[x][y] == 'U') x--;
      else x++;
      return make_pair(x, y);
    };
    vector <vector <int> > id(n, vector <int> (m, -1));
    vector <vector <int> > dep(n, vector <int> (m, 0));
    vector <vector <int> > len(n, vector <int> (m, 0));
    int lans = 0;
    int ans = 0;
    int tt = 0;
    set <pair <int, int> > q;
    auto flex = [&] (int i, int j, int cost) {
      int r = i, c = j;
      tt++;
      vector <pair <int, int> > mda;
      while (id[i][j] == -1) {
        mda.push_back({i, j});
        id[i][j] = tt;
        auto go = nxt(i, j);
        i = go.first, j = go.second;
      }
      if (id[i][j] != tt) {
        for (auto c : mda) {
          id[c.first][c.second] = id[i][j];
        }
        mda.push_back({i, j});
      } else {
        for (int x = (int) mda.size() - 1; x >= 0; x--) {
          if (mda[x] == make_pair(i, j)) {
            len[mda.back().first][mda.back().second] = (int) mda.size() - x;
            break;
          }
        }
      }
      for (int x = (int) mda.size() - 2; x >= 0; x--) {
        dep[mda[x].first][mda[x].second] = dep[mda[x + 1].first][mda[x + 1].second] + 1;
        len[mda[x].first][mda[x].second] = len[mda[x + 1].first][mda[x + 1].second];
      }
      dep[r][c] %= len[r][c];
      if (!q.count({id[r][c], dep[r][c]})) {
        q.insert({id[r][c], dep[r][c]});
        lans++, ans += cost;
      }
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (c[i][j] == '0') {
          flex(i, j, 1);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (c[i][j] == '1') {
          flex(i, j, 0);
        }
      }
    }
    cout << lans << ' ' << ans << '\n';
  }
}