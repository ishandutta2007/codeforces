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

int main()
{
#ifdef MY_SIDE
  freopen("b.in","r",stdin);
#endif
  LL n;
  while(scanf("%I64d",&n)>0)
  {
    vector<LL> res;
    for(LL p=0;p<=n;p=2*p+1)
    {
      LL L = 1;
      LL R = 2000000000LL;
      if(p) MIN(R,n/p+1);
      while(L+1<R)
      {
         LL M = (L+R)/2;
         if(p*M + M*(M-1)/2<=n) L=M; else R=M;
      }
      LL m = L;
      if(p*m+m*(m-1)/2==n && m%2) res.pb((p+1)*m);
    }
    if(res.sz==0) puts("-1"); else
    {
      sort(all(res));
      for(int i=0;i<res.sz;i++)
        printf("%I64d\n",res[i]);
    }
  }
  return 0;
}