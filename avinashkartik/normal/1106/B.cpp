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

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, a[N], c[N];

void solve(){
	cin >> n >> m;
	set <pll> s;
	ll tot = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], tot += a[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) s.insert({c[i], i});
	for(int i = 1; i <= m; i++){
		ll t, d; cin >> t >> d;
		ll ans = 0;
		ll mn = min(a[t], d), f = 1;
		a[t] -= mn;
		if(a[t] == 0) s.erase({c[t], t});
		d -= mn;
		tot -= mn;
		ans += mn * c[t];
		while(d){
			if(tot == 0){
				deb1(0)
				f = 0;
				break;
			}
			auto it = s.begin();
			t = it->s;
			mn = min(a[t], d);
			a[t] -= mn;
			if(a[t] == 0) s.erase({c[t], t});
			d -= mn;
			tot -= mn;
			ans += mn * c[t];
		}
		if(f) deb1(ans)
	}
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}