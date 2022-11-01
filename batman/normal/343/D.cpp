#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =501*1000;

ll n,q,strt[N],fnsh[N],now,seg1[4*N],seg2[4*N],max1,max2;
vector <ll> e[N];

void dfs(ll x,ll par=0)
{
	strt[x]=now++;
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par)
			dfs(e[x][i],x);
	fnsh[x]=now-1;
}

void build1(ll i,ll j,ll b,ll e,ll id,ll t)
{
	if (i>e || j<b)return ;
    if(i==b && j==e){seg1[id]=t;return ;}
    ll l=id<<1,r=l|1,mid=(e+b)>>1;
    build1(i,min(mid,j),b,mid,l,t);
	build1(max(i,mid+1),j,mid+1,e,r,t);
}

void build2(ll i,ll b,ll e,ll id,ll t)
{
	seg2[id]=t;
	if(b==e)return ;
	ll l=id<<1,r=l|1,mid=(e+b)>>1;
    if(i<=mid)build2(i,b,mid,l,t);
	else build2(i,mid+1,e,r,t);
}

void query1(ll i,ll b,ll e,ll id)
{
	max1=max(max1,seg1[id]);
	if(b==e)return ;
	ll l=id<<1,r=l|1,mid=(e+b)>>1;
    if(i<=mid)query1(i,b,mid,l);
	else query1(i,mid+1,e,r);
}


void query2(ll i,ll j,ll b,ll e,ll id)
{
	if (i>e || j<b)return ;
    if(i==b && j==e){max2=max(max2,seg2[id]);return ;}
    ll l=id<<1,r=l|1,mid=(e+b)>>1;
    query2(i,min(mid,j),b,mid,l);
	query2(max(i,mid+1),j,mid+1,e,r);
}

int main() 
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		scanf("%d%d",&v,&u);
		e[v].push_back(u);
		e[u].push_back(v);
	}
	dfs(1);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		ll ex,v;
		scanf("%d%d",&ex,&v);
		if(ex==1)build1(strt[v],fnsh[v],0,n-1,1,i);
		if(ex==2)build2(strt[v],0,n-1,1,i);
		if(ex==3)
		{
			max1=0,max2=0;
			query1(strt[v],0,n-1,1);
			query2(strt[v],fnsh[v],0,n-1,1);
			printf("%d\n",(max1>max2));
		}
	}
	
	return 0;
}