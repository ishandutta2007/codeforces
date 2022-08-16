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

const ll   N     =  2e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll n, a[N], ct[60], vis[N], ans = INFi;
vll adj[N];

void bfs(int x){
	queue <int> q;
	vector <int> p(n, -1);
	q.push(x);
	vis[x] = 0;
	while(q.size()){
		int x = q.front(); q.pop();
		for(auto it : adj[x]){
			if(vis[it] == -1){
				vis[it] = vis[x] + 1;
				p[it] = x;
				q.push(it);
			} else if(p[x] != it){
				ans = min(ans, vis[x] + vis[it] + 1);
			}
		}
	}
}

void solve(){
	cin >> n;
	vll v;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i]) v.pb(a[i]);
		for(int j = 0; j < 60; j++){
			if(a[i]&(1ll << j)) ct[j]++;
			if(ct[j] > 2){
				deb1(3)
				return;
			}
		}
	}
	for(int i = 0; i < v.size(); i++){
		for(int j = i + 1; j < v.size(); j++){
			if(v[i]&v[j]){
				//deb2(i, j)
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}
	for(int i = 0; i < v.size(); i++){
		mset(vis, -1);
		bfs(i);
	}
	if(ans == INFi) ans = -1;
	deb1(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}