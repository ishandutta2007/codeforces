#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
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
#pragma comment(linker, "/STACK:266777216")
using namespace std;

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
    freopen("c.in","rt",stdin);
#endif
  LL n;
  while(scanf("%I64d",&n)>0)
  {
    if(n%3) {puts("0"); continue;}
    n/=3;
    vector<LL> a;
    LL d;
    for(d=1;d*d<n;d++)
      if(n%d==0) a.pb(d), a.pb(n/d);
    if(d*d==n) a.pb(d);
    sort(all(a));
    fprintf(stderr,"%d\n",a.sz);
    int ans=0;
    for(int i=1;i<a.sz;i++) {
      LL d = a[i];
      if(d>n/d/d) break;
      LL m = n/d;
      if(m%d==0) {
        LL d1=d, d2=d, d3=m/d;
        if(d3<d1+d2 && (d1+d2+d3)%2==0)
        {
          if(d2==d3) ans++; else ans+=3;
        }
      }
      for(int j=i+1;j<a.sz;j++) {
        LL d2 = a[j];
        if(d2 > m/d2) continue;
        if(m % d2) continue;
        LL d3 = m / d2;
        if(d3<d+d2 && (d+d2+d3)%2==0) {
          if(d2==d3) ans+=3; else ans+=6;
        }
      }
    }
    printf("%d\n",ans);
  }
    return 0;
}