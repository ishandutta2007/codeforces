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

#define N 1010
char s[2*N][N];
int a[N][N];

int main()
{
#ifdef MY_SIDE
	freopen("d.in","rt",stdin);
#endif
  int n,m,k;
  while(scanf("%d%d%d",&n,&m,&k)>0)
  {
    int eq=0, neq=0;;
    for(int i=0;i<2*n-1;i++)
    {
      scanf("%s",s[i]);
      for(int j=0;s[i][j];j++)
        if(s[i][j]=='E') eq++; else neq++;
    }
    if(k==1) {
      puts(eq>=3*neq?"YES":"NO");
      if(eq>=3*neq) {
        for(int i=0;i<n;i++)
          for(int j=0;j<m;j++)
            printf("1%c",j<m-1?' ':'\n');
      }
      continue;
    }
    puts("YES");
    if(n<=m) {
      for(int i=0;i<n;i++)
      {
        int cnt=0;
        for(int j=0;j<m;j++)
        {
          if(j==0) a[i][j] = 1; else
            a[i][j] = s[2*i][j-1]=='E' ? a[i][j-1] : 3 - a[i][j-1];
          if(i>0)
          {
            if(s[2*i-1][j]=='E') {
              cnt += a[i][j] == a[i-1][j];
            } else {
              cnt += a[i][j] != a[i-1][j];
            }
          }
        }
        if(i>0 && 2*cnt<m)
          for(int j=0;j<m;j++) a[i][j] = 3 - a[i][j];
      }
    } else {
      for(int j=0;j<m;j++)
      {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
          if(i==0) a[i][j]=1; else
            a[i][j] = s[2*i-1][j]=='E' ? a[i-1][j] : 3 - a[i-1][j];
          if(j>0)
          {
            if(s[2*i][j-1]=='E')
              cnt += a[i][j] == a[i][j-1];
            else
              cnt += a[i][j] != a[i][j-1];
          }
        }
        if(j>0 && 2*cnt<n)
          for(int i=0;i<n;i++) a[i][j] = 3 - a[i][j];
      }
    }
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        printf("%d%c",a[i][j],j<m-1?' ':'\n');
  }
	return 0;
}