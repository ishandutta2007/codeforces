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

const int lg = 20;

const int N = 2e5 + 7;
const int inf = 1e9 + 7;

int t[4 * N];

void upd(int v, int l, int r, int i, int x)
{
  if (r - l == 1)
  {
    t[v] = x;
  }
  else
  {
    int m = (l + r) / 2;
    if (i < m)
      upd(v * 2 + 1, l, m, i, x);
    else
      upd(v * 2 + 2, m, r, i, x);
    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
  }
}

int get(int v, int l, int r, int tl, int tr)
{
  if (tl >= r || tr <= l)
  {
    return inf;
  }
  if (tl >= l && tr <= r)
  {
    return t[v];
  }
  else
  {
    int tm = (tl + tr) / 2;
    return min(get(v * 2 + 1, l, r, tl, tm), get(v * 2 + 2, l, r, tm, tr));
  }
}

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector <int> p(n);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    x--;
    p[x] = i;
  }
  vector <int> a(m);
  for (int i = 0; i < m; i++)
  {
    cin >> a[i];
    a[i]--;
    a[i] = p[a[i]];
  }
  vector <int> dp(m);
  vector <int> last(n, -1);
  vector <vector <int> > jmp(m, vector <int> (lg, -1));
  for (int i = m - 1; i >= 0; i--)
  {
    int go = (a[i] + 1) % n;
    jmp[i][0] = last[go];
    for (int j = 1; j < lg; j++)
    {
      if (jmp[i][j - 1] == -1)
      {
        jmp[i][j] = -1;
      }
      else
      {
        jmp[i][j] = jmp[jmp[i][j - 1]][j - 1];
      }
    }
    last[a[i]] = i;
  }
  vector <int> vl(m);
  for (int i = 0; i < m; i++)
  {
    int cur = i;
    for (int it = 0; it < lg; it++)
    {
      if (cur == -1)
      {
        break;
      }
      if (((n - 1) >> it) & 1)
      {
        cur = jmp[cur][it];
      }
    }
    if (cur == -1)
    {
      vl[i] = inf;
    }
    else
    {
      vl[i] = cur;
    }
    upd(0, 0, m, i, vl[i]);
  }
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    l--, r--;
    if (get(0, l, r + 1, 0, m) <= r)
    {
      cout << 1;
    }
    else
    {
      cout << 0;
    }
  }
  cout << '\n';
}