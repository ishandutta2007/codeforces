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

const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll n, a[N];

void solve(){
	vll pos, neg;
	ll ans = 1, res = 1;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] > 0) pos.pb(a[i]);
		else neg.pb(a[i]);
		res *= a[i];
	}
	if(n == 5){
		deb1(res)
		return;
	}
	sort(all(pos), greater<>());
	sort(all(neg));
	if(pos.size()){
		ans = pos[0];
		multiset <ll, greater<>> s;
		for(int i = 1; i < pos.size(); i += 2){
			if(i == pos.size() - 1) break;
			s.insert(pos[i]*pos[i+1]);
		}
		for(int i = 0; i < neg.size(); i += 2){
			if(i == neg.size() - 1) break;
			s.insert(neg[i]*neg[i+1]);
		}
		auto it = s.begin();
		ans *= (*it);
		it++;
		ans *= (*it);
	} else {
		for(int i = neg.size() - 1; i >= neg.size() - 5; i--) ans *= neg[i];
	}
	deb1(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}