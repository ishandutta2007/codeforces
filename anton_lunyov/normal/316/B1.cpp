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

#define N 1111

int main()
{
#ifdef MY_SIDE
	freopen("b.in","r",stdin);
#endif
  int n,x;
  while(scanf("%d%d",&n,&x)>0)
  {
    int mark[N]={0};
    int a[N];
    for(int i=1;i<=n;i++)
    {
      scanf("%d",a+i);
      mark[a[i]]=1;
    }
    int can[N]={1};
    int s=0;
    int px=0;
    for(int i=1;i<=n;i++)
      if(!mark[i])
      {
        bool was=false;
        int k=0;
        for(int j=i;j;j=a[j])
        {
          if(j==x) px=k, was=true;
          k++;
        }
        if(was) px=k-px; else {
          for(int j=s;j>=0;j--)
            if(can[j]) can[j+k]=1;
          s+=k;
        }
      }
    for(int i=0;i<N;i++)
      if(can[i]) printf("%d\n",i+px);
  }
	return 0;
}