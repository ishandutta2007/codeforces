#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;  
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());          
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  5e3+8;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, n1, n2, n3, vis[N], no = 0, dp[N][N], ans[N];
vll adj[N], v[N][2];

bool mem(int ind, int left){
	if(ind == no) return dp[ind][left] = (left == 0);
	if(dp[ind][left] != -1) return dp[ind][left];
	dp[ind][left] = mem(ind+1,left-v[ind][0].size()) | mem(ind+1,left-v[ind][1].size());
	return dp[ind][left];
}

void bt(int ind, int left){
	if(ind == no) return;
	if(dp[ind+1][left-v[ind][0].size()] == 1){
		for(auto it : v[ind][0]) ans[it] = 2;
		bt(ind+1,left-v[ind][0].size());
	}
	else{
		for(auto it : v[ind][1]) ans[it] = 2;
		bt(ind+1,left-v[ind][1].size());
	}
}

void dfs(ll x, ll p, int f){
	if(vis[x] != -1 and vis[x] != f){
		deb1("NO")
		exit(0);
	}
	if(vis[x] != -1) return;
	v[no][f].pb(x);
	vis[x] = f;
	for(auto it : adj[x]){
		if(it == p) continue;
		dfs(it,x,f^1);
	}
}

void solve(){
	mset(vis,-1);
	mset(dp,-1);
	cin>>n>>m>>n1>>n2>>n3;
	for(int i = 1; i <= m; i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 1; i <= n; i++){
		if(vis[i] == -1){
			dfs(i,0,0);
			no++;
		}
	}
	bool f = mem(0,n2);
	if(f == 0){
		deb1("NO")
		return;
	}
	deb1("YES")
	bt(0,n2);
	for(int i = 1,j = 0; i <= n; i++){
		if(ans[i] == 2) cout<<2;
		else{
			if(j < n1) cout<<1;
			else cout<<3;
			j++;
		}
	}
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}