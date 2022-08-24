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
    int n;
    cin >> n;
    vector <int> a(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i % 2 == 0) s += a[i];
    }
    ll here = s;
    vector <ll> p(n + 1);
    s = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) a[i] *= -1;
      s += a[i];
      p[i + 1] = s;
    }
    ll ans = 0;
    for (int parity = 0; parity < 2; parity++) {
      ll mn = 0;
      for (int i = parity; i <= n; i += 2) {
        ans = max(ans, p[i] - mn);
        mn = min(mn, p[i]);
      }
    }
    cout << here + ans << '\n';
  }
}