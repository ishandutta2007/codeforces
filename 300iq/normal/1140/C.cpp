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

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <pair <int, int> > e;
  for (int i = 0; i < n; i++)
  {
    int t, b;
    cin >> t >> b;
    e.push_back({b, t});
  }
  sort(e.begin(), e.end());
  ll sum = 0;
  multiset <int> q;
  ll ans = 0;
  for (int i = (int) e.size() - 1; i >= 0; i--)
  {
    sum += e[i].second;
    q.insert(e[i].second);
    while (q.size() > k)
    {
      sum -= *q.begin();
      q.erase(q.begin());
    }
    ans = max(ans, sum * e[i].first);
  }
  cout << ans << endl;
}