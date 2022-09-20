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

#define N 1666
char a[N][N];
int n,m;
int mark[N][N];
int cmp;

void dfs(int i,int j)
{
  if(i<0 || j<0 || i>=n || j>=m) return;
  if(!a[i][j] || mark[i][j]) return;
  mark[i][j]=cmp;
  dfs(i-1,j);
  dfs(i+1,j);
  dfs(i,j-1);
  dfs(i,j+1);
}

int res[N*N];
int vis[N][N];

int main()
{
#ifdef MY_SIDE
	freopen("f2.in","r",stdin);
#endif
  while(scanf("%d%d",&n,&m)>0)
  {
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        scanf("%d",a[i]+j);
    cmp=0;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(a[i][j] && !mark[i][j])
        {
          cmp++;
          dfs(i,j);
        }

    for(int i=2;i<n-2;i++)
      for(int j=2;j<m-2;j++)
        if(a[i][j] && !vis[i][j])
        {
          int cnt=0;
          for(int x=i-2;x<=i+2;x++)
            for(int y=j-2;y<=j+2;y++)
              if(a[x][y]) cnt++;
          if(cnt==9)
          {
            res[mark[i][j]]++;
            for(int x=i-2;x<=i+2;x++)
              for(int y=j-2;y<=j+2;y++)
                if(a[x][y]) vis[x][y]=1;
          }
        }

    sort(res+1,res+1+cmp);
    printf("%d\n",cmp);
    for(int i=1;i<=cmp;i++)
      printf("%d%c",res[i],i<cmp?' ':'\n');
  }
  return 0;
}