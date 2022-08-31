#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio                ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f                     first                 
#define  s                     second
#define  endl                  "\n"
#define  pb                    push_back  
#define  mset(a,x)             memset(a,x,sizeof(a))             
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,m,a,b,c,val[N],pre[N];
ll vis[N],par[N];
vll adj[N];

void bfs(ll ind){
	queue <ll> q;
	vis[ind] = 0;
	par[ind] = 0;
	q.push(ind);
	while(q.size()){
		ll x = q.front();
		q.pop();
		for(auto it : adj[x]){
			if(vis[it] == -1){
				vis[it] = vis[x]+1;
				par[it] = x;
				q.push(it);
			}
		}
	}
}

void solve(){
	cin>>n>>m>>a>>b>>c;
	for(int i = 0; i < m; i++) cin>>val[i];
	for(int i = 0; i < m; i++){
		ll u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 0; i <= n; i++){
		vis[i] = -1;
		par[i] = -1;
	}
	bfs(a);
	ll x = b;
	ll visa[N];
	for(int i = 0; i <= n; i++){
		visa[i] = vis[i];
		vis[i] = -1;
		par[i] = -1;
	}
	bfs(b);
	ll visb[N];
	for(int i = 0; i <= n; i++){
		visb[i] = vis[i];
		vis[i] = -1;
		par[i] = -1;
	}
	bfs(c);
	sort(val,val+m);
	pre[0] = 0;
	pre[1] = val[0];
	for(int i = 2; i <= m; i++) pre[i] = pre[i-1]+val[i-1];
	ll ans = 1e18;
	for(int i = 1; i <= n; i++){
		ll sz = visa[i]+visb[i]+vis[i];
		if(sz <= m) ans = min(ans,pre[sz]+pre[visb[i]]);
	}
	if(ans == 1e18) ans = 0;
	cout<<ans<<endl;
	for(int i = 0; i <= m; i++) pre[i] = 0;
	for(int i = 0; i <= n; i++) adj[i].clear();
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
}