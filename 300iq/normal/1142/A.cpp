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

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  int a, b;
  cin >> a >> b;
  vector <ll> ts = {a, (n * k - a) % (n * k)};
  vector <ll> solve;
  for (ll s : ts)
  {
    for (ll i = 0; i < n * k; i += k)
    {
      vector <ll> gt = {(i + b) % (n * k), (i + n * k - b) % (n * k)};
      for (ll t : gt)
      {
        ll jmp = t - s;
        if (jmp <= 0) jmp += (n * k);
        ll when = (n * k) / __gcd(n * k, jmp);
        solve.push_back(when);
      }
    }
  }
  cout << *min_element(solve.begin(), solve.end()) << ' ' << *max_element(solve.begin(), solve.end()) << '\n';
}