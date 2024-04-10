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
  int n, k;
  cin >> n >> k;
  vector <int> a(n);
  map <int, int> cnt;
  map <int, vector <int> > moves;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int x = a[i];
    int its = 0;
    while (true) {
      moves[x].push_back(its);
      cnt[x]++;
      x /= 2;
      its++;
      if (!x) break;
    }
  }
  int ok = 1e9;
  for (auto c : cnt) {
    if (c.second >= k) {
      sort(moves[c.first].begin(), moves[c.first].end());
      int ans = 0;
      for (int i = 0; i < k;i++) ans += moves[c.first][i];
      ok = min(ok, ans);
    }
  }
  cout << ok << endl;
}