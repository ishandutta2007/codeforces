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
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,m,vis[N],a[N];
vll cycles,adj[N],rev[N];
string s[N];

void reset(){
	for(int i = 0; i < n*m; i++){
		adj[i].clear();
		rev[i].clear();
		vis[i] = 0;
	}
	cycles.clear();
}

ll bfs(ll ind, ll l){
	queue <ll> q;
	vll ct(l,0);
	vis[ind] = 0;
	q.push(ind);
	while(q.size()){
		ll x = q.front();
		q.pop();
		if(a[x] == 0) ct[vis[x]] |= 1;
		if(rev[x].size() == 0) continue;
		for(auto it : rev[x]){
			if(vis[it] == -1){
				vis[it] = (vis[x]+1)%l;
				q.push(it);
			}
		}
	}
	ll tct = 0;
	for(int i = 0; i < l; i++) tct += ct[i];
	return tct;
}

ll dfs(ll x, ll i){
	if(vis[x] == i) return x;
	if(vis[x] != 0) return -1;
	vis[x] = i;
	return dfs(adj[x][0],i);
}

ll find_length(ll x, ll st,bool flag){
	if(x == st && flag != 0) return 0;
	return find_length(adj[x][0],st,flag|1)+1;
}

void solve(){
	cin>>n>>m;
	string x;
	for(int i = 0; i < n; i++){
		cin>>x;
		for(int j = 0; j < m; j++){
			a[i*m+j] = x[j]-'0';
		}
	}
	for(int i = 0; i < n; i++) cin>>s[i];
	ll u,v;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			u = i*m+j;
			if(s[i][j] == 'U') v = u-m;
			if(s[i][j] == 'D') v = u+m;
			if(s[i][j] == 'L') v = u-1;
			if(s[i][j] == 'R') v = u+1;
			adj[u].pb(v);
			rev[v].pb(u);
		}
	}
	for(int i = 0; i < n*m; i++){
		if(vis[i] == 0){
			ll st = dfs(i,i+1);
			if(st != -1){
				cycles.pb(st);
			}
		}
	}
	for(int i = 0; i < n*m; i++) vis[i] = -1;
	ll no = cycles.size();
	ll ans = 0, res = 0;
	for(int i = 0; i < no; i++){
		ll l = find_length(cycles[i],cycles[i],0);
		res += bfs(cycles[i],l);
		ans += l;
	}
	cout<<ans<<" "<<res<<endl;
	reset();
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}