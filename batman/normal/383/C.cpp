#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =201*1000;

ll n,m,a[N],strt[N],fnsh[N],now,seg[4*N];
bool c[N],c2[N];
vector <ll> e[N];

void dfs(ll x,ll par=0)
{
	c2[now]=c[x];
	strt[x]=now++;
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=par)
			c[e[x][i]]=!c[x],dfs(e[x][i],x);
	fnsh[x]=now;
}

void update(ll ql,ll qr,ll xl,ll xr,ll id,ll val)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr){seg[id]+=((c2[xl])?val:-val);return ;}
	ll l=id*2,r=l+1,mid=(xl+xr)/2;
	update(ql,qr,xl,mid,l,val);
	update(ql,qr,mid,xr,r,val);
}

ll query(ll q,ll xl,ll xr,ll id)
{
	if(xl>=xr)return 0;
	//cout<<xl<<" "<<xr<<"\n";
	//if(xl==3 && xr==4)cout<<seg[id]<<"..............\n";
	if(xl==xr-1){return ((c2[xl])?1:-1)*seg[id];}
	ll l=id*2,r=l+1,mid=(xl+xr)/2,ex;
	//cout<<((c2[xl])?1:-1)*seg[id]<<"\n";
	if(q<mid)return query(q,xl,mid,l)+((c2[xl])?1:-1)*seg[id];
	return query(q,mid,xr,r)+((c2[xl])?1:-1)*seg[id];
}

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	dfs(1);
	while(m--)
	{
		ll t;
		cin>>t;
		if(t==1)
		{
			ll x,val;
			cin>>x>>val;
			update(strt[x],fnsh[x],0,N,1,((c[x])?val:-val));
		}
		if(t==2)
		{
			ll x;
			cin>>x;
			cout<<((c[x])?1:-1)*query(strt[x],0,N,1)+a[x]<<"\n";
		}
	}
	return 0;
}