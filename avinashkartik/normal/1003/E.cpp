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

const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, d, k, depth[N], deg[N];
vpll ans;

void solve(){
	cin>>n>>d>>k;
	for(int i = 1; i <= d; i++){
		ans.pb({i,i+1});
		depth[i] = i-1;
		deg[i]++;
		deg[i+1]++;
	}
	depth[d+1] = d;
	int cur = d+2;
	for(int i = 1; i <= n; i++){
		if(cur == n+1) break;
		int no = min(depth[i],d-depth[i]);
		if(no == 0) continue;
		for(int j = deg[i]+1; j <= k; j++){
			if(cur == n+1) break;
			if(depth[i] > d/2) depth[cur] = depth[i]+1;
			else depth[cur] = depth[i]-1;
			ans.pb({i,cur});
			deg[i]++;
			deg[cur]++;
			cur++;
		}
	}
	if(cur != n+1){
		deb1("NO")
		return;
	}
	for(int i = 1; i <= n; i++){
		if(deg[i] > k){
			deb1("NO")
			return;
		}
	}
	deb1("YES")
	for(auto it : ans) deb2(it.f,it.s)
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