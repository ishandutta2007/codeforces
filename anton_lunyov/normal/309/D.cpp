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

LL brute(int n,int m)
{
  clock_t start=clock();
  LL ans=0;
  for(int x=m;x<=n-m;x++)
  {
    for(int y=m;y<=n-m;y++)
    {
      int z = ((n-x) * (2*x-y) - 1) / (x+y);
      if(z<m) break;
      ans += min(z,n-m) - m + 1;
    }
  }
  fprintf(stderr,"res=%I64d time=%.3lfsec\n",ans,0.001*(clock()-start));
  return ans;
}

LL semi_brute(int n,int m)
{
  clock_t start=clock();
  LL ans=0;
  for(int x=m;x<=n/2;x++)
  {
    int cur=0;
    int maxy = (x * (2*n-2*x-m) - 1) / (n-x+m);
    for(int y=m;y<=maxy;y++)
    {
      int z = ((n-x) * (2*x-y) - 1) / (x+y);
      cur += min(z,n-m) - m + 1;
    }
    ans += x < n-x ? 2LL*cur : cur;
  }
  fprintf(stderr,"res=%I64d time=%.3lfsec\n",ans,0.001*(clock()-start));
  return ans;
}

int main()
{
#ifdef MY_SIDE
  freopen("d.in","r",stdin);
#endif
  int n,m;
  while(scanf("%d%d",&n,&m)>0)
  {
    n++;
    m++;
    //LL res1 = brute(n,m);
    LL res = semi_brute(n,m);
    //assert(res1==res);
    printf("%I64d\n",3*res);
  }
  return 0;
}