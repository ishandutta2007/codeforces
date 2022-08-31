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
 
const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, v[N], p[N], sz[N];
set <pll> s0, s1;

void make(ll n){
	for(int i = 1; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y){
	ll a = find(x);
	ll b = find(y);
	if(a != b){
		if(sz[a] >= sz[b]) swap(a,b);
		p[a] = b;
		sz[b] += sz[a];
	}
}

void solve(){
	cin>>n;
	make(n);
	for(int i = 1; i <= n; i++){
		int x;
		cin>>v[i]>>x;
		if(v[i] == 0) s0.insert({x,i});
		else s1.insert({x,i});
	}
	for(int i = 1; i < n; i++){
		if(s0.size() == 0 or s1.size() == 0) break;
		pll p = *s0.begin();
		pll p1 = *s1.begin();
		s0.erase(p);
		s1.erase(p1);
		int x = min(p.f,p1.f);
		p.f -= x;
		p1.f -= x;
		deb3(p1.s,p.s,x)
		merge(p1.s,p.s);
		if(p1.f != 0) s1.insert(p1);
		if(p.f != 0) s0.insert(p);
	}

	set <ll> s;
	ll rep0[N] = {}, rep1[N] = {}, r1 = 0, r0 = 0;
	for(int i = 1; i <= n; i++){
		ll x = find(i);
		s.insert(x);
		if(v[i] == 0) rep0[x] = i, r0 = i;
		else rep1[x] = i, r1 = i;
	}
	vll V;
	for(auto it : s) V.pb(it);
	ll len = V.size();
	for(int i = 0; i < len; i++){
		if(rep0[V[i]] and find(V[i]) != find(r1)){
			deb3(rep0[V[i]],r1,0)
			merge(V[i],r1);
		}
	}
	for(int i = 0; i < len; i++){
		if(rep1[V[i]] and find(V[i]) != find(r0)){
			deb3(rep1[V[i]],r0,0)
			merge(V[i],r0);
		}
	}
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}