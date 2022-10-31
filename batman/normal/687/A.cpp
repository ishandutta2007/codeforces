#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=101*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)2e9);

ll n,m,mark[N];
vector <ll> e[N],v[2];

void dfs(ll x)
{
	v[mark[x]-1].push_back(x);
	for(int i=0;i<e[x].size();i++)
	{
		if(mark[e[x][i]]==mark[x]){cout<<-1;exit(0);}
		if(!mark[e[x][i]])
			mark[e[x][i]]=((mark[x]==1)?2:1),dfs(e[x][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(!mark[i])
			mark[i]=1,dfs(i);
	cout<<v[0].size()<<"\n";
	for(int i=0;i<v[0].size();i++)cout<<v[0][i]<<" ";
	cout<<"\n"<<v[1].size()<<"\n";
	for(int i=0;i<v[1].size();i++)cout<<v[1][i]<<" ";
			
	return 0;
}