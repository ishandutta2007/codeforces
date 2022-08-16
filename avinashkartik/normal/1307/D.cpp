#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an lleratcive problem - use endl
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
#define  f                     first                 
#define  s                     second
#define  endl                  "\n"
#define  pb                    push_back           
 
const ll   N     =  2e+5+5;
const ll   MAXN  =  1e+9;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n,m,k,sp[N],u,v,st[N],en[N],vis[N];
vll adj[N];
vpll ch;
queue <ll> q;

void bfsst(){
	q.push(1);
	vis[1] = 1;
	st[1] = 0;
	while(q.size()){
		ll x = q.front();q.pop();
		for(auto it : adj[x]){
			if(!vis[it]){
				vis[it] = 1;
				st[it] = st[x]+1;
				q.push(it);
			}
		}
	}
}

void bfsen(){
	q.push(n);
	vis[n] = 1;
	en[n] = 0;
	while(q.size()){
		ll x = q.front();q.pop();
		for(auto it : adj[x]){
			if(!vis[it]){
				vis[it] = 1;
				en[it] = en[x]+1;
				q.push(it);
			}
		}
	}
}

int main(){
    fastio;
    cin>>n>>m>>k;

    for(int i = 0; i < k; i++) cin>>sp[i];
    for(int i = 0; i < m; i++){
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    bfsst();
    fill_n(vis,n+5,0);
    bfsen();

    for(int i = 0;i < k; i++){
    	ll j = sp[i];
    	ll x = st[j]-en[j];
    	ch.pb({x,en[j]});
    	//cout<<st[j]<<" "<<en[j]<<endl;
    }

    sort(ch.begin(), ch.end());

    ll x = ch[0].s+ch[0].f;
    ll ans = 0;
    for(int i = 1;i < k; i++){
    	ans = max(ans,x+ch[i].s);
    	x = max(x,ch[i].s+ch[i].f);
    	//cout<<ans<<endl;
    }

    cout<<min(ans+1,st[n])<<endl;
}