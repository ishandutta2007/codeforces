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
  int n, k;
  cin >> n >> k;
  ll ans = 1;
  if (k >= 2) {
    ans += n * (ll) (n - 1) / 2;
  }
  if (k >= 3) {
    ans += n * (ll) (n - 1) * (ll) (n - 2) / 6 * 2;
  }
  if (k >= 4) {
    ans += n * (ll) (n - 1) * (ll) (n - 2) * (ll) (n - 3) / 24 * 9;
  }
  cout << ans << '\n';
}