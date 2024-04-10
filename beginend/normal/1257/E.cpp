#include<bits/stdc++.h>

const int N=200005;

int k1,k2,k3,n,f[N],g[N],mn[N];
bool vis1[N],vis2[N],vis3[N];

int main()
{
	scanf("%d%d%d",&k1,&k2,&k3);
	n=k1+k2+k3;
	for (int i=1,x;i<=k1;i++) scanf("%d",&x),vis1[x]=1;
	for (int i=1,x;i<=k2;i++) scanf("%d",&x),vis2[x]=1;
	for (int i=1,x;i<=k3;i++) scanf("%d",&x),vis3[x]=1;
	f[0]=k1;
	for (int i=1;i<=n;i++)
		if (vis1[i]) f[i]=f[i-1]-1;
		else if (vis2[i]) f[i]=f[i-1]+1;
		else f[i]=f[i-1];
	g[n+1]=mn[n+1]=k3;
	for (int i=n;i>=1;i--)
		if (vis3[i]) g[i]=g[i+1]-1;
		else if (vis2[i]) g[i]=g[i+1]+1;
		else g[i]=g[i+1];
	for (int i=n;i>=1;i--) mn[i]=std::min(g[i],mn[i+1]);
	int ans=n+1;
	for (int i=0;i<=n;i++) ans=std::min(ans,f[i]+mn[i+1]);
	printf("%d\n",ans);
	return 0;
}