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

#ifdef ONPC
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

map <ll, int> d[2];

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  int n;
  cin >> n;
  d[0][0] = 1;
  ll pref = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    pref ^= x;
    ans += d[(i + 1) % 2][pref];
    d[(i + 1) % 2][pref]++;
  }
  cout << ans << '\n';
}