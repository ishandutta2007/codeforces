#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Os")
 
#define F first
#define S second
#define pb push_back
#define SZ(x) (int)(x.size())
#define all(x) x.begin(),x.end()
 
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
 
const ll maxn=2e3+10, LG=30, mod=1e9+7, inf=1e18;
 
ll n;
ll c[maxn];
vector<ll> g[maxn];
 
ll val[maxn];
 
ll st[maxn],ft[maxn],tt=0;
ll ras[maxn];
 
void dfs(ll v,ll p=0){
	st[v]=++tt;
	ras[tt]=v;
	for(auto u:g[v])if(u!=p) dfs(u,v);
	ft[v]=tt;
 
	vector<ll> vv;
	for(int i=st[v]+1;i<=ft[v];i++) vv.pb(val[ras[i]]);
	sort(all(vv));
	if(SZ(vv)<c[v]){
		cout<<"NO"<<endl;
		exit(0);
	}
 
	if(c[v])
		val[v]=vv[c[v]-1]+1;
	else val[v]=1;
 
	for(int i=1;i<=n;i++)
		if(val[i]>=val[v] && i!=v)
			val[i]++;
 
	//cout<<v<<endl; for(int i=1;i<=n;i++) cout<<i<<' '<<val[i]<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	ll root;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll p; cin>>p>>c[i];
		if(p==0){
			root=i;
			continue;
		}
		g[i].pb(p);
		g[p].pb(i);
	}
 
	dfs(root);
 
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++) cout<<val[i]<<' ';
 
	return 0;
}