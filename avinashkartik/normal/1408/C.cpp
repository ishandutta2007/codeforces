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
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, l, a[N];

bool ch(ld mid){
	ld prv = 0, mid1 = mid;
	int sp = 1;
	for(int i = 1; i <= n; i++){
		if((a[i] - prv) / sp < mid1){
			mid1 -= (ld) (a[i] - prv) / sp;
			prv = a[i];
			sp++;
		} else {
			prv += sp * mid1;
			mid1 = 0;
			break;
		}
	}
	prv += sp * mid1;
	ld prv2 = l, mid2 = mid;
	int sp2 = 1;
	for(int i = n; i >= 1; i--){
		if((prv2 - a[i]) / sp2 < mid2){
			mid2 -= (ld) (prv2 - a[i]) / sp2;
			prv2 = a[i];
			sp2++;
		} else {
			prv2 -= sp2 * mid2;
			mid2 = 0;
			break;
		}
	}
	prv2 -= sp2 * mid2;
	//deb2(prv, prv2)
	return prv <= prv2;
}

void bs(){
	ld l = 0, r = 2e9, ans = 0, eps = 1e-9;
	while(r - l >= eps){
		ld mid = (l + r) / 2;
		if(ch(mid) == 1){
			ans = mid;
			l = mid + eps;
		} else r = mid - eps;
	}
	deb1(ans)
}

void solve(){
	cin >> n >> l;
	for(int i = 1; i <= n; i++) cin >> a[i];
	bs();
	//ch(3);
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}