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

#define MOD 1000000000
#define N 201010
int f[N];
int sf[N];

struct node
{
  int a0,a1;
  int n;
  node(){}
  node(int a0_,int a1_,int n_){a0=a0_;a1=a1_;n=n_;}
  node operator+(const node &x) const {
    return node(
      (a0 + LL(f[n-1]) * x.a0 + LL(f[n]) * x.a1) % MOD,
      (a1 + LL(f[n]) * x.a0 + LL(f[n+1]) * x.a1) % MOD,
      n + x.n);
  }
  node operator+(int d) const {
    return node(
      (a0 + LL(sf[n-1]) * d) % MOD,
      (a1 + LL(sf[n]) * d) % MOD,
      n);
  }
};

#define M 4*N
node a[M];
int d[M];

node query(int x,int l,int r,int L,int R,int D)
{
  if(r<L || R<l) return node(0,0,0);
  D+=d[x];
  if(L<=l && r<=R)
    return a[x] + D;
  int m=(l+r)/2;
  node qL = query(2*x,l,m,L,R,D);
  node qR = query(2*x+1,m+1,r,L,R,D);
  return qL + qR;
}

void upd(int x,int l,int r,int L,int R,int D)
{
  if(r<L || R<l) return;
  if(L<=l && r<=R) {
    d[x]+=D;
    return;
  }
  int m=(l+r)/2;
  upd(2*x,l,m,L,R,D);
  upd(2*x+1,m+1,r,L,R,D);
  node qL = a[2*x] + d[2*x];
  node qR = a[2*x+1] + d[2*x+1];
  a[x] = qL + qR;
}

int main()
{
#ifdef MY_SIDE
	freopen("e.in","r",stdin);
#endif
  f[0]=0; sf[0]=0;
  f[1]=1; sf[1]=1;
  for(int n=2;n<N;n++)
  {
    f[n]=(f[n-1]+f[n-2])%MOD;
    sf[n]=(f[n]+sf[n-1])%MOD;
  }
  int n,q;
  while(scanf("%d%d",&n,&q)>0)
  {
    int m=1;
    for(;m<n;m*=2);
    fill(d,0);
    for(int i=0;i<n;i++)
    {
      int x;
      scanf("%d",&x);
      a[m+i] = node(0,x,1);
    }
    for(int i=m-1;i>0;i--)
      a[i] = a[2*i] + a[2*i+1];
    while(q--)
    {
      int t;
      scanf("%d",&t);
      if(t==1) {
        int x,v;
        scanf("%d%d",&x,&v);
        x--;
        node q = query(1,0,m-1,x,x,0);
        int d = v - q.a1;
        upd(1,0,m-1,x,x,d);
      } else if(t==2) {
        int L,R;
        scanf("%d%d",&L,&R);
        L--;R--;
        node q = query(1,0,m-1,L,R,0);
        printf("%d\n",q.a1);
      } else {
        int L,R,d;
        scanf("%d%d%d",&L,&R,&d);
        L--;R--;
        upd(1,0,m-1,L,R,d);
      }
    }
  }
	return 0;
}