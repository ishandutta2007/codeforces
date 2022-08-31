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

const ll   N     =  2e3+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, a[N], A, m, dp[N][N], p[N];

ll mem(int ind, int u){
	if(ind == A+1) return 0;
	if(a[ind] != 0 and u == 0 and a[ind-1] == a[ind]) return INFi;
	if(dp[ind][u] != -1) return dp[ind][u];
	ll ans = mem(ind+1,0);
	if(u) ans = min(ans,mem(ind+1,u)+p[u]);
	if(p[ind] != -1){
		ans = min(ans,mem(ind+1,ind)+p[ind]);
	}
	return dp[ind][u] = ans;
}

void solve(){
	mset(p,-1);
	mset(dp,-1);
	cin>>A>>n>>m;
	A++;
	for(int i = 1; i <= n; i++){
		int u,v;
		cin>>u>>v;
		for(int j = u+1; j <= v+1; j++) a[j] = i;
	}
	for(int i = 1; i <= m; i++){
		ll u,v;
		cin>>u>>v;
		if(p[u+1] == -1) p[u+1] = v;
		else p[u+1] = min(p[u+1],v);
	}
	ll ans = mem(1,0);
	if(ans >= INFi) ans = -1;
	deb1(ans)
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