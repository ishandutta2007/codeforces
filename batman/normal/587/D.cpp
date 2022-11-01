#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)501*1000)
#define M ((ll)501*1000)

ll n,m,c[N],t[N],num,ans[N];
vector <pair<ll,ll> > _e[N];
vector <ll> e2[M];

bool mark[M];
vector <ll> e[M],er[M],topol;
ll topol_num[M],comp[M],cnt_comp;

void add(ll x,ll y){e2[x^1].push_back(y);e2[y^1].push_back(x);}

void dfs(ll x)
{
	mark[x]=1;
	for(auto u:e[x])
		if(!mark[u])
			dfs(u);
	topol.push_back(x);
	topol_num[x]=topol.size();
}

void dfs2(ll x)
{
	comp[x]=cnt_comp;
	for(auto u:er[x])
		if(!comp[u])
			dfs2(u);
}

bool check(ll x,bool exx=0)
{
	topol.clear();memset(mark,0,sizeof mark);
	memset(comp,0,sizeof comp);cnt_comp=1;
	
	for(int i=0;i<2*num;i++)e[i]=e2[i];
	for(int i=0;i<m;i++)if(t[i]>x)e[2*i+1].push_back(2*i);
	for(int i=0;i<2*num;i++)if(!mark[i])dfs(i);
	reverse(topol.begin(),topol.end());
	for(int i=0;i<2*num;i++)er[i].clear();
	for(int i=0;i<2*num;i++)for(auto u:e[i])er[u].push_back(i);
	for(auto u:topol)if(!comp[u])dfs2(u),cnt_comp++;
	for(int i=0;i<m;i++)
	{
		if(comp[2*i]==comp[2*i+1])return 0;
		if(comp[2*i+1]>comp[2*i])ans[i]=1;
		else ans[i]=0;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;num=m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u>>c[i]>>t[i];
		_e[v].push_back({c[i],i});
		_e[u].push_back({c[i],i});
	}
	for(int i=1;i<=n;i++)
	{
		if(!_e[i].size())continue;
		bool flg=0;
		ll id;
		sort(_e[i].begin(),_e[i].end());
		for(int j=1;j<_e[i].size();j++)
		{
			if(_e[i][j].first==_e[i][j-1].first && flg)return cout<<"No",0;
			if(_e[i][j].first==_e[i][j-1].first)flg=1,id=j;
		}
		if(flg)add(2*_e[i][id].second+1,2*_e[i][id-1].second+1);
		ll lst=_e[i][0].second;
		for(int j=1;j<(ll)_e[i].size();j++)
		{
			ll ex=_e[i][j].second;
			add(2*lst,2*ex);add(2*ex,2*num+1);add(2*lst,2*num+1);
			lst=num++;
		}
	}
	ll l=-1,r=(ll)1e9+1;
	while(l<r-1)
	{
		ll mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	if(r==(ll)1e9+1)return cout<<"No",0;
	check(r,1);
	ll res=0;
	for(int i=0;i<m;i++)res+=ans[i];
	cout<<"Yes\n"<<r<<" "<<res<<"\n";
	for(int i=0;i<m;i++)if(ans[i])cout<<i+1<<" ";
	return 0;
}