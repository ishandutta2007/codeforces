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

const int N = 100;

vector <pair <int, int> > g[N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <int> ok(n);
  for (int i= 0; i < m; i++) {
    int s, d, c;
    cin >> s >> d >> c;
    s--, d--;
    ok[d] = i;
    g[s].push_back({d, c});
  }
  set <pair <int, int> > q;
  vector <int> ans;
  for (int i = 0; i < n; i++) {
    for (auto c : g[i]) {
      q.insert({c.first, c.second});
    }
    if (!q.empty() && q.begin()->first == i) {
      if (q.begin()->second) {
        cout << -1 << '\n';
        return 0;
      }
      ans.push_back(m+1);
      q.erase(q.begin());
    } else {
      bool good = false;
      for (auto c : q) {
        if (c.second) {
          auto t = c;
          q.erase(t);
          t.second--;
          q.insert(t);
          good = true;
          ans.push_back(ok[c.first]+1);
          break;
        }
      }
      if (!good) {
        ans.push_back(0);
      }
    }
  }
  for (int x : ans) cout << x << ' ';
  cout << endl;
}