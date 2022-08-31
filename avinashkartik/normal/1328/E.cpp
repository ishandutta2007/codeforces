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

ll n;
ll parent[N],level[N],visited[N];
const ll LEVEL=log2(N)+1;
ll st[N][LEVEL];
vll v[N];

void findparent(ll n, ll prev){
	visited[n] = 1;
	parent[n] = prev;
	if(prev != -1)
		level[n] = level[prev]+1;
	for(ll i = 0; i < v[n].size(); i++){
		if(visited[v[n][i]] == 0){
			findparent(v[n][i],n);
		}
	}
}
 
void clearall(){
	for(ll i = 0; i < N; i++){
		parent[i] = -1;
		level[i] = -1;
		visited[i] = 0;
		for(ll j = 0; j < LEVEL; j++)
			st[i][j] = -1;
	}
}
 
void fillst(ll n){
	clearall();
	ll i,j;
	findparent(1,-1);
	for(j = 0; j < LEVEL; j++){
		for(i = 1; i <= n; i++){
			if(j == 0)
				st[i][j] = parent[i];
			if(st[i][j-1] != -1){
				st[i][j] = st[st[i][j-1]][j-1];
			}
		}
	}
}
 
ll lca(ll x, ll y){
	if(level[y] < level[x])
		swap(x,y);
	ll diff = level[y]-level[x];
	for(ll i = 0;i < LEVEL; i++){
		// Checks all set bits in diff
		if((diff>>i)&1){
			y = st[y][i];
		}
	}
	if(x == y)
		return x;
	for(ll i = LEVEL-1; i >= 0; i--){
		// First highest of x and y that are unequal
		if(st[x][i] != -1 && st[x][i] != st[y][i]){
			x = st[x][i];
			y = st[y][i];
		}
	}
	return st[x][0];
}

int main(){
    fastio;
    ll q;
	cin>>n>>q;
	for(int i = 0; i < n-1; i++){
		ll ui,vi;
		cin>>ui>>vi;
		v[ui].pb(vi);
		v[vi].pb(ui);
	}
	fillst(n);
	ll a[N],maxlv,x;
	while(q--){
		cin>>x;
		maxlv = 1;
		ll f = 0;
		for(int i = 0; i < x; i++){
			cin>>a[i];
			if(level[a[i]] > level[maxlv])
				maxlv = a[i];
		}
		for(int i = 0; i < x; i++){
			ll LCA = lca(maxlv,a[i]);
			if(LCA != a[i] && LCA != parent[a[i]]){
				f = 1;
				break;
			}
		}
		if(f == 1) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}