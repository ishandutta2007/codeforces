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

#define K 11
#define N 50505
char s[N];
char p[K][N];
int L[K],R[K];

int P=137;
LL pw[N];
LL hsh[N];

void calc(char *s, int m, vector<pair<LL,int> >& res)
{
  int n=strlen(s);
  if(m>n) {
    res.cl;
    return;
  }
  int i,j;
  LL h=0;
  for(i=0;i<n;i++)
  {
    h=P*h+s[i];
    if(i>=m) h-=pw[m]*s[i-m];
    if(i>=m-1) hsh[i-m+1]=h;
  }
  int L=n-m+1;
  sort(hsh,hsh+L);
  for(i=0;i<L;i=j)
  {
    for(j=i;j<L && hsh[i]==hsh[j];j++);
    res.pb(mp(hsh[i],j-i));
  }
}

int main()
{
#ifdef MY_SIDE
	freopen("g.in","r",stdin);
#endif
  pw[0]=1;
  for(int n=1;n<N;n++)
    pw[n]=P*pw[n-1];
  int k;
  while(scanf("%s%d",s,&k)>0)
  {
    for(int j=0;j<k;j++)
      scanf("%s%d%d",p[j],L+j,R+j);
    int ans=0;
    int n=strlen(s);
    for(int m=1;m<=n;m++)
    {
      vector<pair<LL,int> > hsh[K];
      for(int j=0;j<k;j++)
        calc(p[j],m,hsh[j]);
      vector<pair<LL,int> > shsh;
      calc(s,m,shsh);
      for(int i=0;i<shsh.sz;i++)
      {
        LL h = shsh[i].X;
        bool good=true;
        for(int j=0;j<k;j++)
        {
          int i = lower_bound(all(hsh[j]),mp(h,-1))-hsh[j].begin();
          if(i<hsh[j].sz && hsh[j][i].X==h)
          {
            if(!(L[j]<=hsh[j][i].Y && hsh[j][i].Y<=R[j]))
              good=false;
          } else {
            if(L[j]>0) good=false;
          }
        }
        if(good) ans++;
      }
    }
    printf("%d\n",ans);
  }
	return 0;
}