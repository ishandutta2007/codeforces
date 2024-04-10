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
//const LL INF=LL(inf)*inf;
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

#define N 333
int a[N][N];
int p[N];

int main()
{
#ifdef MY_DEBUG
	freopen("b.in","rt",stdin);
#endif
	int n;
	while(scanf("%d",&n)>0)
	{
		int i,j,k,h;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		for(i=1;i<=n;i++)
			scanf("%d",p+i);
		for(i=1;i<=n;i++)
		{
			int bestj=0,besth=inf;
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=n;k++)
					if(p[k]<=j && p[k]!=i) break;
				if(k>n) continue;
				for(h=1;a[i][h]!=p[k];h++);
				if(besth>h)
				{
					besth=h;
					bestj=j;
				}
			}
			printf("%d\n",bestj);
		}
	}
	return 0;
}