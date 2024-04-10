#include <stdio.h>
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

#define bit(n) (1<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;

struct item
{
	int x,y,t;
	double p;
	void read()
	{
		scanf("%d%d%d%lf",&x,&y,&t,&p);
	}
	bool operator<(const item &a) const
	{
		return t<a.t;
	}
};

#define N 1111

item a[N];
double E[N];

int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	while(scanf("%d",&n)>0)
	{
		int i,j;
		for(i=0;i<n;i++)
			a[i].read();
		sort(a,a+n);
		double ans=0;
		for(i=0;i<n;i++)
		{
			E[i]=0;
			for(j=0;j<i;j++)
				if(sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y)<=LL(a[i].t-a[j].t)*(a[i].t-a[j].t))
					MAX(E[i],E[j]);
			E[i]+=a[i].p;
			MAX(ans,E[i]);
		}
		printf("%.7lf\n",ans);
	}
	return 0;
}