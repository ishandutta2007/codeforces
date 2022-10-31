#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=101*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

ll n,m,c[N],sz[N],cnt[N],cnt2[N],ans[N];
set <ll> st;
vector <ll> e[N];
vector <pair<ll,ll> > q[N];
bool big[N];

void pre_dfs(ll x,ll par=0)
{
	sz[x]=1;
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par)
			pre_dfs(e[x][i],x),sz[x]+=sz[e[x][i]];
}

void add(ll x,ll par,ll num)
{
	cnt2[cnt[c[x]]]-=c[x];
	if(cnt2[cnt[c[x]]]==0)st.erase(cnt[c[x]]);
	cnt[c[x]]+=num;
	if(cnt2[cnt[c[x]]]==0)st.insert(cnt[c[x]]);
	cnt2[cnt[c[x]]]+=c[x];
	
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par && !big[e[x][i]])
			add(e[x][i],x,num);
}

void dfs(ll x,ll par=0,bool mark=0)
{
	ll big_child=0;
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par && sz[e[x][i]]>sz[big_child])
			big_child=e[x][i];
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par && e[x][i]!=big_child)
			dfs(e[x][i],x);
	if(big_child)dfs(big_child,x,1);
	big[big_child]=1;
	add(x,par,1);
	ans[x]=cnt2[*st.rbegin()];
	big[big_child]=0;
	if(!mark)add(x,par,-1);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	pre_dfs(1);
	dfs(1);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}