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

const int  N     =  3e5+5;
const int  mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;


int calc(ll a1, ll a2, ll a3, ll b1, ll b2, ll b3){
	int x = min(a1, b3);
	a1 -= x, b3 -= x;
	x = min(a1, b1);
	a1 -= x, b1 -= x;
	b2 -= a1;
	int y = min(a2, b1);
	a2 -= y, b1 -= y;
	y = min(a2, b2);
	a2 -= y, b1 -= y;
	b3 -= a2;
	int z = min(a3, b2);
	a3 -= z, b2 -= z;
	z = min(a3, b3);
	a3 -= z, b3 -= z;
	b1 -= a3;
	int mn = a1 + a2 + a3;
	return mn;
}

void solve(){
	ll n, a1, a2, a3, b1, b2, b3;
	cin >> n;
	cin >> a1 >> a2 >> a3;
	cin >> b1 >> b2 >> b3;
	int mx = min(a1, b2) + min(a2, b3) + min(a3, b1);
	int mn = INFi;
	mn = min(mn, calc(a1, a2, a3, b1, b2, b3));
	mn = min(mn, calc(a2, a3, a1, b2, b3, b1));
	mn = min(mn, calc(a3, a1, a2, b3, b1, b2));
	deb2(mn, mx)
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