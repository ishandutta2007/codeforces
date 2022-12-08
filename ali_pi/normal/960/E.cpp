#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2E5+5;
const int MOD=1E9+7;
int n,x,y,f[N],son[N];
vector <int> G[N];
ll ans,v[N];

void dfs(int x,int fa)
{
	int y;
	f[x]=son[x]=1; ans=(ans+v[x]*n)%MOD;
	for (int i=0;i<G[x].size();i++) if ((y=G[x][i])!=fa)
	{
		dfs(y,x);
		son[x]+=son[y]; f[x]-=f[y];
		ans=(ans+v[x]*-f[y]%MOD*(n-son[y]))%MOD;
	}
}

void dfs2(int x,int fa,int tot)
{
	ans=(ans+v[x]*tot%MOD*son[x]%MOD)%MOD;
	for (int i=0;i<G[x].size();i++) if ((y=G[x][i])!=fa)
	{
		dfs2(y,x,-(tot+f[x]+f[y]));
	}
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>v[i];
	for (int i=1;i<n;i++)
	{
		cin>>x>>y;
		G[x].push_back(y); G[y].push_back(x);
	}
	dfs(1,0);
	dfs2(1,0,0);
	cout<<(ans+MOD)%MOD;
}