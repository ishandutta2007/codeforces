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

const ll   N     =  4e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll n, a[N];

ll tree[N] = {};
 
void update(int idx, int val){ 
    idx++;
    while(idx <= N-2){ 
        tree[idx] += val;
        idx += idx & (-idx); 
    } 
} 
 
ll query(int idx){
    idx++;
    ll sum = 0;
    while(idx > 0){ 
        sum += tree[idx];
        idx -= idx & (-idx); 
    } 
    return sum; 
}

void solve(){
	mset(tree,0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	vll add[n+2], rem[n+2];
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(a[i] == a[j]) add[i].pb(j), rem[j].pb(i);
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		for(auto it : add[i]){
			ans += query(it-1)-query(i);
		}
		for(auto it : add[i]) update(it,1);
		for(auto it : rem[i]) update(i,-1);
	}
	deb1(ans)
}

int main(){
	GODSPEED;
	ll test = 1;
	cin>>test;
	for(ll i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}