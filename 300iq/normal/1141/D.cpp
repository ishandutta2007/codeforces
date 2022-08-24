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
  int n;
  cin >> n;
  string s;
  cin >> s;
  map <char, vector <int> > mp, tp;
  for (int i = 0; i < n; i++) {
    mp[s[i]].push_back(i);
  }
  cin >> s;
  for (int i = 0; i < n; i++) {
    tp[s[i]].push_back(i);
  }
  vector <pair <int, int> > ans;
  for (char c = 'a'; c <= 'z'; c++) {
    while (mp[c].size() && tp[c].size()) {
      ans.push_back({mp[c].back(), tp[c].back()});
      mp[c].pop_back(), tp[c].pop_back();
    }
    char t = '?';
    while (mp[c].size() && tp[t].size()) {
      ans.push_back({mp[c].back(), tp[t].back()});
      mp[c].pop_back(), tp[t].pop_back();
    }
    swap(c, t);
    while (mp[c].size() && tp[t].size()) {
      ans.push_back({mp[c].back(), tp[t].back()});
      mp[c].pop_back(), tp[t].pop_back();
    }
    swap(c, t);
  }
  char c = '?';
  char t = '?';
  while (mp[c].size() && tp[t].size()) {
    ans.push_back({mp[c].back(), tp[t].back()});
    mp[c].pop_back(), tp[t].pop_back();
  }
  cout << ans.size() << '\n';
  for (auto c : ans) {
    cout << c.first + 1 << ' ' << c.second + 1 << '\n';
  }
}