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

const int N = 1e5 + 7;
const int K = 20;

int st[N][K];
int par[N];
int mark[N];

int tt = 0;

vector <int> g[N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    par[i] = -1;
  }
  vector <int> t(m);
  vector <int> x(m), y(m);
  vector <vector <pair <int,int>> > f(m);
  for (int i = 0; i < m; i++) {
    cin >> t[i];
    if (t[i] == 1) {
      cin >> x[i] >> y[i];
    } else if (t[i] == 2) {
      cin >> x[i];
    }
    if (t[i] == 3) {
      int x, j;
      cin >> x >> j;
      j--, x--;
      f[j].push_back({x, i});
    }
  }
  vector <int> ans(m, -1);
  for (int i= 0; i < m; i++) {
    if (t[i] == 1) {
      x[i]--,y[i]--;
      par[x[i]] = y[i];
    } else if (t[i] == 2) {
      x[i]--;
      tt++;
      int l = x[i];
      while (l != -1) {
        mark[l] = tt;
        l = par[l];
      }
      for (auto c : f[tt - 1]) {
        if (mark[c.first] == tt) {
          ans[c.second] = 1;
        } else {
          ans[c.second] = 0;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (ans[i] == 1)cout << "YES\n";
    else if (ans[i] == 0) cout << "NO\n";
  }
}