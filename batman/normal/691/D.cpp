#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1001*1000)
#define MOD ((ll)1e9+7)

ll n,m,a[N],par[N],ans[N];
vector <ll> b[N],c[N];
ll root(ll x){if(par[x]==-1)return x;return par[x]=root(par[x]);}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],par[i]=-1;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		if(root(u)!=root(v))par[root(v)]=root(u);
	}
	for(int i=1;i<=n;i++)
		b[root(i)].push_back(i),c[root(i)].push_back(a[i]);
	for(int i=1;i<=n;i++)
		if(par[i]==-1)
		{
			sort(c[i].begin(),c[i].end(),greater <ll>());
			for(int j=0;j<c[i].size();j++)ans[b[i][j]]=c[i][j];
		}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}