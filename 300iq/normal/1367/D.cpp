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
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector <int> b(m);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    vector <int> ids;
    for (int i = 0; i < m; i++) ids.push_back(i);
    vector <int> ret;
    vector <vector <int> > ok;
    while (!ids.empty()) {
      int sum = 0;
      vector <int> go, l;
      for (int z : ids) {
        if (!b[z]) {
          l.push_back(z);
          sum++;
        } else {
          go.push_back(z);
        }
      }
      for (int x : go) {
        for (int y : l) {
          b[x] -= abs(x - y);
        }
      }
      ok.push_back(l);
      ids = go;
      ret.push_back(sum);
    }
    reverse(ok.begin(), ok.end());
    map <char, int> cnt;
    for (auto z : s) cnt[z]++;
    vector <char> ans(m);
    for (auto c : ok) {
      for (auto &t : cnt) {
        if (t.second >= (int)c.size()) {
          t.second = 0;
          for (int p : c) {
            ans[p] = t.first;
          }
          break;
        }
        t.second = 0;
      }
    }
    for (int i = 0; i < m; i++) cout << ans[i];
    cout << '\n';
  }
}