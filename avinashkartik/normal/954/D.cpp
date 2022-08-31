#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, s, t, ch[N][N];
vll adj[N];

vll bfs(int s){
	vll dist(n+1,-1);
	dist[s] = 0;
	queue <int> q;
	q.push(s);
	while(q.size()) { 
		int x = q.front(); q.pop();
		for (auto it : adj[x]) {
			if (dist[it] == -1) {
				dist[it] = dist[x] + 1;
				q.push(it);
			}
		}
	}
	return dist;
}

void solve(){
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		ch[u][v] = 1;
		ch[v][u] = 1;
	}
	vll S = bfs(s);
	vll T = bfs(t);
	ll d = S[t], ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (ch[i][j]) continue;
			if (S[i] + T[j] + 1 < d or S[j] + T[i] + 1 < d) continue;
			ans++;
		}
	}
	deb1(ans)
}

int main(){
	GODSPEED;
	//cin>>test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}