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
#include <iomanip>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <ll> x(n);
  for (int i = 0; i < n; i++)
  {
    cin >> x[i];
  }
  ll g = x[1]  - x[0];
  for (int i = 2; i < n; i++)
  {
    g = __gcd(g, x[i] - x[0]);
  }
  for (int i = 0; i < m; i++)
  {
    ll p;
    cin >> p;
    if (g % p == 0)
    {
      cout << "YES" << endl;
      cout << x[0] << ' ' << i + 1 << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}