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

#define MOD 1000000000
#define N 101010
int a[N];
int f[N];

int main()
{
#ifdef MY_SIDE
	freopen("e.in","r",stdin);
#endif
  f[0]=f[1]=1;
  for(int n=2;n<N;n++)
    f[n]=(f[n-1]+f[n-2])%MOD;
  int n,m;
  while(scanf("%d%d",&n,&m)>0)
  {
    for(int i=1;i<=n;i++)
      scanf("%d",a+i);
    while(m--)
    {
      int t,l,r;
      scanf("%d%d%d",&t,&l,&r);
      if(t==1) {
        a[l]=r;
      } else {
        int s=0;
        for(int x=0;x<=r-l;x++)
          s=(s+LL(a[x+l])*f[x])%MOD;
        printf("%d\n",s);
      }
    }
  }
	return 0;
}