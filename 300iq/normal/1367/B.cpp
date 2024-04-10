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
    int a = 0, b = 0;
    int ops = 0;
    for (int i = 0; i <n ; i++) {
      int x;
      cin >> x;
      if (i % 2 == 0) a++;
      if (x % 2 == 0) a--;
      if (i % 2 == 1) b++;
      if (x % 2 == 1) b--;
      if (i % 2 != x % 2) ops++;
    }
    if (a || b) cout << -1 << '\n';
    else cout << ops / 2 << '\n';
  }
}