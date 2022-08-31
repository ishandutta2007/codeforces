#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 7;

vector <int> g[N];
int tin[N], tout[N];

int tt = 0;

struct bomzhara
{
  int cost, u, v, ind;
};

vector <bomzhara> e;

bool operator < (const bomzhara &a, const bomzhara &b)
{
  return a.cost < b.cost;
}

int c[N];
int par[N];

int get(int v)
{
  if (v == par[v]) return v;
  else return par[v] = get(par[v]);
}

void uni(int u, int v)
{
  u = get(u), v = get(v);
  par[u] = v;
}

void dfs(int v, int pr)
{

  tin[v] = tt;
  int childs = 0;
  for (int to : g[v])
  {
    if (to != pr)
    {
      dfs(to, v);
      childs++;
    }
  }
  if (childs == 0)
  {
    tt++;
  }
  tout[v] = tt;
  e.push_back({c[v], tin[v], tout[v], v});
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> c[i];
    par[i] = i;
  }
  for (int i = 1; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  sort(e.begin(), e.end());
  vector <int> ret;
  ll ans = 0;
  int m = (int) e.size();
  int j = 0;
  for (int i = 0; i < m; i++)
  {
    while (j < m && e[j].cost == e[i].cost)
    {
      j++;
    }
    for (int x = i; x < j; x++)
    {
      if (get(e[x].u) != get(e[x].v)) ret.push_back(e[x].ind);
    }
    for (int x = i; x < j; x++)
    {
      if (get(e[x].u) != get(e[x].v))
      {
        uni(e[x].u, e[x].v);
        ans += e[x].cost;
      }
    }
    i = j - 1;
  }
  for (auto c : e)
  {
    if (get(c.u) != get(c.v))
    {
      uni(c.u, c.v);
      ans += c.cost;
      ret.push_back(c.ind);
    }
  }
  cout << ans << ' ' << ret.size() << '\n';
  sort(ret.begin(), ret.end());
  for (int i : ret)cout << i + 1 << ' ';
  cout << endl;
}