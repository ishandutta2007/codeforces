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
  int n, x, y;
  cin >> n >> x >> y;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    bool bad = false;
    for (int j = max(0, i - x); j < i; j++) {
      if (a[j] <= a[i]) bad = true;
    }
    for (int j = i + 1; j < n && j <= i + y; j++) {
      if (a[j] <= a[i]) bad = true;
    }
    if (!bad) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}