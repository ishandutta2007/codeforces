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
	freopen("b.in","rt",stdin);
#endif
  int n,m,k;
  while(scanf("%d%d%d",&n,&m,&k)>0)
  {
    map<int,int> a;
    for(int i=0;i<n;i++)
    {
      int x;
      scanf("%d",&x);
      a[x]++;
    }
    for(int i=0;i<m;i++)
    {
      int x;
      scanf("%d",&x);
      a[x]--;
    }
    bool yes=false;
    LL s=0;
    for(map<int,int>::iterator it = a.end();it!=a.begin();)
    {
      --it;
      s += it->Y;
      if(s>0) yes=true;
    }
    puts(yes?"YES":"NO");
  }
	return 0;
}