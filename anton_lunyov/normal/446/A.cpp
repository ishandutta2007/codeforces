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

#define N 101010
int a[N];
int L[N],R[N];

int main()
{
#ifdef MY_SIDE
  freopen("z.in","r",stdin);
#endif
  int n;
  while(scanf("%d",&n)>0) {
    for(int i=0;i<n;i++)
      scanf("%d",a+i);
    for(int i=0;i<n;i++) {
      L[i] = i && a[i-1]<a[i] ? L[i-1]+1 : 1;
    }
    for(int i=n;i--;) {
      R[i] = i<n-1 && a[i]<a[i+1] ? R[i+1]+1 : 1;
    }
    int res=0;
    for(int i=0;i<n;i++) {
      MAX(res, L[i]);
      MAX(res, R[i]);
      if(i<n-1) MAX(res, L[i]+1);
      if(i>0) MAX(res, R[i]+1);
    }
    for(int i=1;i+1<n;i++) {
      if(a[i-1]+1<a[i+1]) {
        MAX(res, L[i-1]+1+R[i+1]);
      }
    }
    printf("%d\n",res);
  }
  return 0;
}