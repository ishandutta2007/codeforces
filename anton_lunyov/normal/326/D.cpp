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

#define N 3030
int a[N][N];

struct node
{
  int down,up,left,right;
  int sq_dr, sq_ul;
};

node dp[N][N];

#define get_min(i,j) val[i] < val[j] ? i : j

int mark[101010];

int main()
{
#ifdef MY_SIDE
  freopen("d.in","r",stdin);
#endif
  int n;
  while(scanf("%d",&n)>0)
  {
    fill(mark,0);
    fill(dp,0);
    fill(a,0);
    //int X1=N,X2=0,Y1=N,Y2=0;
    for(int i=1;i<=n;i++)
    {
      int x1,y1,x2,y2;
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      //MIN(X1,x1); MAX(X2,x2);
      //MIN(Y1,y1); MAX(Y2,y2);
      for(int x=x1;x<x2;x++)
        for(int y=y1;y<y2;y++)
          a[x][y]=i;
    }
    for(int i=1;i<N;i++)
      for(int j=1;j<N;j++) if(a[i-1][j-1])
      {
        int h = min(dp[i-1][j].sq_ul, dp[i][j-1].sq_ul) + 1;
        if(!a[i-h][j-h]) h--;
        dp[i][j].sq_ul = h;
      }
    for(int i=N-2;i>=0;i--)
      for(int j=N-2;j>=0;j--) if(a[i][j])
      {
        int h = min(dp[i+1][j].sq_dr, dp[i][j+1].sq_dr) + 1;
        if(!a[i+h-1][j+h-1]) h--;
        dp[i][j].sq_dr = h;
      }
    //for(int i=X1;i<=X2;i++) for(int j=Y1;j<=Y2;j++) printf("(%d,%d)%c",dp[i][j].sq_ul,dp[i][j].sq_dr,j<Y2?' ':'\n');
    for(int j=0;j<N;j++)
    {
      for(int i=1;i<N;i++)
        if(a[i-1][j]!=a[i-1][j-1])
          dp[i][j].up = dp[i-1][j].up + 1;
      for(int i=N-2;i>=0;i--)
        if(a[i][j]!=a[i][j-1])
          dp[i][j].down = dp[i+1][j].down + 1;
    }
    //for(int i=X1;i<=X2;i++) for(int j=Y1;j<=Y2;j++) printf("(%d,%d)%c",dp[i][j].up,dp[i][j].down,j<Y2?' ':'\n');
    for(int i=0;i<N;i++)
    {
      for(int j=1;j<N;j++)
        if(a[i-1][j-1]!=a[i][j-1])
          dp[i][j].left = dp[i][j-1].left + 1;
      for(int j=N-2;j>=0;j--)
        if(a[i-1][j]!=a[i][j])
          dp[i][j].right = dp[i][j+1].right + 1;
    }
    bool no=true;
    for(int z=-N+1;z<N && no;z++)
    {
      int L = max(0,-z);
      int R = min(N,N-z);
      int m = 1;
      for(;m<R-L;m*=2);
      VI val(m,inf);
      for(int i=L;i<R;i++)
        val[i-L] = i-min(min(dp[i][i+z].sq_ul,dp[i][i+z].up),dp[i][i+z].left);
      VI b(2*m);
      for(int i=0;i<m;i++)
        b[m+i]=i;
      for(int i=m-1;i>0;i--)
        b[i] = get_min(b[2*i],b[2*i+1]);
      for(int i=L;i<R;i++)
      {
        int h = min(min(dp[i][i+z].sq_dr,dp[i][i+z].down),dp[i][i+z].right);
        //if(h) printf("%d %d %d\n",i,i+z,h);
        if(h==0) continue;
        int l = m + i-L+1;
        int r = m + i-L+h;
        int j = i-L+1;
        while(l<=r)
        {
          if(l%2) {
            j = get_min(j, b[l]);
            l++;
          }
          if(r%2==0) {
            j = get_min(j, b[r]);
            r--;
          }
          l/=2;
          r/=2;
        }
        if(val[j]<=i) {
          no = false;
          int x1 = i, y1 = i+z;
          int x2 = j + L, y2 = x2+z;
          for(int x=x1;x<x2;x++)
            for(int y=y1;y<y2;y++)
            {
              assert(a[x][y]);
              mark[a[x][y]]=1;
            }
          VI res;
          for(int i=1;i<=n;i++)
            if(mark[i]) res.pb(i);
          printf("YES %d\n",res.sz);
          for(int i=0;i<res.sz;i++)
            printf("%d%c",res[i],i<res.sz-1?' ':'\n');
          break;
        }
      }
    }
    if(no) puts("NO");
  }
  return 0;
}