#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
vector <pair<int,pair<int,int> > > e[200005];
vector <int> f[200005];
int ans[200005],inv[200005],now[200005],mn[200005];
inline void ins(int x,int y)
{
	int k=x;
	for(auto t:f[x])
	{
		while(k%t==0) k/=t,now[t]+=y;
		mn[t]=min(mn[t],now[t]);
	}
}
inline void dfs(int u,int f)
{
	for(auto X:e[u])
	{
		int v=X.first,x=X.second.first,y=X.second.second;
		if(v==f) continue;
		ins(y,1),ins(x,-1),ans[v]=ans[u]*y%mod*inv[x]%mod;
		dfs(v,u);
		ins(x,1),ins(y,-1);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	inv[1]=1;
	for(int i=2;i<=200000;i++)
	{
		if(!f[i].size()) for(int j=i;j<=200000;j+=i)
			f[j].push_back(i);
	}
	for(int i=2;i<=200000;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) now[i]=mn[i]=0,e[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v,x,y;
			cin >> u >> v >> x >> y;
			e[u].push_back({v,{x,y}});
			e[v].push_back({u,{y,x}});
		}
		ans[1]=1;
		dfs(1,0);
		int p=1;
		for(int i=1;i<=n;i++)
			while(mn[i]<0) p*=i,++mn[i],p%=mod;
		for(int i=1;i<=n;i++)
			ans[i]*=p,ans[i]%=mod;
		int s=0;
		for(int i=1;i<=n;i++) s=(s+ans[i])%mod;
		cout << s << "\n";
	}
	return 0;
}