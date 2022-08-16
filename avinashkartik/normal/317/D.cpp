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

const int  N     =  1e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll test = 1, n, vis[N];
map <ll, int> g;

/*
int calc(ll msk){
	if(g.find(msk) != g.end()) return g[msk];
	set <int> s;
	for(int i = 28; i >= 0; i--){
		if(((1ll << i) & msk) == 0) continue;
		ll newmsk = msk;
		for(int j = i; j >= 0; j -= (29-i)){
			if((1ll << j) & msk) newmsk -= (1ll << j);
		}
		s.insert(calc(newmsk));
	}
	for(int i = 0; i <= 28; i++){
		if(s.find(i) == s.end()){
			g[msk] = i;
			break;
		}
	}
	return g[msk];
} */

int grundy[30] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};

void solve(){
	/* To pre - calculate the grundy values
	g[0] = 0;
	for(int i = 1; i <= 28; i++){
		ll msk = 0;
		for(int j = 28; j > 28-i; j--) msk ^= (1ll << j);
		deb1(calc(msk))
	} */
	cin >> n;
	ll left = n, ans = 0;
	for(int i = 2; i*i <= n; i++){
		if(vis[i]) continue;
		int ct = 0;
		for(ll j = i; j <= n; j *= i, ct++) if(j < N) vis[j] = 1;
		left -= ct;
		ans ^= grundy[ct];
	}
	ans ^= grundy[left%2];
	cout << ((ans)? "Vasya" : "Petya") << "\n";
}

int main(){
	GODSPEED;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}