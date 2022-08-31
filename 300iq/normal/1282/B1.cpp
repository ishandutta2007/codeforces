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
    int n, p, k;
    cin >> n >> p >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    auto check = [&] (int m) {
      int cur = p;
      while (m >= 0) {
        if (cur < a[m]) {
          return false;
        }
        cur -= a[m];
        if (m >= k - 1) {
          m -= k;
        } else {
          m--;
        }
      }
      return true;
    };
    int l = -1, r=  n;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l + 1 << endl;
  }
}