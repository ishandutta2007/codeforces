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
  int l, r;
  cin >> l >> r;
  for (int i = l; i <= r; i++) {
    int x = i;
    set <int> q;
    int t = 0;
    while (x) {
      t++;
      q.insert(x % 10);
      x/= 10;
    }
    if (t == q.size()) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}