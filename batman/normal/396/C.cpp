#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=301*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

ll n,q,dis[N],strt[N],fnsh[N],num;
long long seg[2][4*N],lazy[2][4*N];
vector <ll> e[N];

void dfs(ll x,ll par=0)
{
	strt[x]=num++;
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par)
			dis[e[x][i]]=dis[x]+1,dfs(e[x][i],x);
	fnsh[x]=num;
}

void shift(ll id)
{
	ll l=id*2,r=l+1;
	seg[0][l]+=lazy[0][id];seg[0][l]%=MOD;
	seg[0][r]+=lazy[0][id];seg[0][r]%=MOD;
	seg[1][l]+=lazy[1][id];seg[1][l]%=MOD;
	seg[1][r]+=lazy[1][id];seg[1][r]%=MOD;
	lazy[0][l]+=lazy[0][id];lazy[0][l]%=MOD;
	lazy[0][r]+=lazy[0][id];lazy[0][r]%=MOD;
	lazy[1][l]+=lazy[1][id];lazy[1][l]%=MOD;
	lazy[1][r]+=lazy[1][id];lazy[1][r]%=MOD;
	lazy[0][id]=0;
	lazy[1][id]=0;
}

void update(ll ql,ll qr,ll xl,ll xr,ll id,long long x,long long k)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[0][id]+=x;seg[0][id]%=MOD;
		seg[1][id]+=k;seg[1][id]%=MOD;
		lazy[0][id]+=x;lazy[0][id]%=MOD;
		lazy[1][id]+=k;lazy[1][id]%=MOD;
		return ;
	}
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	shift(id);
	update(ql,qr,xl,mid,l,x,k);
	update(ql,qr,mid,xr,r,x,k);
}

long long query(ll q,ll xl,ll xr,ll id,ll v)
{
	if(xl>=xr)return 0;
	if(xl==xr-1)return (((seg[0][id]-dis[v]*seg[1][id])%MOD)+MOD)%MOD;
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	shift(id);
	if(q<mid)return query(q,xl,mid,l,v);
	return query(q,mid,xr,r,v);
}

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		ll x;
		scanf("%d",&x);
		e[x].push_back(i);
		e[i].push_back(x);
	}
	dfs(1);
	scanf("%d",&q);
	while(q--)
	{
		ll t;
		scanf("%d",&t);
		if(t==1)
		{
			ll v;
			long long x,k;
			scanf("%d%I64d%I64d",&v,&x,&k);
			x+=dis[v]*k;x%=MOD;
			//cout<<strt[v]<<" "<<fnsh[v]<<"\n";
			update(strt[v],fnsh[v],0,N,1,x,k);
		}
		if(t==2)
		{
			ll v;
			scanf("%d",&v);
			//cout<<strt[v]<<"\n";
			printf("%I64d\n",query(strt[v],0,N,1,v));
		}
	}
	return 0;
}