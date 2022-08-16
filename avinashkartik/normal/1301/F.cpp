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
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  1008;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int test=1, n, m, k, a[N][N], dist[41][N][N];
vpll adj[45];

void msbfs(int x){
	int vis[45];
	mset(vis,0);
	vis[x] = 1;
	queue <pll> q;
	for(auto it : adj[x]) q.push(it), dist[x][it.f][it.s] = 0;
	while(q.size()){
		pll st = q.front(); q.pop();
		int i = st.f, j = st.s;
		if(i == 0 or i == n+1) continue;
		if(j == 0 or j == m+1) continue;
		if(dist[x][i-1][j] == -1){
			dist[x][i-1][j] = dist[x][i][j]+1;
			q.push({i-1,j});
		}
		if(dist[x][i+1][j] == -1){
			dist[x][i+1][j] = dist[x][i][j]+1;
			q.push({i+1,j});
		} 
		if(dist[x][i][j-1] == -1){
			dist[x][i][j-1] = dist[x][i][j]+1;
			q.push({i,j-1});
		} 
		if(dist[x][i][j+1] == -1){
			dist[x][i][j+1] = dist[x][i][j]+1;
			q.push({i,j+1});
		}
		if(vis[a[i][j]] == 1) continue;
		for(auto it : adj[a[i][j]]){
			if(dist[x][it.f][it.s] == -1){
				dist[x][it.f][it.s] = dist[x][i][j]+1;
				q.push({it.f,it.s});
			}
		}
		vis[a[i][j]] = 1;
	}
}

void solve(){
	mset(dist,-1);
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		cin>>a[i][j];
    		adj[a[i][j]].pb({i,j});
    	}
    }
    for(int i = 1; i <= k; i++) msbfs(i);
    int q;
    cin>>q;
    for(int i = 1; i <= q; i++){
    	int r1,c1,r2,c2;
    	cin>>r1>>c1>>r2>>c2;
    	int ans = (abs(r1-r2)+abs(c1-c2));
    	for(int j = 1; j <= k; j++){
    		ans = min(ans,1+dist[j][r1][c1]+dist[j][r2][c2]);
    	}
    	deb1(ans)
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