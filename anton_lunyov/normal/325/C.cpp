#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#include <queue>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

#define assert(f) { if(!(f)) { fprintf(stderr,"Assertion failed: "); fprintf(stderr,#f); fprintf(stderr,"\n"); exit(1); } }

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

const int pinf = 314000000;
#define N 101010

VI a[N];
int tp[N];
int init_diam[N],diam[N];
int init_mon[N],mon[N];
int Dmin[N], Dmax[N];
VI link[N];
bool bad[N];
int cnt[N];
int bfs[N];

void ADD(int& a,int b)
{
  a+=b;
  if(a>pinf) a=pinf;
}

int main()
{
#ifdef MY_SIDE
  freopen("c.in","r",stdin);
#endif
  int n,m;
  while(scanf("%d%d",&m,&n)>0)
  {
    for(int u=1;u<=n;u++)
      link[u].cl;
    for(int i=0;i<m;i++)
    {
      int len=0;
      scanf("%d%d",tp+i,&len);
      init_diam[i]=0;
      VI tmp;
      a[i].cl;
      for(int j=0;j<len;j++)
      {
        int x;
        scanf("%d",&x);
        if(x<0) init_diam[i]++; else
        {
          link[x].pb(i);
          a[i].pb(x);
        }
      }
      init_mon[i]=a[i].sz;
    }
    priority_queue<PII,VPII,greater<PII> > q;
    for(int u=1;u<=n;u++) Dmin[u] = inf; 
    for(int i=0;i<m;i++)
    {
      diam[i] = init_diam[i];
      mon[i] = init_mon[i];
      if(!mon[i]) MIN(Dmin[tp[i]],diam[i]);
    }
    for(int u=1;u<=n;u++)
      if(Dmin[u]<inf) q.push(mp(Dmin[u],u));
    while(q.sz)
    {
      PII p = q.top();
      q.pop();
      int u = p.Y;
      if(Dmin[u]!=p.X) continue;
      for(int j=0;j<link[u].sz;j++)
      {
        int i=link[u][j];
        mon[i]--;
        ADD(diam[i],Dmin[u]);
        int v = tp[i];
        if(mon[i]==0 && Dmin[v]>diam[i])
          q.push(mp(Dmin[v]=diam[i],v));
      }
    }

    for(int i=0;i<m;i++)
      bad[i]=false;
    for(int u=1;u<=n;u++)
    {
      if(Dmin[u]<inf) continue;
      for(int j=0;j<link[u].sz;j++)
      {
        int i = link[u][j];
        bad[i] = true;
      }
    }

    for(int u=1;u<=n;u++) Dmax[u] = cnt[u] = 0;
    for(int i=0;i<m;i++)
    {
      if(bad[i]) continue;
      diam[i] = init_diam[i];
      mon[i] = init_mon[i];
      int u = tp[i];
      if(!mon[i]) {
        MAX(Dmax[u],diam[i]); 
      } else {
        cnt[u]++;
      }
    }
    int len=0;
    for(int u=1;u<=n;u++)
      if(cnt[u]==0 && Dmax[u] && Dmin[u]<inf) bfs[len++]=u;

    for(int k=0;k<len;k++)
    {
      int u = bfs[k];
      for(int j=0;j<link[u].sz;j++)
      {
        int i=link[u][j];
        if(bad[i]) continue;
        mon[i]--;
        ADD(diam[i],Dmax[u]);
        if(mon[i]==0)
        {
          int v = tp[i];
          MAX(Dmax[v],diam[i]);
          cnt[v]--;
          if(cnt[v]==0 && Dmax[v] && Dmin[v]<inf)
            bfs[len++]=v;
        }
      }
    }
    for(int u=1;u<=n;u++)
      if(Dmin[u]==inf) puts("-1 -1"); else
        printf("%d %d\n",Dmin[u],cnt[u]?-2:Dmax[u]);
  }
  return 0;
}