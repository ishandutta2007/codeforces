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
#define L 5050505
char buf[L];
string s[N];
int sum[N];
int a[N];
int p[N];
int b[N];

int main()
{
#ifdef MY_SIDE
  freopen("b.in","r",stdin);
#endif
  int n,r,c;
  while(scanf("%d%d%d",&n,&c,&r)>0)
  {
    sum[0]=0;
    for(int i=0;i<n;i++)
    {
      scanf("%s",buf);
      s[i]=buf;
      sum[i+1]=sum[i]+s[i].sz+1;
    }
    for(int i=0,j=0;i<n;i++)
    {
      for(;j<n && sum[j+1]-1-sum[i]<=r;j++);
      a[i]=j;
    }
    a[n]=n;
    for(int i=0;i<=n;i++)
      p[i]=i;
    for(;c;)
    {
      if(c%2) {
        for(int i=0;i<=n;i++) b[i]=p[a[i]];
        for(int i=0;i<=n;i++) p[i]=b[i];
      }
      if(c/=2) {
        for(int i=0;i<=n;i++) b[i]=a[a[i]];
        for(int i=0;i<=n;i++) a[i]=b[i];
      }
    }
    int i0=0;
    for(int i=0;i<=n;i++)
      if(p[i0]-i0 < p[i]-i) i0=i;
    int cnt=0;
    for(int i=i0;i<p[i0];i++)
    {
      if(cnt+s[i].sz>r) {
        printf("\n");
        cnt=0;
      }
      printf("%s",s[i].c_str());
      cnt+=s[i].sz+1;
      if(cnt<r) putchar(' ');
    }
    printf("\n");
  }
  return 0;
}