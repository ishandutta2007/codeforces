#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)


ll n,m,par[N],ans,a[N];
vector <pair <ll,pair<ll,ll> > > ed;

ll root(ll x){if(par[x]<0)return x;return par[x]=root(par[x]);}
void merge(ll x,ll y){x=root(x);y=root(y);par[y]+=par[x];par[x]=y;}


int main()
{ 
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
	for(int i=1;i<=n;i++)par[i]=-1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		ed.push_back({min(a[u],a[v]),{u,v}});
	}
	sort(ed.begin(),ed.end());
	for(int i=(ll)ed.size()-1;i>=0;i--)
	{
	    ll u=ed[i].second.first;
    	ll v=ed[i].second.second;
	    ll w=ed[i].first;
    	if(root(u)!=root(v))
		{	
			ans+=(-par[root(u)])*(-par[root(v)])*w;
			merge(u,v);
		}
	}
	cout<<fixed<<setprecision(12)<<(ld)ans*2/(ld)n/(ld)(n-1);
    return 0;
}