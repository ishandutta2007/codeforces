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

#define N 101010
int n;
PII a[N];

int gcd(int a,int b)
{
  a=abs(a);
  b=abs(b);
  return b ? gcd(b,a%b) : a;
}

void calc(double& sx, double& sx2)
{
  sx=0;
  sx2=0;
  int mini=0,maxi=0;
  for(int i=0;i<n;i++)
  {
    if(a[mini].X>a[i].X) mini=i;
    if(a[maxi].X<a[i].X) maxi=i;
  }
  int maxx=a[maxi].X;
  for(int i1=mini,j1=mini;;)
  {
    int i2=(i1+1)%n, j2=(j1+n-1)%n;
    int x1=max(a[i1].X,a[j1].X);
    int x2=min(a[i2].X,a[j2].X);
    if(a[i2].X!=maxx || a[j2].X!=maxx) x2--;
    for(int x=x1;x<=x2;x++)
    {
      double y1 = double(a[i2].Y-a[i1].Y)/(a[i2].X-a[i1].X)*(x-a[i1].X)+a[i1].Y;
      double y2 = double(a[j2].Y-a[j1].Y)/(a[j2].X-a[j1].X)*(x-a[j1].X)+a[j1].Y;
      if(y1>y2) swap(y1,y2);
      y1 = ceil(y1);
      y2 = floor(y2);
      sx += (y2-y1+1)*x;
      sx2 += (y2-y1+1)*x*x;
    }
    if(a[i2].X==maxx && a[j2].X==maxx) break;
    if(a[i2].X<a[j2].X) i1=i2; else j1=j2;
  }
}

int main()
{
#ifdef MY_SIDE
    freopen("d.in","rt",stdin);
#endif
  while(scanf("%d",&n)>0)
  {
    for(int i=0;i<n;i++)
      scanf("%d%d",&a[i].X,&a[i].Y);
    LL ar=0;
    LL b=0;
    for(int i=0;i<n;i++)
    {
      int j=(i+1)%n;
      int x1=a[i].X, y1=a[i].Y;
      int x2=a[j].X, y2=a[j].Y;
      ar+=LL(x1)*y2-LL(x2)*y1;
      b+=gcd(x1-x2,y1-y2);
    }
    if(ar<0) ar=-ar;
    LL k = (ar+b)/2+1;
    double sx,sx2;
    calc(sx,sx2);
    for(int i=0;i<n;i++)
      swap(a[i].X, a[i].Y);
    double sy,sy2;
    calc(sy,sy2);
    double res = (k*(sx2+sy2)-sx*sx-sy*sy)/k/(k-1);
    printf("%.10lf\n",res);
  }
  return 0;
}