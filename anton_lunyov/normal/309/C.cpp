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

#define K 33
#define N 1010101
int c[N],b[N];
VI a[K];
int LOG2[1<<15];

int log2(int a)
{
  if(a<bit(15)) return LOG2[a];
  return 15+LOG2[a>>15];
}

int main()
{
#ifdef MY_SIDE
  freopen("c.in","r",stdin);
#endif
  for(int h=0;h<15;h++)
    for(int i=bit(h);i<bit(h+1);i++)
      LOG2[i]=h;
  int n,m;
  while(scanf("%d%d",&n,&m)>0)
  {
    for(int i=0;i<n;i++)
      scanf("%d",c+i);
    int cnt[K]={0};
    for(int i=0;i<m;i++) {
      int b;
      scanf("%d",&b);
      cnt[b]++;
    }
    m=0;
    for(int i=0;i<K;i++)
      while(cnt[i]--) b[m++]=i;
    int L=0;
    int R=m+1;
    while(L+1<R)
    {
      int M=(L+R)/2;
      for(int i=0;i<K;i++) a[i].cl;
      for(int i=0;i<n;i++)
        a[log2(c[i])].pb(c[i]);
      int k=K-1;
      int j;
      for(j=M-1;j>=0;j--)
      {
        for(;k>=0 && a[k].sz==0;k--);
        if(k<b[j]) break;
        int c = a[k].back();
        a[k].pop_back();
        c -= bit(b[j]);
        if(c)
          a[log2(c)].pb(c);
      }
      if(j>=0) R=M; else L=M;
      /*priority_queue<int> q;
      for(int i=0;i<n;i++)
        q.push(a[i]);
      int j;
      for(j=M-1;j>=0;j--)
      {
        int ar = bit(b[j]);
        int cell = q.top();
        q.pop();
        if(cell<ar) break;
        if(cell>ar) q.push(cell-ar);
      }
      if(j>=0) R=M; else L=M;*/
    }
    printf("%d\n",L);
  }
  return 0;
}