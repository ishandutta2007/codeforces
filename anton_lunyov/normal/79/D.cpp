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

#define N 10101
#define M 111
#define K 20
int f[1<<K];
int mark[N];
int ind[N];
int d[M];
int bfs[N];
int t[N];
int len;

void add(int u,int T)
{
	if(t[u]>T)
	{
		t[u]=T;
		bfs[len++]=u;
	}
}

int main()
{
#ifdef MY_DEBUG
	freopen("d.in","r",stdin);
#endif
	int n,k,m;
	while(scanf("%d%d%d",&n,&k,&m)>0)
	{
		n++;
		fill(mark,0);
		int i,j,u;
		for(i=0;i<k;i++)
		{
			int x;
			scanf("%d",&x);
			mark[x-1]^=1;
			mark[x]^=1;
		}

		for(i=0;i<m;i++)
			scanf("%d",d+i);
		sort(d,d+m);
		m=unique(d,d+m)-d;

		int g[K];
		int a[K][K];
		int gn=0;
		for(u=0;u<n;u++)
			if(mark[u]) g[gn++]=u;

		for(i=0;i<gn;i++)
		{
			len=0;
			for(u=0;u<n;u++)
				t[u]=inf;
			u=g[i];
			add(u,0);
			for(k=0;k<len;k++)
			{
				u=bfs[k];
				int T=t[u]+1;
				for(j=0;j<m;j++)
				{
					if(u+d[j]<n) add(u+d[j],T);
					if(u-d[j]>=0) add(u-d[j],T);
				}
			}
			for(j=0;j<gn;j++)
				a[i][j]=t[g[j]];
		}
		n=gn;
		f[0]=0;
		int mask;
		for(mask=1;mask<bit(n);mask++)
		{
			for(i=0;i<n;i++)
				if(mask & bit(i)) break;
			f[mask]=inf;
			for(j=i+1;j<n;j++)
				if(mask & bit(j))
					MIN(f[mask],f[mask-bit(i)-bit(j)]+a[i][j]);
		}
		int ans=f[mask-1];
		if(ans==inf) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}