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

const int N = 6e5 + 7;
const int M = 3e5;

ll ans = 0;

int val[N][2];
int par[N];

vector <pair <int, int> > t[4 * N];

int get(int v)
{
  if (v == par[v])
  {
    return v;
  }
  else
  {
    return get(par[v]);
  }
}

vector <pair <int&, int> > e;
vector <ll> ret;

void add(int u, int v)
{
  u = get(u), v = get(v);
  if (u == v)
  {
    ret.push_back(-1);
    return;
  }
  if (val[u][0] + val[u][1] > val[v][0] + val[v][1])
  {
    swap(u, v);
  }
  e.push_back({par[u], par[u]});
  par[u] = v;
  ret.push_back((ll) val[u][0] * val[v][1] + (ll) val[u][1] * val[v][0]);
  ans += ret.back();
  for (int t = 0; t < 2; t++)
  {
    e.push_back({val[v][t], val[v][t]});
    val[v][t] += val[u][t];
  }
}

void undo()
{
  if (ret.back() == -1)
  {
    ret.pop_back();
    return;
  }
  else
  {
    ans -= ret.back();
    ret.pop_back();
    for (int i = 0; i < 3; i++)
    {
      e.back().first = e.back().second;
      e.pop_back();
    }
  }
}

void upd(int v, int l, int r, int tl, int tr, pair <int, int> p)
{
  if (tl >= r || tr <= l)
  {
    return;
  }
  if (tl >= l && tr <= r)
  {
    t[v].push_back(p);
  }
  else
  {
    int tm = (tl + tr) / 2;
    upd(v * 2 + 1, l, r, tl, tm, p);
    upd(v * 2 + 2, l, r, tm, tr, p);
  }
}

void build(int v, int l, int r)
{
  for (auto c : t[v])
  {
    add(c.first, c.second);
  }
  if (r - l == 1)
  {
    cout << ans << ' ';
  }
  else
  {
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
  }
  for (auto c : t[v])
  {
    undo();
  }
}

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < N; i++)
  {
    int type = (i < M);
    val[i][type] = 1;
    par[i] = i;
  }
  map <pair <int, int>, vector <int> > val;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    b += M;
    val[{a, b}].push_back(i);
  }
  for (auto c : val)
  {
    for (int i = 0; i < (int) c.second.size(); i += 2)
    {
      int l = c.second[i];
      int r = q;
      if (i + 1 < (int) c.second.size())
      {
        r = c.second[i + 1];
      }
      upd(0, l, r, 0, q, c.first);
    }
  }
  build(0, 0, q);
}