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

const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, k, a[N];

ll fastmod(ll x, ll y = mod - 2){
	ll res = 1;
	while(y){
		if(y&1) res = res * x % (mod);
		x = x * x % (mod);
		y /= 2;
	}
	return res;
}

ll ncr(ll n, ll r){
	ll ans = 1;
	for(int i = n; i > n - r; i--){
		ans = ans * i % mod * fastmod(n - i + 1) % mod;
	}
	return ans;
}

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll mn = INF, ct = 0, tot = 0; 
	for(int i = n; i > n - k; i--){
		if(a[i] < mn){
			mn = a[i];
			ct = 0;
		}
		ct++;
	}
	for(int i = n; i > 0; i--){
		if(a[i] == mn) tot++;
	}
	deb1(ncr(tot, ct))
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