#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
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
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());          
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  3e6+8;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], last[N], fst[N], dp[N], comp[N];

void solve(){
	set <ll> s;
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i], s.insert(a[i]);
	ll j = 1, mx = 0;
	for(auto it : s) comp[it] = j++; j--;
	for(int i = 1; i <= n; i++){
		a[i] = comp[a[i]], dp[a[i]] = 1, last[a[i]] = i;
		if(fst[a[i]] == 0) fst[a[i]] = i;
	}
	for(int i = 2; i <= j; i++) if(fst[i] > last[i-1]) dp[i] = dp[i-1]+1;
	for(int i = 1; i <= j; i++) mx = max(dp[i],mx);
	deb1(j-mx)
	for(int i = 1; i <= j; i++) fst[i] = 0;
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}