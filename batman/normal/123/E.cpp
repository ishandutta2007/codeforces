#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define N ((ll)101*1000)

ll n,a[N],b[N],sum1,sum2,sz[N],num[N];
ld ans;
vector <ll> e[N];

void dfs(ll x,ll par=0)
{
	sz[x]=1;num[x]=a[x];
	for(auto u:e[x])
		if(u!=par)
		{
			dfs(u,x);
			sz[x]+=sz[u];
			num[x]+=num[u];
			ans+=((ld)b[x]/sum2)*((ld)num[u]/sum1)*sz[u];
		}
	ans+=((ld)b[x]/sum2)*((ld)(sum1-num[x])/sum1)*(n-sz[x]);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i],sum1+=a[i],sum2+=b[i];
	dfs(1);
	cout<<fixed<<setprecision(14)<<ans<<"\n";
	return 0;
}