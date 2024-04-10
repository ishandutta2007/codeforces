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

#define N 1010101
int a[2*N];

int main()
{
#ifdef MY_SIDE
  freopen("a.in","r",stdin);
#endif
  int n,m,t;
  while(scanf("%d%d%d",&n,&m,&t)>0)
  {
    for(int i=0;i<n;i++)
    {
      scanf("%d",a+i);
      a[n+i]=a[i]+m;
    }
    int d = 2*t%m;
    LL cnt=0;
    for(int i=0,j=0;i<n;i++)
    {
      for(;j<2*n && a[j]-a[i]<=d;j++);
      cnt+=j-i-1;
    }
    double ans = double(2*t/m) * n * (n-1) + cnt;
    printf("%.12lf\n",ans/4);
  }
  return 0;
}