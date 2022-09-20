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

int pp[N],p[N];
int L[N];
int R[N];
PII a[N];
int inv[N];
int v[N];
int l[N],r[N];
int h[N];
LL s[N];
LL res[N];

void dfs(int u,int H)
{
	if(L[u]<0)
	{
		h[u]=H;
		l[u]=r[u]=u;
	}
	else
	{
		dfs(L[u],H+1);
		dfs(R[u],H+1);
		l[u]=l[L[u]];
		r[u]=r[R[u]];
	}
}

int main()
{
#ifdef XDEBUG
	freopen("c.in","r",stdin);
#endif
	int n;
	while(scanf("%d",&n)>0)
	{
		int i,u;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",pp+i,&a[i].X);
			if(pp[i]<0) pp[i]=0;
			a[i].Y=i;
			L[i]=R[i]=-1;
		}
		sort(a+1,a+1+n);
		inv[0]=0;
		for(i=1;i<=n;i++)
		{
			inv[a[i].Y]=i;
			v[i]=a[i].X;
		}
		for(i=1;i<=n;i++)
			p[inv[i]]=inv[pp[i]];
		int root;
		for(i=1;i<=n;i++)
		{
			u=p[i];
			if(u>0)
			{
				if(u>i) L[u]=i; else R[u]=i;
			}
			else root=i;
		}
		dfs(root,0);
		fill(s,0);
		for(i=2;i<n;i+=2)
		{
			u=L[i];
			s[l[u]]+=v[i+1];
			s[r[u]+2]-=v[i+1];

			u=R[i];
			s[l[u]]+=v[i-1];
			s[r[u]+2]-=v[i-1];
		}
		res[1]=s[1];
		for(i=3;i<=n;i+=2)
			res[i]=res[i-2]+s[i];
		int q;
		for(scanf("%d",&q);q--;)
		{
			int x;
			scanf("%d",&x);
			if(x<v[1]) i=1; else
			if(x>v[n]) i=n; else
			{
				i=lower_bound(v+1,v+1+n,x)-v;
				if(L[i]>0) i--;
			}
			double ans=1.*res[i]/h[i];
			printf("%.10lf\n",ans);
		}
	}
	return 0;
}