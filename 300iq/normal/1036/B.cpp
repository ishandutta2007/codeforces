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
  int q;
  cin >> q;
  while (q--) {
    ll n, m, k;
    cin >> n >> m >> k;
    if (n < m) swap(n, m);
    if (n % 2 != m % 2) {
      k--, n--;
    } else if (n % 2 != k % 2) {
      k -= 2, n--, m--;
    }
    if (k < n) {
      cout << -1 << endl;
    } else {
      cout << k << endl;
    }
  }
}