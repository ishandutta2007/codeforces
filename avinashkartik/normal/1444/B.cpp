#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              f                 
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

const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, a[N], f[N], pre[N];

ll fastmod(ll x, ll y = mod - 2){
	ll res = 1;
	while(y){
		if(y&1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

ll ncr(ll n, ll r){
	return f[n] * fastmod(f[r]) % mod * fastmod(f[n - r]) % mod;
}

void solve(){
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = f[i - 1] * i % mod;
	cin >> n;
	for(int i = 1; i <= 2 * n; i++) cin >> a[i];
	sort(a + 1, a + 2*n + 1);
	for(int i = 1; i <= n; i++) a[i] = a[2*n - i + 1] - a[i];
	ll ans = 0;
	ll res = ncr(2*n - 1, n - 1);
	for(int i = 1; i <= n; i++){
		ans = (ans + res * a[i]) % mod;
	}
	deb1((2 * ans) % mod)
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