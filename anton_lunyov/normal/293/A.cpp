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

#define N 1010101
char a[2*N],b[2*N];

int main()
{
#ifdef MY_SIDE
    freopen("a.in","rt",stdin);
#endif
  int n;
  while(scanf("%d",&n)>0)
  {
    scanf("%s%s",a,b);
    int c11=0,c10=0,c01=0;
    for(int i=0;i<2*n;i++)
    {
      if(a[i]=='1' && b[i]=='1') c11++;
      if(a[i]=='1' && b[i]=='0') c10++;
      if(a[i]=='0' && b[i]=='1') c01++;
    }
    int na = 0, nb = 0;
    for(int i=0;i<n;i++)
    {
      if(c11) na++, c11--; else
      if(c10) na++, c10--; else
      if(c01) c01--;

      if(c11) nb++, c11--; else
      if(c01) nb++, c01--; else
      if(c10) c10--;
    }
    if(na==nb) puts("Draw"); else
    if(na>nb) puts("First"); else
      puts("Second");
  }
    return 0;
}