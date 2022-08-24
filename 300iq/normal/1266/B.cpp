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
    ll x;
    cin >> x;
    int tot = 1 + 2 + 3 + 4 + 5 + 6 - 7;
    bool good = false;
    for (int i = 1; i <= 6; i++) {
      int ok = tot + i;
      if (x >= ok && (x - ok) % tot == 0) {
        good = true;
      }
    }
    if (good) cout << "YES\n";
    else cout << "NO\n";
  }
}