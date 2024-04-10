#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=1000005;
const LL inf=(LL)1e16;

int n,m,k,w[N],pre[N];
bool vis[N];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		int x;scanf("%d",&x);
		vis[x]=1;
	}
	for (int i=1;i<=k;i++) scanf("%d",&w[i]);
	if (vis[0]) {puts("-1");return 0;}
	for (int i=1;i<=n;i++)
		if (!vis[i]) pre[i]=i;
		else pre[i]=pre[i-1];
	LL ans=inf;
	for (int i=1;i<=k;i++)
	{
		int s=0,now=0;
		while (now<n)
		{
			int ls=now;now=pre[std::min(n,now+i)];
			s++;
			if (now==ls) break;
		}
		if (now<n) continue;
		ans=std::min(ans,(LL)s*w[i]);
	}
	if (ans==inf) ans=-1;
	printf("%I64d",ans);
	return 0;
}