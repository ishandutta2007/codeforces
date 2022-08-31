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
  int n, w;
  cin >> n >> w;
  vector <int> a(n);
  ll s = 0;
  ll l = 0, r = w;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
    l = max(l, -s);
    r = min(r, w - s);
  }
  if (l > r) cout << 0 << ' ';
  else cout << r - l + 1 << '\n';
}