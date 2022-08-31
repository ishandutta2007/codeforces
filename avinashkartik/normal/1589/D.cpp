#include<bits/stdc++.h>

using namespace std;

#define  f              first                 
#define  s              second
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
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n;

ll q(ll l, ll r) {
	deb3('?', l, r)
	ll x; cin >> x;
	return x;
}

void solve(){
	cin >> n;
	ll t = q(1, n);
	ll l = 1, r = n, i = 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (q(mid, n) >= t) {
			i = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	ll j = i + t - q(i + 1, n) + 1;
	r = t - (j - i) * (j - i - 1) / 2;
	ll sq = ceil(sqrt(2 * r));
	ll k = j + sq - 1;
	deb4('!', i, j, k)
}

int main(){
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}