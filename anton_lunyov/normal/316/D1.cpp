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

void research()
{
#ifdef MY_SIDE
	freopen("d.out","w",stdout);
#endif
  for(int n=1;n<=10;n++)
  {
    fprintf(stderr,"n=%d:\n",n);
    int p[11];
    for(int i=0;i<n;i++) p[i]=i;
    int res[11]={0};
    do
    {
      int b=0;
      int mark[11]={0};
      for(int i=0;i<n;i++)
        if(!mark[i])
        {
          VI a;
          for(int j=i;!mark[j];j=p[j])
          {
            mark[j]=1;
            a.pb(j);
          }
          sort(all(a));
          if(a.sz>=3)
            MAX(b,a[a.sz-3]+1);
        }
      for(int c=b;c<=n;c++)
        res[c]++;
    }
    while(next_permutation(p,p+n));
    printf("{");
    for(int i=0;i<=n;i++)
      printf("%d%c",res[i],i<n?',':'}');
    printf(",\n");
  }
  exit(0);
}

int res[11][11]={{0},
{1,1},
{2,2,2},
{4,6,6,6},
{10,16,24,24,24},
{26,50,80,120,120,120},
{76,156,300,480,720,720,720},
{232,532,1092,2100,3360,5040,5040,5040},
{764,1856,4256,8736,16800,26880,40320,40320,40320},
{2620,6876,16704,38304,78624,151200,241920,362880,362880,362880},
{9496,26200,68760,167040,383040,786240,1512000,2419200,3628800,3628800,3628800}
};

int main()
{
  //research();
#ifdef MY_SIDE
	freopen("d.in","r",stdin);
#endif
  int n;
  while(scanf("%d",&n)>0)
  {
    int k=0;
    for(int i=0;i<n;i++)
    {
      int a;
      scanf("%d",&a);
      if(a==2) k++;
    }
    printf("%d\n",res[n][k]);
  }
	return 0;
}