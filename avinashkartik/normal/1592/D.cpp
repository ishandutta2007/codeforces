#include<bits/stdc++.h>

using namespace std;

#define  f              first                 
#define  s              second
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n;
vector <int> o, adj[N];

ll q(int r){
	vector <int> V;
	for (int i = 0; i < r; i++) V.pb(o[i]);
	cout << "? " << V.size() << " ";
	debv(V)
	ll x; cin >> x;
	return x;
}
 
void solve(){
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector <int> vis(n + 1, 0), p(n + 1, 0);
	queue <int> Q;
	Q.push(1);
	vis[1] = 1;
	while (Q.size()) {
		int x = Q.front();
		Q.pop();
		o.pb(x);
		for (auto it : adj[x]) {
			if (vis[it]) continue;
			vis[it] = 1;
			p[it] = x;
			Q.push(it);
		}
	}
	ll res = q(n), l = 2, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (q(mid) == res) r = mid;
		else l = mid + 1;
	}
	// assert(q(l, l) == res);
	deb3('!', o[l - 1], p[o[l - 1]])
}

int main(){
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}