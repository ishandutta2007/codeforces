#include <stdlib.h>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#include <bits/stdc++.h>

const int N = 205, M = (50*50) << 1;

int n, m, p, s, t;

int top, head[N], to[M], nxt[M], c[M], l[M];

void
addedge (int u, int v, int cap, int len)
{
  to[top] = v, nxt[top] = head[u], c[top] = cap, l[top] = len, head[u] =
    top++;
}

vector < pair < int, long long >>paths;

long long dis[N], fa[N];

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

int
main ()
{
  scanf ("%d%d", &n, &m);
  s=1;
  t=n;
  --s, --t;
  top = 0;
  memset (head, -1, sizeof (head));
  for (int i = 0; i < m; ++i)
    {
      int u, v, d, c;
      scanf ("%d%d%d", &u, &v, &d);
      c = 1;
      --u, --v;
      addedge (u, v, c, d);
      addedge (v, u, 0, -d);
    }
  while (go (s, t))
    {
      continue;
    }
  int q;
  cin>>q;
  vector<pair<int,int>> req;
  vector<double> answer;
  for (int i=0;i<q;i++){
      int x;
      scanf("%d", &x);
      req.push_back(make_pair(x,i));
      answer.push_back(-1);
  }
  #define all(a) a.begin(),a.end()
  sort(all(req));
  int ppp=0;
  long long csum = 0, fsum = 0;
  for (int i = 0; i < (int) paths.size (); ++i)
    {
      csum += paths[i].first * paths[i].second;
      fsum += paths[i].first;
      while (ppp<req.size()){
      if (i + 1 == paths.size () || (double) (double(req[ppp].first) + csum) / fsum < paths[i + 1].second)
	{
	    answer[req[ppp].second]=(double) (double(req[ppp].first) + csum) / fsum;
	    ppp++;
	}
	else{
	    break;
	}
          
      }
    }
  for (auto i:answer){
	  printf ("%.12f\n", i);
  }
  return 0;
}