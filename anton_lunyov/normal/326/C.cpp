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

#define N 111
int g[N][3][3];

int sg(int n, int a[N][2])
{
  int res=0;
  for(int i=0;i<n;i++)
  {
    if(a[i][0]==0 && a[i][1]==0) continue;
    int p=0;
    if(a[i][0]==0) p++;
    if(a[i][1]==0) p+=2;
    int j;
    for(j=i+1;j<n && a[j][0]==1 && a[j][1]==1;j++);
    if(j==n || a[j][0]==0 && a[j][1]==0) j--;
    int q=0;
    if(j<n && a[j][0]==0) q++;
    if(j<n && a[j][1]==0) q+=2;
    res^=g[j-i+1][p][q];
    i=j;
  }
  return res;
}

int main()
{
#ifdef MY_SIDE
  freopen("c.in","r",stdin);
#endif
  int n,m;
  for(int p=0;p<3;p++)
    g[1][p][p]=1;
  for(n=2;n<N;n++)
  {
    for(int p1=0;p1<3;p1++)
      for(int p2=0;p2<3;p2++)
      {
        int a[N][2],b[N][2];
        for(int i=0;i<n;i++)
          for(int j=0;j<2;j++) a[i][j]=1;
        if(p1==1) a[0][0]=0;
        if(p1==2) a[0][1]=0;
        if(p2==1) a[n-1][0]=0;
        if(p2==2) a[n-1][1]=0;
        int mark[512]={0};
        for(int i=0;i<n;i++)
          for(int j=0;j<2;j++)
          {
            if(a[i][j])
            {
              memcpy(b,a,sizeof a);
              b[i][j]=0;
              for(int x=i-1;x<=i+1;x++)
              {
                if(0<=x && x<n) b[x][!j]=0;
              }
              if(p1==2 && p2==0)
                p1=p1;
              int k = sg(n,b);
              mark[k]=1;
            }
          }
        int k;
        for(k=0;mark[k];k++);
        g[n][p1][p2]=k;
      }
  }
  while(scanf("%d%d",&n,&m)>0)
  {
    int a[N][2]={0};
    for(int i=0;i<n;i++)
      for(int j=0;j<2;j++) a[i][j]=1;
    while(m--)
    {
      int i,j;
      scanf("%d%d",&i,&j);
      i--;j--;
      a[i][j]=0;
      for(int x=i-1;x<=i+1;x++)
        if(0<=x && x<n) a[x][!j]=0;
    }
    int res = sg(n,a);
    puts(res?"WIN":"LOSE");
  }
  return 0;
}