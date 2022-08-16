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

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, a[N], ct[N][2], vis[N];
vll v[N], adj[N], res[N][2];

void dfs(int x, int st, int c){
	vis[x] = 1;
	res[st][c].pb(x);
	if(x > n) ct[st][c]++;
	for(auto it : adj[x]){
		if(!vis[it]) dfs(it, st, c^1);
	}
}

void solve(){
	cin >> n;
	if(n%2 == 0){
		deb1("First")
		for(int i = 1; i <= 2*n; i++){
			if(i <= n) cout << i << " ";
			else cout << i-n << " ";
		}
		cout << endl;
	} else{
		deb1("Second")
		for(int i = 1; i <= 2*n; i++){
			cin >> a[i];
			v[a[i]].pb(i);
		}
		for(int i = 1; i <= n; i++){
			adj[v[i][0]].pb(v[i][1]);
			adj[v[i][1]].pb(v[i][0]);
			adj[i].pb(i+n);
			adj[i+n].pb(i);
		}
		for(int i = 1; i <= n; i++){
			if(!vis[i]) dfs(i, i, 0);
		}
		bool f = 0;
		vll ans;
		for(int i = 1; i <= n; i++){
			if(res[i][0].size() == 0) continue;
			if(res[i][0].size()%2 == 0){
				for(auto it : res[i][0]) ans.pb(it);
				if(ct[i][0]%2 == 1) f ^= 1;
			}
		}
		for(int i = 1; i <= n; i++){
			if(res[i][0].size()%2 == 0) continue;
			if(n%4 == 1){
				if(ct[i][0]%2 == 1 and f == 0){
					for(auto it : res[i][0]) ans.pb(it);
					f ^= 1;
				} else if(ct[i][0]%2 == 0 and f == 1){
					for(auto it : res[i][0]) ans.pb(it);
				} else {
					for(auto it : res[i][1]) ans.pb(it);
					f ^= (ct[i][1]%2);
				}
			} else {
				if(ct[i][0]%2 == 1 and f == 1){
					for(auto it : res[i][0]) ans.pb(it);
					f ^= 1;
				} else if(ct[i][0]%2 == 0 and f == 0){
					for(auto it : res[i][0]) ans.pb(it);
				} else {
					for(auto it : res[i][1]) ans.pb(it);
					f ^= (ct[i][1]%2);
				}
			}
		}
		debv(ans)
		cin >> n;
	}
}

int main(){
	int test = 1;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}