#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,h[N],q[N],d[N],s[N],vis[N],sg[N];
vector<int>g[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&h[i]);
	for(int i=1;i<=m;i++){int u,v;scanf("%d%d",&u,&v);g[u].push_back(v);d[v]++;}
	int ql=1,qr=0;
	for(int i=1;i<=n;i++)if(!d[i])q[++qr]=i;
	while(ql<=qr)
	{
		int x=q[ql++];
		for(int i=0;i<g[x].size();i++)if(!--d[g[x][i]])q[++qr]=g[x][i];
	}
	for(int i=n;i;i--)
	{
		int x=q[i];
		for(int j=0;j<g[x].size();j++)vis[sg[g[x][j]]]=i;
		while(vis[sg[x]]==i)sg[x]++;s[sg[x]]^=h[x];
	}
	for(int i=n;~i;i--)if(s[i])
	{
		int x;for(int j=1;j<=n;j++)if(sg[j]==i&&h[j]>(s[i]^h[j]))x=j;h[x]^=s[sg[x]];
		for(int j=0;j<g[x].size();j++)h[g[x][j]]^=s[sg[g[x][j]]],s[sg[g[x][j]]]=0;
		puts("WIN");for(int j=1;j<=n;j++)printf("%d ",h[j]);return 0;
	}
	puts("LOSE");
	return 0;
}