#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)101*1000)
#define K ((ll)20)

ll n,q,par[K][N],dis_w[N],dis[N],now=1,strt[N],fnsh[N],fen[N],ans,num_ver,inv_strt[N];
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
			dis_w[u.first]=dis_w[x]+u.second,
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

void add(ll x,bool p,bool ad)
{
	ll ex=((ad)?1:-1);
	if(p && !ad){num_ver--;update(strt[x],-1);}
	ll num=query(strt[x],fnsh[x]);
	if((num_ver-num && num) || !num_ver){if(p && ad)num_ver++,update(strt[x],1);return ;}
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
		ans+=(dis_w[v]-dis_w[x])*ex;
		if(p && ad)num_ver++,update(strt[x],1);
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
	add(v,0,ad);
	ans+=(dis_w[x]-dis_w[v])*ex;
	if(ad)num_ver++,update(strt[x],1);
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
    	ll v,u,w;
    	cin>>v>>u>>w;
    	e[v].push_back({u,w});
    	e[u].push_back({v,w});
	}
	pre_dfs(1);
	cin>>q;
	while(q--)
	{
		char c;
		ll x;
		cin>>c;
		if(c=='+'){cin>>x;add(x,1,1);}
		if(c=='-'){cin>>x;add(x,1,0);}
		if(c=='?')cout<<ans<<"\n";
	}
    return 0;
}