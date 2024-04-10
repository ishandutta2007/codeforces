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
  int n, m;
  cin >> n >> m;
  vector <ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i= 1; i < n; i++) a[i] += a[i - 1];
  for (int i = 0; i < m; i++) {
    ll x;
    cin >> x;
    int l = -1, r = n - 1;
    while (l < r - 1) {
      int m = (l + r) / 2;
      if (a[m] >= x) {
        r = m;
      } else {
        l = m;
      }
    }
    ll cur = (!r ? 0 : a[r - 1]);
    cout << r + 1 << ' ' << x - cur << '\n';
  }
}