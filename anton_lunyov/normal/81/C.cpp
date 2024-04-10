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
typedef pair<int,int> PII;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) {if(a>(b)) a=(b);}
#define MAX(a,b) {if(a<(b)) a=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

#define N 101010
PII a[N];
int ans[N];

int main()
{
#ifdef MY_DEBUG
	freopen("c.in","r",stdin);
#endif
	int n,n1,n2;
	while(scanf("%d%d%d",&n,&n1,&n2)>0)
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i].X);
			a[i].Y=i;
		}

		if(n1==n2)
		{
			for(i=0;i<n1;i++) ans[i]=1;
			for(;i<n;i++) ans[i]=2;
		}
		else
		{
			if(n1<n2) 
			{
				for(i=0;i<n;i++) a[i].X=-a[i].X;
				sort(a,a+n);
				for(i=0;i<n1;i++) ans[a[i].Y]=1;
				for(;i<n;i++) ans[a[i].Y]=2;
			}
			else
			{
				sort(a,a+n);
				for(i=0;i<n1;i++) ans[a[i].Y]=1;
				for(;i<n;i++) ans[a[i].Y]=2;
			}
		}
		for(i=0;i<n;i++)
			printf("%d%c",ans[i],i<n-1?' ':'\n');
	}
	return 0;
}