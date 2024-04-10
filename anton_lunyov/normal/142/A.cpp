#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef __int64 LL;
typedef unsigned __int64 ULL;
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

int main()
{
#ifdef MY_DEBUG
	freopen("a.in","r",stdin);
#endif
	int n;
	while(scanf("%d",&n)>0)
	{
		VI a;
		int d,i,j;
		for(d=1;d*d<n;d++)
			if(n%d==0) a.pb(d),a.pb(n/d);
		if(d*d==n) a.pb(d);
		sort(all(a));
		LL minv=INF,maxv=-1;
		for(i=0;i<a.sz;i++)
		{
			int d1=a[i];
			for(j=0;j<a.sz && a[j]<=n/d1;j++)
			{
				int d2=a[j];
				if(n/d1%d2==0)
				{
					int d3=n/d1/d2;
					LL v=LL(d1+1)*(d2+2)*(d3+2)-n;
					MIN(minv,v);
					MAX(maxv,v);
				}
			}
		}
		printf("%I64d %I64d\n",minv,maxv);
	}
	return 0;
}