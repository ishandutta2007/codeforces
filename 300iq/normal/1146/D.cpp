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

const int N = 2e5 + 7;

bool u[N];

void dfs(int v, int x, int a, int b)
{
  if (u[v])
  {
    return;
  }
  u[v] = true;
  if (v + a <= x) dfs(v + a, x, a, b);
  if (v - b >= 0) dfs(v - b, x, a, b);
}

ll g(int x)
{
  if (x <= 0) return 0;
  else return x * (ll) (x + 1) / 2;
}

ll f(int l, int r)
{
  return g(r) - g(l - 1);
}

int val[N];

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, a, b;
  cin >> m >> a >> b;
  int g = __gcd(a, b);
  ll ans = 0;
  if (m > a + b)
  {
    ans += (m - (a + b + 1) + 1);
    int l = a + b + 1;
    int r = m;
    while (l % g && l <= r)
    {
      ans += l / g;
      l++;
    }
    while (r % g != g - 1 && l <= r)
    {
      ans += r / g;
      r--;
    }
    ll go = f(l / g, r / g) * g;
    ans += go;
    /*
    for (int i = a + b + 1; i <= m; i++)
    {
      ans += i / g;
    }
     */
    m = a + b;
  }
  for (int i = 0; i <= m; i++)
  {
    val[i] = m + 1;
  }
  val[0] = 0;
  set <pair <int, int> > q;
  q.insert({0, 0});
  while (!q.empty())
  {
    int x = q.begin()->second;
    q.erase(q.begin());
    if (x + a <= m && val[x + a] > max(val[x], x + a))
    {
      int go = max(val[x], x + a);
      q.erase({val[x + a], x + a});
      val[x + a] = go;
      q.insert({val[x + a], x + a});
    }
    if (x - b >= 0 && val[x - b] > val[x])
    {
      int go = val[x];
      q.erase({val[x - b], x - b});
      val[x - b] = go;
      q.insert({val[x - b], x - b});
    }
  }
  for (int i = 0; i <= m; i++)
  {
    if (val[i] <= m)
    {
      ans += (m - val[i] + 1);
    }
  }
  cout << ans << endl;
}