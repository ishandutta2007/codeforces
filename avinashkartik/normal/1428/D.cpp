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

ll n, a[N];

void solve(){
	cin >> n;
	vector <int> v2, v1, v3, c(n+5);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vpll ans;
	int st = n;
	for(int i = n; i >= 1; i--){
		if(a[i] == 0) continue;
		if(a[i] == 1){
			ans.pb({st, i});
			v1.pb(i);
			c[i] = st;
			st--;
		} else if(a[i] == 2){
			if(v1.size() == 0){
				deb1(-1)
				return;
			}
			ans.pb({c[v1.back()], i});
			v1.pop_back();
			v2.pb(i);
		} else if(a[i] == 3){
			if(v1.size() == 0 && v2.size() == 0 && v3.size() == 0){
				deb1(-1)
				return;
			}
			if(v3.size()){
				ans.pb({st, i});
				ans.pb({st, v3.back()});
				v3.pop_back();
				st--;
			} else if(v2.size()){
				ans.pb({st, i});
				ans.pb({st, v2.back()});
				v2.pop_back();
				st--;
			} else {
				ans.pb({st, i});
				ans.pb({st, v1.back()});
				v1.pop_back();
				st--;
			}
			v3.pb(i);
		}
	}
	for(auto it : ans){
		if(it.f < 1 || it.f > n){
			deb1(-1)
			return;
		}
		if(it.s < 1 || it.s > n){
			deb1(-1)
			return;
		}
	}
	deb1(ans.size())
	for(auto it : ans) deb2(it.f, it.s)
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