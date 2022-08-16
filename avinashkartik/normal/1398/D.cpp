#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
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

const ll   N     =  305;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll test = 1, n, r[N], g[N], b[N], R, G, B, dp[N][N][N];

ll mem(int ri, int gi, int bi){
	if(ri == R && gi == G && bi == B) return 0;
	if(dp[ri][gi][bi] != -1) return dp[ri][gi][bi];
	ll ans = 0;
	if(ri != R and gi != G) ans = max(ans,mem(ri+1,gi+1,bi)+r[ri]*g[gi]);
	if(ri != R and bi != B) ans = max(ans,mem(ri+1,gi,bi+1)+r[ri]*b[bi]);
	if(bi != B and gi != G) ans = max(ans,mem(ri,gi+1,bi+1)+g[gi]*b[bi]);
	return dp[ri][gi][bi] = ans;
}

void solve(){
	mset(dp,-1);
	cin >> R >> G >> B;
	for(int i = 0; i < R; i++) cin >> r[i];
	for(int i = 0; i < G; i++) cin >> g[i];
	for(int i = 0; i < B; i++) cin >> b[i];
	sort(r,r+R,greater<>());
	sort(g,g+G,greater<>());
	sort(b,b+B,greater<>());
	deb1(mem(0,0,0))
}

int main(){
	GODSPEED;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}