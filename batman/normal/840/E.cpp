#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)51*1000)
#define P ((ll)8)
#define K ((ll)(1<<P))

struct Node{ll ch[2],maxi;};

ll n,q,c[N],dis[N],par[N],par2[N],max_val[K][N];
vector <ll> e[N];
Node a[K*8];
ll num;

void add(ll x,ll y)
{
	ll now=0;
	for(int i=P-1;i>=0;i--)
	{
		bool p=(x&(1<<i));
		if(a[now].ch[p]==-1)
			a[now].ch[p]=num,
			a[num].ch[0]=a[num].ch[1]=a[num].maxi=-1,
			num++;
		now=a[now].ch[p];
		a[now].maxi=max(a[now].maxi,y);
	}
}

ll get(ll x)
{
	ll now=0,res=0;
	for(int i=P-1;i>=0;i--)
	{
		bool p=(x&(1<<i));
		if(a[now].ch[!p]==-1)
			now=a[now].ch[p];
		else now=a[now].ch[!p],res+=(1<<i);
	}
	return res*K+a[now].maxi;
}

void dfs(ll x)
{
	for(auto u:e[x])
		if(u!=par[x])
			par[u]=x,
			dis[u]=dis[x]+1,
			dfs(u);
	a[0].ch[0]=a[0].ch[1]=a[0].maxi=-1;
	num=1;
	ll x2=x;
	for(int i=0;i<K;i++)
	{
		if(x2==0)break;
		add(c[x2]/K,(c[x2]^i)%K);
		x2=par[x2];
	}
	par2[x]=x2;
	for(int i=0;i<K;i++)
		max_val[i][x]=get(i);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	dis[1]=1;dfs(1);
	while(q--)
	{
		ll v,u;
		cin>>v>>u;
		ll d=0,res=0;
		while(dis[u]-K-1>=dis[v])
		{
			res=max(res,max_val[d][u]);
			d++;
			u=par2[u];
		}
		d*=K;
		while(dis[u]>=dis[v])res=max(res,(c[u]^d)),u=par[u],d++;
		cout<<res<<"\n";
	}
	return 0;
}