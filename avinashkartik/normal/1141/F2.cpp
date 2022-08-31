#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
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
 
const ll   N     =  1505;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, a[N], pre[N];
set <ll> s;
map <ll, vpll> m;


void solve(){
	cin>>n;
	pre[0] = 0;
	for(ll i = 1; i <= n; i++) cin>>a[i], pre[i] = pre[i-1]+a[i];
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			ll x = pre[j]-pre[i-1];
			m[x].pb({i,j});
			s.insert(x);
		}
	}
	vpll fans;
	int res = 0;
	for(auto dif : s){
		int ct = 0, l = n+1;
		vpll ans;
		reverse(m[dif].begin(), m[dif].end());
		for(auto it : m[dif]){
			if(it.s < l){
				ct++;
				l = it.f;
				ans.pb(it);
			}
		}
		if(ct > res){
			res = ct;
			fans = ans;
		}
	}
	deb1(res);
	for(auto it : fans) deb2(it.f,it.s);
}

int main(){
    fastio;
    //cin>>test;
    for(ll i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}