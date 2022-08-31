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

const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll l, r, k, p, ans;

ll fastmod(ll x, ll y, ll mod){
	ll res = 1;
	while(y){
		if(y&1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

void solve(){
	cin >> k >> l >> r >> p;
	if(p == 2){
		deb1(1 - (k&1))
	} else {
		if(k % p == 0){
			ans = 1;
			if(k&1){
				ans = ans * fastmod(fastmod(2, r - l, p), p - 2, p) % p;
			}
			deb1(ans)
		} else {
			ll x = (fastmod(k, fastmod(2, r + 1, p - 1), p) + p - 1) % p;
			ll y = (fastmod(k, fastmod(2, l, p - 1), p) + p - 1) % p;
			if(y) ans = x * fastmod(y, p - 2, p) % p;
			else ans = fastmod(2, r - l + 1, p);
			if(k&1){
				ans = ans * fastmod(fastmod(2, r - l, p), p - 2, p) % p;
			}
			deb1(ans)
		}
	}
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}