// I'm back ^_^
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((101*1000))

ll n,m,strt[N],fnsh[N],num,ans[N],lazy[4*N];
vector <ll> e[N],qu[N];
pair<ll,ll> seg[4*N];

void build(ll xl,ll xr,ll id)
{
	seg[id].second=xr-xl;
	if(xl==xr-1)return;
	build(xl,xl+xr>>1,id*2);
	build(xl+xr>>1,xr,id*2+1);
}

void shift(ll id)
{
	seg[id*2].first+=lazy[id];
	lazy[id*2]+=lazy[id];
	seg[id*2+1].first+=lazy[id];
	lazy[id*2+1]+=lazy[id];
	lazy[id]=0;
}

void update(ll ql,ll qr,ll xl,ll xr,ll id,ll val)
{
	if(xr<=ql || qr<=xl)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[id].first+=val;
		lazy[id]+=val;
		return ;
	}
	shift(id);
	update(ql,qr,xl,xl+xr>>1,id*2,val);
	update(ql,qr,xl+xr>>1,xr,id*2+1,val);
	seg[id]={min(seg[id*2].first,seg[id*2+1].first),0};
	if(seg[id*2].first==seg[id].first)seg[id].second+=seg[id*2].second;
	if(seg[id*2+1].first==seg[id].first)seg[id].second+=seg[id*2+1].second;
}

void pre_dfs(ll x,ll par=-1)
{
	strt[x]=num++;
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par)
			pre_dfs(e[x][i],x);
	fnsh[x]=num;
}

void dfs(ll x,ll par=-1)
{
	for(int i=0;i<qu[x].size();i++)update(strt[qu[x][i]],fnsh[qu[x][i]],0,n,1,1);
	if(seg[1].first==0)ans[x]=max(n-seg[1].second-1,0ll);
	else ans[x]=n-1;
	//cout<<x<<" "<<seg[1].first<<" "<<seg[1].second<<"\n";
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par)
			dfs(e[x][i],x);
	for(int i=0;i<qu[x].size();i++)update(strt[qu[x][i]],fnsh[qu[x][i]],0,n,1,-1);	
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    
    cin>>n>>m;
    for(int i=0;i<n-1;i++)
    {
    	ll v,u;
    	cin>>v>>u;v--;u--;
    	e[v].push_back(u);
    	e[u].push_back(v);
	}
	pre_dfs(0);
	while(m--)
	{
		ll x,y;
		cin>>x>>y;x--;y--;
		qu[x].push_back(x);qu[x].push_back(y);
		qu[y].push_back(x);qu[y].push_back(y);
	}
	build(0,n,1);
	dfs(0);
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    return 0;
}