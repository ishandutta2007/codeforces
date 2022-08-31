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
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+3;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, k, a[N], ans = 0, p[N];

ll val(ll x, ll pi){
	ll m = x % pi;
	return m * (x / pi + 1) * (x / pi + 1) + (pi - m) * (x / pi) * (x / pi);
}

ll dif(int i, int pi){
	return val(a[i], pi) - val(a[i], pi+1);
}

void solve(){
	cin >> n >> k;
	set <pll, greater<>> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ans += a[i] * a[i];
		p[i] = 1;
		//deb1(dif(i, p[i]))
		s.insert({dif(i, p[i]), i});
	}
	for(int i = 1; i <= k - n; i++){
		auto it = *s.begin();
		ans -= it.f;
		p[it.s]++;
		s.erase(it);
		s.insert({dif(it.s, p[it.s]), it.s});
	}
	deb1(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}