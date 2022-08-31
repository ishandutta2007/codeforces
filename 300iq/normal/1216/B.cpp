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
  vector <pair <int, int> > e;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    e.push_back({x, i});
  }
  sort(e.rbegin(), e.rend());
  int x = 0;
  ll ans = 0;
  for (auto c : e) {
    ans += c.first * x + 1;
    x++;
  }
  cout << ans << '\n';
  for (auto c : e) {
    cout << c.second + 1 << ' ';
  }
  cout << endl;
}