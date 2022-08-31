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

vector <pair <int, int> > go[3], gx[3];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 3; i++) go[i].clear(), gx[i].clear();
    int n;
    cin >> n;
    vector <string> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      a[i] = s;
      for (int j = 0; j < n; j++) {
        if (a[i][j] != '.') cnt++;
        if (a[i][j] == 'O') {
          go[(i + j) % 3].push_back({i, j});
        } else if (a[i][j] == 'X') {
          gx[(i + j) % 3].push_back({i, j});
        }
      }
    }
    bool good = false;
    for (int i = 0; i < 3; i++) {
      if (good) break;
      for (int j = 0; j < 3; j++) {
        if (i == j) continue;
        if (go[i].size() + gx[j].size() <= cnt / 3) {
          good = true;
          for (auto c: go[i]) {
            a[c.first][c.second] = 'X';
          }
          for (auto c: gx[j]) {
            a[c.first][c.second] = 'O';
          }
          for (int i = 0; i < n; i++) cout << a[i] << '\n';
          break;
        }
      }
    }
    assert(good);
  }
}