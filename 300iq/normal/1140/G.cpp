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

const int N = 3e5 + 7;
const ll inf = (ll) (1e18) + 7;

vector <int> t[N];
vector <pair <int, ll> > g[2 * N];
bool die[N];
int sz[N];

void dfs(int v, int pr)
{
  sz[v] = 1;
  for (int to : t[v])
  {
    if (to != pr && !die[to])
    {
      dfs(to, v);
      sz[v] += sz[to];
    }
  }
}

int centr(int v, int pr, int need)
{
  for (int to : t[v])
  {
    if (to != pr && !die[to] && sz[to] > need / 2)
    {
      return centr(to, v, need);
    }
  }
  return v;
}

const int LG = 20;

int who[2 * N][LG][2];
ll ans[2 * N][LG][2];

void prec(int v, int lg, int type)
{
  priority_queue <pair <ll, int>, vector <pair <ll, int> >, greater <pair <ll, int> > > q;
  q.push({0, v});
  ans[v][lg][type] = 0;
  int root = v;
  while (!q.empty())
  {
    int v = q.top().second;
    ll dist = q.top().first;
    q.pop();
    if (dist > ans[v][lg][type])
    {
      continue;
    }
    who[v][lg][type] = root;
    for (auto c : g[v])
    {
      int to = c.first;
      if (die[to / 2]) continue;
      if (ans[to][lg][type] > ans[v][lg][type] + c.second)
      {
        ans[to][lg][type] = ans[v][lg][type] + c.second;
        q.push({ans[to][lg][type], to});
      }
    }
  }
}

void build(int v, int lg)
{
  dfs(v, -1);
  int x = centr(v, -1, sz[v]);
  prec(2 * x, lg, 0);
  prec(2 * x + 1, lg, 1);
  die[x] = true;
  for (int to : t[x])
  {
    if (!die[to])
    {
      build(to, lg + 1);
    }
  }
}

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n; i++)
  {
    for (int j = 0; j < LG; j++)
    {
      for (int t = 0; t < 2; t++)
      {
        ans[i][j][t] = inf;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    g[2 * i].push_back({2 * i + 1, x});
    g[2 * i + 1].push_back({2 * i, x});
  }
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    ll w1, w2;
    cin >> w1 >> w2;
    a--, b--;
    t[a].push_back(b);
    t[b].push_back(a);
    g[2 * a].push_back({2 * b, w1});
    g[2 * b].push_back({2 * a, w1});
    g[2 * a + 1].push_back({2 * b + 1, w2});
    g[2 * b + 1].push_back({2 * a + 1, w2});
  }
  build(0, 0);
  int q;
  cin >> q;
  while (q--)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    ll out = inf;
    for (int i = 0; i < LG; i++)
    {
      for (int t = 0; t < 2; t++)
      {
        if (who[a][i][t] == who[b][i][t])
        {
          out = min(out, ans[a][i][t] + ans[b][i][t]);
        }
      }
    }
    cout << out << '\n';
  }
}