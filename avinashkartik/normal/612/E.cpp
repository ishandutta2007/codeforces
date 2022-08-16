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

const ll   N     =  3e6+8;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int test = 1, n, a[N], ans[N], ind[N];
vll t[N];

vll find(int i){
	ll st = a[i];
	vll v;
	while(st != i){
		v.pb(st);
		st = a[st];
	}
	v.pb(st);
	return v;
}

int reorder(int i, vll v){
	ll st = i, x = i;
	st = v.back();
	ans[x] = st;
	x = st;
	st = a[i];
	while(x != i){
		if(ans[x] > 0) return 0;
		ans[x] = st;
		int tmp = st;
		st = a[x];
		x = tmp;
	}
}

void getans(int i){
	vll v = find(i);
	if(v.size()%2 == 0){
		for(auto it : v) ans[it] = -1;
		if(t[v.size()].size() == 0){
			t[v.size()] = v;
			return;
		}
		for(auto it : t[v.size()]) v.pb(it);
		t[v.size()/2].clear();
		reorder(i,v);
	}
	else{
		int m = v.size();
		for(int i = 0; i < m; i++) ans[v[i]] = a[v[(i-(m+1)/2+m)%m]];
	}
}

void solve(){
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i], ind[a[i]] = i;
	for(int i = 1; i <= n; i++){
		if(ans[i] == 0) getans(i);
	}
	int f = 1;
	for(int i = 1; i <= n; i++) if(ans[i] == -1) f = 0;
	if(f == 0) deb1(-1)
	else for(int i = 1; i <= n; i++) cout<<ans[i]<<" ";
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