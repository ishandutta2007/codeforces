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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll k, l, r, t, x, y;

void solve(){
	cin >> k >> l >> r >> t >> x >> y;
	if(k > r || k < l){
		deb1("No")
		return;
	}
	if(x == y){
		if(k + y <= r){
			deb1("Yes")
			return;
		}
		if(k - x >= l){
			deb1("Yes")
			return;
		}
		deb1("No")
	} else if(x > y){
		if(k + y > r) k -= x, t--;
		ll d = ceil((ld) (k - l + 1) / (x - y));
		if(d > t) deb1("Yes")
		else deb1("No")
	} else {
		if(r - y < l){
			ll d = ceil((ld) (k - l + 1) / x);
			if(d > t) deb1("Yes")
			else deb1("No")
			return;
		}
		if(r - y - l >= x){
			deb1("Yes")
			return;
		}
		map <ll, ll> vis;
		while(t > 0){
			ll d = ceil((ld) (k - (r - y)) / x);
			d = min(t, d);
			k -= x * d;
			if(vis[k] == 1) break;
			if(k < l){
				deb1("No")
				return;
			}
			t -= d;
			vis[k] = 1;
			k += y;
		} 
		deb1("Yes")
	}
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