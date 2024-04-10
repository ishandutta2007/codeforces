#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)101*1000)
#define K ((ll)17)

ll n,k,par[K][N],dis_w[N],dis[N],now=1,strt[N],fnsh[N],fen[N],ans,num_ver,inv_strt[N];
vector <pair<ll,ll> > e[N];

void update(ll x,ll num){for(;x<now;x+=x&-x)fen[x]+=num;}
ll ask(ll x){ll res=0;for(;x>0;x-=x&-x)res+=fen[x];return res;}
ll query(ll l,ll r){return ask(r-1)-ask(l-1);}

void pre_dfs(ll x)
{
	inv_strt[now]=x;
	strt[x]=now++;
	for(int i=1;i<K;i++)par[i][x]=par[i-1][par[i-1][x]];
	for(auto u:e[x])
		if(u.first!=par[0][x])
			dis[u.first]=dis[x]+1,
			dis_w[u.first]=dis_w[x]+1,
			par[0][u.first]=x,
			pre_dfs(u.first);
	fnsh[x]=now;
}

ll iPar(ll x,ll num)
{
	for(int i=0;i<K;i++)
		if((num&(1<<i)))
			x=par[i][x];
	return x;
}

void add(ll x,bool p)
{
	ll num=query(strt[x],fnsh[x]);
	if(num_ver==0)ans++;
	if((num_ver-num && num) || !num_ver){if(p)num_ver++,update(strt[x],1);return ;}
	if(num)
	{
		ll l=strt[x],r=fnsh[x];
		while(l<r-1)
		{
			ll mid=(l+r)/2;
			if(query(l,mid))r=mid;
			else l=mid;
		}
		ll v=inv_strt[l];
		l=-1,r=dis[v]-dis[x];
		while(l<r-1)
		{
			ll mid=(l+r)/2,u=iPar(v,mid);
			if(query(strt[u],fnsh[u])==num)r=mid;
			else l=mid;
		}
		v=iPar(v,r);
		ans+=dis_w[v]-dis_w[x];
		if(p)num_ver++,update(strt[x],1);
		return ;
	}
	ll l=0,r=dis[x];
	while(l<r-1)
	{
		ll mid=(l+r)/2,u=iPar(x,mid);
		if(query(strt[u],fnsh[u]))r=mid;
		else l=mid;
	}
	ll v=iPar(x,r);
	add(v,0);
	ans+=dis_w[x]-dis_w[v];
	num_ver++;
	update(strt[x],1);
}

void rem(ll x,bool p)
{
	if(p){num_ver--;update(strt[x],-1);}
	ll num=query(strt[x],fnsh[x]);
	if((num_ver-num && num) || !num_ver){;return ;}
	if(num)
	{
		ll l=strt[x],r=fnsh[x];
		while(l<r-1)
		{
			ll mid=(l+r)/2;
			if(query(l,mid))r=mid;
			else l=mid;
		}
		ll v=inv_strt[l];
		l=-1,r=dis[v]-dis[x];
		while(l<r-1)
		{
			ll mid=(l+r)/2,u=iPar(v,mid);
			if(query(strt[u],fnsh[u])==num)r=mid;
			else l=mid;
		}
		v=iPar(v,r);
		ans-=dis_w[v]-dis_w[x];
		return ;
	}
	ll l=0,r=dis[x];
	while(l<r-1)
	{
		ll mid=(l+r)/2,u=iPar(x,mid);
		if(query(strt[u],fnsh[u]))r=mid;
		else l=mid;
	}
	ll v=iPar(x,r);
	rem(v,0);
	ans-=dis_w[x]-dis_w[v];
}

bool check(ll x)
{
	bool flg=0;
	for(int i=1;i<=x;i++)add(i,1);
	if(ans<=k)flg=1;
	for(int i=x+1;i<=n;i++)
	{
		add(i,1);
		rem(i-x,1);
		if(ans<=k)flg=1;
	}
	for(int i=n;i>n-x;i--)rem(i,1);
	ans=0;
	return flg;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n-1;i++)
    {
    	ll v,u;
    	cin>>v>>u;
    	e[v].push_back({u,0});
    	e[u].push_back({v,0});
	}
	pre_dfs(1);
	//cout<<check(4);
	ll l=1,r=n+1;
	while(l<r-1)
	{
		ll mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
    return 0;
}