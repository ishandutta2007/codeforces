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
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (auto &c : s) {
    if (c == 'W') c = 0;
    else c = 1;
  }
  for (int col = 0; col < 2; col++) {
    string t = s;
    vector <int> ans;
    for (int i = 0; i + 1 < n; i++) {
      if (t[i] != col) {
        t[i] = col;
        t[i + 1] ^= 1;
        ans.push_back(i);
      }
    }
    if (t.back() == col) {
      cout << ans.size() << '\n';
      for (int i : ans) cout << i + 1 << ' ';
      cout << '\n';
      return 0;
    }
  }
  cout << -1 << endl;
}