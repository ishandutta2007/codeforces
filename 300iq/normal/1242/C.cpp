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

bool dp[1 << 15];
vector <pair <int, int> > ans[1 << 15];
int go[1 << 15];
pair <int, int> ret[15];

int its = 0;

void solve(int mask) {
  if (!ans[mask].empty()) {
    for (int j = 0; j < (int) ans[mask].size(); j++) {
      ret[ans[mask][j].first] = make_pair(ans[mask][j].second, ans[mask][(j - 1 + (int) ans[mask].size()) % (int) ans[mask].size()].first);
    }
  } else {
    solve(go[mask]);
    solve(mask ^ go[mask]);
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  vector <vector <int> > a(k);
  vector <ll> sm(k);
  map <ll, pair <int, int> > mp;
  ll tot = 0;
  for (int i = 0; i < k; i++) {
    int n;
    cin >> n;
    while (n--) {
      int x;
      cin >> x;
      sm[i] += x;
      a[i].push_back(x);
      tot += x;
    }
    for (int j = 0; j < (int) a[i].size(); j++) {
      mp[a[i][j]] = make_pair(i, a[i][j]);
    }
  }
  if (tot % k) {
    cout << "No\n";
    return 0;
  } 
  tot /= k;
  for (int i = 0; i < k; i++) {
    for (int x : a[i]) {
      int cur = x;
      int boxes = (1 << i);
      bool bad = false;
      vector <pair <int, int> > e;
      e.push_back({i, x});
      int last_box = i;
      while (true) {
        ll get = tot - (sm[last_box] - cur);
        if (!mp.count(get)) {
          bad = true;
          break;
        }
        auto go = mp[get];
        if ((boxes >> go.first) & 1) {
          if (go.first != i) {
            bad = true;
            break;
          }
          if (go.second != x) {
            bad = true;
            break;
          }
          break;
        } else {
          e.push_back(go);
          boxes |= (1 << go.first);
          last_box = go.first;
          cur = go.second;
        }
      }
      if (!bad) {
        dp[boxes] = 1;
        ans[boxes] = e;
      }
    }
  }
  for (int mask = 0; mask < (1 << k); mask++) {
    for (int sm = mask; sm > 0; sm = (sm - 1) & mask) {
      if (dp[sm] && dp[mask ^ sm]) {
        dp[mask] = true;
        go[mask] = sm;
      }
    }
  }
  if (!dp[(1 << k) - 1]) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  solve((1 << k) - 1);
  for (int i = 0; i < k; i++) {
    cout << ret[i].first << ' ' << ret[i].second + 1 << '\n';
  }
}