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

char s[111111];

int main()
{
#ifdef MY_SIDE
	freopen("a.in","r",stdin);
#endif
  while(scanf("%s",s)>0)
  {
    int mark[10]={0};
    int q=0;
    for(int i=0;s[i];i++)
      if(s[i]=='?') q++; else
      if('A'<=s[i] && s[i]<='J')
        mark[s[i]-'A']=1;
    int fct=1;
    int k=10;
    for(int i=0;i<10;i++)
      if(mark[i]) fct*=k--;
    if(s[0]=='?') {
      fct*=9; q--;
    } else if(s[0]>='A') {
      fct=fct/10*9;
    }
    printf("%d",fct);
    while(q--) printf("0");
    printf("\n");
  }
	return 0;
}