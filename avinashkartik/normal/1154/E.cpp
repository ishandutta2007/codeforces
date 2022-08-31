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

const ll   N     =  2e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, k, a[N], prv[N], nxt[N], ans[N];
set <ll,greater<ll>> s;
map <ll,ll> ind;

int findprv(ll x){
	return (prv[x] == x)? x: prv[x] = findprv(prv[x]);
}

int findnxt(ll x){
	return (nxt[x] == x)? x: nxt[x] = findnxt(nxt[x]);
}

void solve(){
    cin>>n>>k;
    for(int i = 1; i <= n; i++) cin>>a[i], s.insert(i), ind[a[i]] = i;
    for(int i = 0; i <= n+1; i++) prv[i] = i, nxt[i] = i;
    int team = 1;
    while(s.size()){
    	int mx = *s.begin();
    	int idx = ind[mx];
    	s.erase(mx);
    	ans[idx] = team;
    	prv[idx] = idx-1;
    	nxt[idx] = idx+1;
    	for(int i = 0; i < k; i++){
    		idx = findprv(idx);
    		if(idx == 0) break;
    		s.erase(a[idx]);
    		ans[idx] = team;
    		prv[idx] = idx-1;
    		nxt[idx] = idx+1;
    	}
    	idx = ind[mx];
    	for(int i = 0; i < k; i++){
    		idx = findnxt(idx);
    		if(idx == n+1) break;
    		s.erase(a[idx]);
    		ans[idx] = team;
    		prv[idx] = idx-1;
    		nxt[idx] = idx+1;
    	}
    	if(team == 1) team = 2;
    	else team = 1;
    }
    for(int i = 1; i <= n; i++) cout<<ans[i]; cout<<endl;
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