#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=3005;
const LL inf=(LL)1e16;

int n,m,a[N][N],tot[N];
struct data{int x,y;}b[N];
bool vis[N];

bool cmp(data a,data b)
{
	return a.y<b.y;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		b[i]=(data){x,y};
	}
	std::sort(b+1,b+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		int x=b[i].x,y=b[i].y;
		a[x][++tot[x]]=i;
	}
	LL ans=inf;
	for (int i=1;i<=n;i++)
	{
		LL s=0;int w=tot[1];
		for (int j=1;j<=n;j++) vis[j]=0;
		for (int j=2;j<=m;j++)
			for (int k=1;k<=tot[j]-i+1;k++) s+=(LL)b[a[j][k]].y,vis[a[j][k]]=1,w++;
		for (int j=1;j<=n&&w<i;j++)
			if (!vis[j]&&b[j].x!=1) w++,s+=(LL)b[j].y;
		ans=std::min(ans,s);
	}
	printf("%lld",ans);
	return 0;
}