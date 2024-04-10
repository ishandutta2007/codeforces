#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;

typedef long long LL;
const int maxn = 100005;
int n,x[maxn],y[maxn];
int ax[maxn],ay[maxn];
int px[maxn],py[maxn];
bool compx(int u,int v) {return x[u]<x[v];}
bool compy(int u,int v) {return y[u]<y[v];}
int min4(int x,int y,int z,int d) {return min(min(x,y),min(z,d));}
LL ans;bool e[2][2];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("evil.in","r",stdin);
		freopen("evil.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d %d",&x[i],&y[i]),ax[i]=ay[i]=i;
	sort(ax+1,ax+n+1,compx);
	sort(ay+1,ay+n+1,compy);
	for (int i=1;i<=n;i++)
		px[ax[i]]=i,py[ay[i]]=i;
	LL sum=0;int m=n+1>>1;
	for (int i=1;i<=m;i++)
		sum-=x[ax[i]]+y[ay[i]];
	for (int i=n;i>n-m;i--)
		sum+=x[ax[i]]+y[ay[i]];
	sum*=2ll;
	
	if (n%2==0) {
		int z=x[ax[m+1]],d=y[ay[m+1]];
		for (int i=1;i<=n;i++)
			e[px[i]>m][py[i]>m]=true;
		if (!e[1][1]&&!e[0][0]) ans=sum;
		else if (!e[1][0]&&!e[0][1]) ans=sum;
		else ans=sum-2ll*min(x[ax[m+1]]-x[ax[m]],y[ay[m+1]]-y[ay[m]]);
	}
	else {
		int z=x[ax[m]],d=y[ay[m]];
		for (int i=1;i<=n;i++)
		if (i!=ax[m])
			e[px[i]>m][py[i]>m]=true;
		if (ax[m]!=ay[m]) ans=sum;
		else if (!e[1][1]&&!e[0][0]) ans=sum;
		else if (!e[1][0]&&!e[0][1]) ans=sum;
		else ans=sum-2ll*min4(x[ax[m+1]]-x[ax[m]],x[ax[m]]-x[ax[m-1]],y[ay[m+1]]-y[ay[m]],y[ay[m]]-y[ay[m-1]]);
	}
	printf("%lld",ans);
	return 0;
}