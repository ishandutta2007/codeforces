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
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  3e5+8;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], vis[N], inc[N], spf[N], ct[N], dp[N], flag[N];
vll fact[N];

int no_of_coprimes(int x){
	int res = 0;
	for(auto it : fact[x]) res += ct[it]*inc[it];
	return res;
}

void solve(){
	for(int i = 1; i < N; i++) {
		for(int j = i; j < N; j += i) fact[j].push_back(i);
		spf[i] = fact[i][1];
		if(i == 1) inc[i] = 1;
		else if((i/spf[i])%spf[i] == 0) inc[i] = 0;
		else inc[i] =- inc[i/spf[i]];
	}
    cin>>n;
    ll g = 0;
    for(int i = 1; i <= n; i++){
    	cin>>a[i];
    	if(a[i] == 1){
    		deb1(1)
    		return;
    	}
    	if(g == 0) g = a[i];
    	else g = __gcd(a[i],g);
    	vis[a[i]] = 1;
    	for(auto it : fact[a[i]]) ct[it]++;
    }
    if(g != 1){
    	deb1(-1)
    	return;
    }
    for(ll i = N-8; i >= 1; i--) flag[i] = no_of_coprimes(i);
    for(ll i = N-8; i >= 1; i--){
    	if(vis[i] == 1){ dp[i] = 1; continue; }
    	dp[i] = INF;
    	for(ll j = 2*i; j <= N-8; j += i){
			if(flag[j/i]) dp[i] = min(dp[i],dp[j]+1);
		}
    }
    deb1(dp[1])
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}