#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int n,m,q,s[N],sz[N],w[N];long long ans;
vector<int>g[N],e[N];
int main()
{
	scanf("%d%d",&n,&m);for(int i=1;i<=n;i++)w[i]=i;
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	for(int i=1;i<=n;i++)for(int j=0;j<g[i].size();j++)if(w[g[i][j]]<w[i])s[i]++;else e[i].push_back(g[i][j]);
	for(int i=1;i<=n;i++)sz[i]=g[i].size(),ans+=1ll*s[i]*(sz[i]-s[i]);
	scanf("%d",&q);printf("%lld\n",ans);
	for(int i=1;i<=q;i++)
	{
		int x;scanf("%d",&x);
		for(auto t:e[x])
		{
			e[t].push_back(x);ans-=1ll*s[t]*(sz[t]-s[t]);
			s[t]--;ans+=1ll*s[t]*(sz[t]-s[t]);
		}
		e[x].clear();ans-=1ll*s[x]*(sz[x]-s[x]);
		s[x]=sz[x];w[x]=n+i;printf("%lld\n",ans);
	}
	return 0;
}