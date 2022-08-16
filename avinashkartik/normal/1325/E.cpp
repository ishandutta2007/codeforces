#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
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
 
const ll   N     =  1e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, a[N], spf[N], ct[N], par[N];
vll adj[N];

void sieve(){
	mset(spf,-1);
	for(ll i = 2; i*i < N; i++){
		if(spf[i] == -1){
			for(int j = 2*i; j < N; j += i){
				if(spf[j] == -1) spf[j] = i;
			}
		}
	}
}

ll normalize(ll n){
	for(int i = 2; i*i <= n; i++){
		ll x = i*i;
		while(n%x == 0) n /= x;
	}
	return n;
}

ll bfs(ll st){
	mset(ct,0);
	mset(par,0);
	queue <ll> q;
	q.push(st);
	ct[st] = 1;
	while(q.size()){
		ll x = q.front(); q.pop();
		for(auto it : adj[x]){
			if(it == par[x]) continue;
			if(ct[it] != 0){
				return ct[x]+ct[it]-1;
			}
			ct[it] = ct[x]+1;
			par[it] = x;
			q.push(it);
		}
	}
	return INF;
}

void solve(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		a[i] = normalize(a[i]);
	}
	sort(a,a+n);
	if(a[0] == 1){
		deb1(1)
		return;
	}
	a[n] = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == a[i+1]){
			deb1(2)
			return;
		}
		if(spf[a[i]] == -1){
			adj[1].pb(a[i]);
			adj[a[i]].pb(1);
		}
		else{
			ll x = spf[a[i]], y = a[i]/x;
			adj[x].pb(y);
			adj[y].pb(x);
		}
	}
	ll ans = INF;
	for(int i = 2; i*i <= N; i++){
		if(spf[i] == -1){
			ans = min(ans,bfs(i));
		}
	}
	if(ans == INF) ans = -1;
	deb1(ans)
}

int main(){
    fastio;
    //cin>>test;
    sieve();
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}