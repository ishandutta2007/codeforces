#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
#define ld long double
#define N ((int)301*1000)
#define INF ((ll)1e15)

int n,res[N];
ll s[N];
ll mini[4*N],lazy[4*N];


void build(int xl=0,int xr=n,int id=1)
{
	if(xl==xr-1)
	{
		mini[id]=1LL*xl*(xl+1)/2;
		return ;
	}
	int mid=(xl+xr)/2;
	build(xl,mid,id*2);
	build(mid,xr,id*2+1);
	mini[id]=min(mini[id*2],mini[id*2+1]);
}

void shift(int id)
{
	mini[id*2]+=lazy[id];
	lazy[id*2]+=lazy[id];
	mini[id*2+1]+=lazy[id];
	lazy[id*2+1]+=lazy[id];
	lazy[id]=0;
}

int query(ll q,int xl=0,int xr=n,int id=1)
{
	if(xl==xr-1)
	{
		if(mini[id]!=q)cout<<1/0;
		mini[id]=INF;
		lazy[id]=0;
		return xl+1;
	}
	int mid=(xl+xr)/2;
	shift(id);
	if(mini[id*2+1]<=q)
		return query(q,mid,xr,id*2+1);
	int res=query(q,xl,mid,id*2);
	mini[id*2+1]-=res;
	lazy[id*2+1]-=res;
	return res;
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	build();
	for(int i=n-1;i>=0;i--)
		res[i]=query(s[i]);
	for(int i=0;i<n;i++)cout<<res[i]<<" ";
	return 0;
}