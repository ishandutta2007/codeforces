#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define K ((ll)60)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,m,ans,prt_xr[N],cnt_bit[2][K],cnt_comp;
vector <pair<ll,ll> > e[N];
vector <ll> cycles;
bool mark[N];

ll mul(ll x,ll y){return ((x%MOD)*(y%MOD))%MOD;}

void dfs_cycle(ll x,ll par=0)
{
	for(int i=0;i<K;i++)cnt_bit[((prt_xr[x]&(1LL<<i))!=0)][i]++;
	mark[x]=1;cnt_comp++;
	for(auto u:e[x])
	{
		if(u.first==par)continue;
		if(mark[u.first])cycles.push_back((u.second^prt_xr[x]^prt_xr[u.first]));
		else prt_xr[u.first]=(prt_xr[x]^u.second),dfs_cycle(u.first,x);
	}
}

ll eliminate()
{
	ll res=0,cnt=1;
	bool one[K]={};
	for(int i=0;i<K;i++)
	{
		ll id=-1;
		for(int j=0;j<cycles.size();j++)
			if((cycles[j]&(1LL<<i)))
				id=j;
		if(id==-1)continue;
		for(int j=0;j<K;j++)one[j]|=((cycles[id]&(1LL<<j))!=0);
		cnt*=2;cnt%=MOD;
		ll ex=cycles[id];
		for(int j=0;j<cycles.size();j++)
			if((cycles[j]&(1LL<<i)))
				cycles[j]^=ex;
	}
	for(int i=0;i<K;i++)
	{
		if(one[i])res+=mul((1LL<<i),mul(cnt_comp*(cnt_comp-1)/2,mul(cnt,tavan(2,MOD-2)))),res%=MOD;
		else res+=mul((1LL<<i),mul(cnt,mul(cnt_bit[0][i],cnt_bit[1][i]))),res%=MOD;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		e[v].push_back({u,w});
		e[u].push_back({v,w});
	}
	for(int i=1;i<=n;i++)
		if(!mark[i])
		{
			cnt_comp=0;
			cycles.clear();
			memset(cnt_bit,0,sizeof cnt_bit);
			dfs_cycle(i);
			ans+=eliminate();ans%=MOD;
		}
	cout<<ans;
	return 0;
}