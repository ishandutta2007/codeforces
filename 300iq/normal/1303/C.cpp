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
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector <vector <int> > g(26);
    for (int i = 0; i < 26; i++) g[i].clear();
    for (int i = 0; i+1 < (int) s.size(); i++) {
      g[s[i]-'a'].push_back(s[i + 1] - 'a');
      g[s[i + 1]-'a'].push_back(s[i] - 'a');
    }
    for (int i = 0; i < 26; i++) {
      sort(g[i].begin(), g[i].end());
      g[i].resize(unique(g[i].begin(),g[i].end())-g[i].begin());
    }
    set <int> q;
    string ans = "";
    for (int i = 0; i < 26; i++) {
      if (g[i].size() == 0 || g[i].size() == 1) {
        if (q.count(i)) continue;
        int x = i;
        while (true) {
          q.insert(x);
          ans += (x + 'a');
          int was = x;
          for (int to : g[x]) {
            if (!q.count(to)) {
              x = to;
              break;
            }
          }
          if (was == x) break;
        }
      }
    }
    if (ans.size() != 26) {
      cout << "NO\n";
    } else {
      bool bad = false;
      for (int i = 1; i < (int) s.size(); i++) {
        char x = s[i - 1], y = s[i];
        int mda=  0;
        for (int i = 1; i < (int) ans.size(); i++) {
          if (ans[i - 1] == x && ans[i] == y) {
            mda++;
          }
          if (ans[i - 1] == y && ans[i] == x) {
            mda++;
          }
        }
        if (!mda) bad = true;
      }
      if (bad) {
        cout << "NO\n";
      } else {
        cout << "YES" << endl;
        cout << ans << endl;
      }
    }
  }
}