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
  freopen("a.in","r",stdin);
#endif
  int n;
  while(scanf("%d",&n)>0)
  {
    int x1[11],y1[11],x2[11],y2[11];
    LL ar=0;
    int X1=inf,X2=-inf,Y1=inf,Y2=-inf;
    for(int i=0;i<n;i++)
    {
      scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i);
      MIN(X1,x1[i]);
      MAX(X2,x2[i]);
      MIN(Y1,y1[i]);
      MAX(Y2,y2[i]);
      ar += LL(x2[i]-x1[i]) * (y2[i]-y1[i]);
    }
    puts(X2-X1==Y2-Y1 && LL(X2-X1)*(Y2-Y1)==ar?"YES":"NO");
  }
  return 0;
}