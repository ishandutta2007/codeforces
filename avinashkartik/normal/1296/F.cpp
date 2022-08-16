#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second
#define  endl                  "\n"

const ll   N     =  5005;
const ll   MAX   =  1e17;
const ll   mod   =  1e+7+3;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,u[N],v[N],pp[N],vis[N],val[N][N],f=1,q,p,minn,u1,v1;
ll prev;
vll adj[N];
vpll vp;

void dfs(ll x){
	if(!vis[x]){
		vis[x] = 1;
		for(auto it : adj[x]){
			if(it == ::prev){
				val[it][x] = max(p,val[it][x]);
				val[x][it] = max(p,val[x][it]);
				::prev = x;
				break;
			}
			dfs(it);
			if(it == ::prev){
				val[it][x] = max(p,val[it][x]);
				val[x][it] = max(p,val[x][it]);
				::prev = x;
				break;
			}
		}
	}
}

void ch(ll x){
	if(!vis[x]){
		vis[x] = 1;
		for(auto it : adj[x]){
			if(it == ::prev){
				minn = min(val[it][x],minn);
				::prev = x;
				//cout<<it<<" "<<x<<" "<<val[it][x]<<endl;
				break;
			}
			ch(it);
			if(it == ::prev){
				minn = min(val[it][x],minn);
				::prev = x;
				//cout<<it<<" "<<x<<" "<<val[it][x]<<endl;
				break;
			}
		}
	}
}

int main() {
	cin>>n;
	for(int i = 0; i < n-1; i++){
		cin>>u1>>v1;
		vp.push_back({u1,v1});
		adj[v1].push_back(u1);
		adj[u1].push_back(v1);
	}
	cin>>q;
	for(int i = 0; i < q; i++){
		cin>>u[i]>>v[i]>>pp[i];
		p = pp[i];
		::prev = v[i];
		fill_n(vis,N,0);
		dfs(u[i]);
	}
	for(int i = 0; i < q; i++){
		::prev = v[i];
		fill_n(vis,N,0);
		minn = MAX;
		ch(u[i]);
		//cout<<minn<<endl;
		if(minn != pp[i]) f = 0;  
	}
	if(f == 0) cout<<-1;
	else{
		for(auto it : vp)cout<<max(1ll,val[it.x][it.y])<<" ";
	}
	cout<<endl;
}