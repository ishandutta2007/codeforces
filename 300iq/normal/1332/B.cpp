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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int x = 2; x * x <= a[i]; x++) {
        if (a[i] % x == 0) {
          a[i] = x;
          break;
        }
      }
    }
    map <int, int> mp;
    int sz = 0;
    for (int i = 0; i < n; i++) {
      if (!mp.count(a[i])) mp[a[i]] = sz++;
      a[i] = mp[a[i]];
    }
    cout << sz << '\n';
    for (int x : a) cout << x + 1 << ' ';
    cout << '\n';
  }
}