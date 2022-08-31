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
 
const ll   N     =  5005;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, k, a[N], dp[N][N], en[N];

ll mem(ll ind, ll no){
	if(ind < 0 or no == k){
		return 0;
	}
	if(dp[ind][no] != -1) return dp[ind][no];
	ll ans = mem(en[ind],no+1)+ind-en[ind];
	if(ind) ans = max(ans,mem(ind-1,no));
	return dp[ind][no] = ans;
}

void solve(){
	cin>>n>>k;
	for(int i = 0; i < n; i++) cin>>a[i];
	sort(a,a+n);
	for(int i = n-1, j = n-1; i >= 0; i--){
		while(j >= 0 and a[i] - a[j] <= 5) j -= 1;
		en[i] = j;
	}
	mset(dp,-1);
	ll res = mem(n-1,0);
	deb1(res)
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