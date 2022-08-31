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

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

const int N = 1e5 + 6;

vector <int> g[N];
int u[N];
int mt[N];
bool bad[N];

int tt = 228;

bool dfs(int v) {
  if (u[v] == tt) return false;
  u[v] = tt;
  for (int x : g[v]) {
    if (mt[x] == -1 || dfs(mt[x])) {
      mt[x] = v;
      return true;
    }
  }
  return false;
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
    int n, m;
    cin >> n >> m;
    vector <vector <int> > arr(n, vector <int> (m));
    vector <vector <int> > dir(n, vector <int> (m));
    vector <vector <int> > id(n, vector <int> (m));
    vector <int> cell(n * m);
    int ptr = 0;
    vector <int> l, r;
    bool fucked = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        id[i][j] = ptr++;
        bad[id[i][j]] = true;
        if ((i + j) % 2 == 0) {
          l.push_back(id[i][j]);
        } else {
          r.push_back(id[i][j]);
        }
        g[id[i][j]].clear();
        cin >> arr[i][j];
        if (arr[i][j] == 1) fucked = true;
        cell[id[i][j]] = arr[i][j];
      }
    }
    if (fucked) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int t = 0; t < 4; t++) {
          int a = i + dx[t], b = j + dy[t];
          if (0 <= a && a < n && 0 <= b && b < m && arr[a][b] < arr[i][j]) {
            bad[id[i][j]] = false;
            dir[i][j] = t;
          }
        }
      }
    }
    auto add_edge = [&] (int a, int b) {
      g[a].push_back(b);
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int t = 0; t < 4; t++) {
          int a = i + dx[t], b = j + dy[t];
          if (0 <= a && a < n && 0 <= b && b < m && arr[a][b] == arr[i][j]) {
            add_edge(id[i][j], id[a][b]);
          }
        }
      }
    }
    bool fail = false;
    auto solve = [&] (vector <int> a, vector <int> b) {
      vector <char> ok(n * m);
      for (int x : b) ok[x] = 1;
      tt++;
      sort(a.begin(), a.end(), [&] (int u, int v) {
        return bad[u] > bad[v];
      });
      for (int x : b) mt[x] = -1;
      for (int x : a) {
        vector <int> now;
        for (int t : g[x]) {
          if (ok[t]) {
            now.push_back(t);
          }
        }
        g[x] = now;
      }
      vector <int> ret;
      for (int x : a) {
        if (dfs(x)) {
          ret.push_back(x);
          tt++;
        } else if (bad[x]) {
          fail = true;
        }
      }
      return ret;
    };
    auto x = solve(l, r);
    auto y = solve(r, x);
    if (fail) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      string ret = "LRUD";
      vector <int> match(n * m, -1);
      vector <int> lul(n * m);
      for (int t : x) {
        match[t] = mt[t];
        match[mt[t]] = t;
        lul[t] = 1;
        lul[mt[t]] = cell[t] - 1;;
      }
      vector <vector <int> > cost(n, vector <int> (m));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (match[id[i][j]] == -1) {
            pair <int, int> go = make_pair(i + dx[dir[i][j]], j + dy[dir[i][j]]);
            cout << arr[i][j] - arr[go.first][go.second] << ' ';
          } else {
            cout << lul[id[i][j]] << ' ';
          }
        }
        cout << '\n';
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (match[id[i][j]] == -1) {
            cout << ret[dir[i][j]] << ' ';
          } else {
            int my_dir = -1;
            for (int p = 0; p < 4; p++) {
              int a = i + dx[p], b = j + dy[p];
              if (0 <= a && a < n && 0 <= b && b < m && id[a][b] == match[id[i][j]]) {
                my_dir = p;
              }
            }
            cout << ret[my_dir] << ' ';
          }
        }
        cout << '\n';
      }
    }
  }
}