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
unsigned a[N];

void print(unsigned mask)
{
	for(int i=4;i--;)
		printf("%d%c",(mask >> (8*i)) & 255, i?'.':'\n');
}

int main()
{
#ifdef MY_SIDE
	freopen("c.in","r",stdin);
#endif
	int n,k;
	while(scanf("%d%d",&n,&k)>0)
	{
		for(int i=0;i<n;i++)
		{
			int b[4];
			scanf("%d.%d.%d.%d",b,b+1,b+2,b+3);
			a[i]=0;
			for(int j=0;j<4;j++)
				a[i]=256*a[i]+b[j];
		}
		sort(a,a+n);
		unsigned ans=0;
		unsigned mask=0;
		for(int h=31;h>0;h--)
		{
			mask += bit64(h);
			//print(mask);
			int cnt=0;
			for(int i=0;i<n;i++)
				if(i==0 || (a[i] & mask) != (a[i-1] & mask))
					cnt++;
			if(cnt>=k)
			{
				if(cnt==k) ans=mask;
				break;
			}
		}
		if(ans==0) puts("-1"); else
			print(ans);
	}
	return 0;
}