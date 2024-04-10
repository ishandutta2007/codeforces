
//Petrozavodsk Winter-2016. JAG Contest <3
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
 
#include <stdlib.h>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
 
const int N = 205, M = 3005 << 1;
 
int n, m, p, s, t;
 
int top, head[N], to[M], nxt[M], c[M], l[M];
 
void
addedge (int u, int v, int cap, int len)
{
  to[top] = v, nxt[top] = head[u], c[top] = cap, l[top] = len, head[u] =
    top++;
}
 
vector < pair < int, int >>paths;
 
int dis[N], fa[N];
 
bool inque[N];
 
const int INF = 1000000000;
 
bool
go (int source, int target)
{
  for (int i = 0; i < n; ++i)
    {
      dis[i] = INF;
    }
  dis[source] = 0;
  inque[source] = true;
  queue < int >q;
  q.push (source);
  while (q.size ())
    {
      int u = q.front ();
      inque[u] = false;
      q.pop ();
      for (int i = head[u]; ~i; i = nxt[i])
	{
	  if (c[i])
	    {
	      int v = to[i], nd = dis[u] + l[i];
	      if (dis[v] > nd)
		{
		  dis[v] = nd;
		  fa[v] = i;
		  if (!inque[v])
		    {
		      inque[v] = true;
		      q.push (v);
		    }
		}
	    }
	}
    }
  if (dis[target] == INF)
    {
      return false;
    }
  int f = INF;
  int u = target;
  while (u != source)
    {
      int e = fa[u];
      f = min (f, c[e]);
      u = to[e ^ 1];
    }
  paths.push_back (make_pair (f, dis[target]));
  u = target;
  while (u != source)
    {
      int e = fa[u];
      c[e] -= f, c[e ^ 1] += f;
      u = to[e ^ 1];
    }
  return true;
}
 
int main ()
{
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  s = 1, t = n;
  --s, --t;
  top = 0;
  memset (head, -1, sizeof (head));
  for (int i = 0; i < m; ++i)
    {
      int u, v, w;
      cin >> u >> v >> w;
      --u, --v;
      addedge (u, v, 1, w);
      addedge (v, u, 0, -w);
    }
  while (go (s, t))
    {
      continue;
    }
  int q;
  cin >> q;
  while (q--) {
    int p;
    cin >> p;
    int csum = 0, fsum = 0;
    for (int i = 0; i < (int) paths.size (); ++i)
      {
        csum += paths[i].first * paths[i].second;
        fsum += paths[i].first;
        double ans = (double) (p + csum) / fsum;
        if (i + 1 == paths.size () || ans < paths[i + 1].second)
        {
          cout << fixed << setprecision(20) << ans << endl;
          break;
        }
      }
  }
  return 0;
}