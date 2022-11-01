#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (101*1000)
#define K (60)

ll n,m,par_[N],dis[N],par[N][K];
vector <ll> e[N];
vector <pair<ll,ll> > need,vec;
bool mark[N],used[N];

ll root(ll x){if(par_[x]<0)return x;return par_[x]=root(par_[x]);}

void dfs(ll x)
{
	mark[x]=1;
	for(int i=1;i<K;i++)
		par[x][i]=par[par[x][i-1]][i-1];
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i]])
			dis[e[x][i]]=dis[x]+1,par[e[x][i]][0]=x,dfs(e[x][i]);
	mark[x]=0;				
}

ll iPar(ll x,ll num)
{
	for(int i=0;num;i++,num/=2)
		if(num%2)x=par[x][i];
	return x;
}

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)par_[i]=-1;
	while(m--)
	{
		ll t;
		cin>>t;
		if(t==1)
		{
			ll x,y;
			cin>>x>>y;
			e[x].push_back(y);e[y].push_back(x);
			par_[x]=y;
		}
		if(t==2)
		{
			ll x;
			cin>>x;
			vec.push_back({root(x),x});
			//cout<<"2           "<<root(x)<<" "<<x<<"\n";
		}
		if(t==3)
		{
			ll x,y;
			cin>>x>>y;
			need.push_back({x,y});
		}
	}
	for(int i=1;i<=n;i++)
		if(!used[root(i)])
			e[N-1].push_back(root(i)),e[root(i)].push_back(N-1),used[root(i)]=1;
	dfs(N-1);
	for(int i=0;i<need.size();i++)
	{
		pair <ll,ll> a=vec[need[i].second-1];
		
		ll x=need[i].first;
		if(dis[x]>=dis[a.first] && dis[x]<=dis[a.second] && iPar(a.second,dis[a.second]-dis[x])==x)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}