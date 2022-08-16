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

ll test=1, n, m, a[N], cnt[N], p[N];
vll v[N];

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void solve(){
	cin>>n>>m;
	for(int i = 0; i < n; i++) cin>>a[i], v[a[i]%m].pb(i), cnt[a[i]%m]++;
	ll ct = 0, ind = 0;
	for(int i = 0; i < m; i++){
		p[i] = i;
		if(cnt[i] >= n/m) p[i] = (i+1)%m;
	}
	for(int j = 0; j < 2; j++){
		for(int i = 0; i < m; i++){
			int sz = v[i].size(); sz -= n/m;
			int f = 0;
			while(sz > 0){
				ind = find(i);
				v[ind].pb(v[i].back());
				v[i].pop_back();
				sz--;
				cnt[ind]++;
				cnt[i]--;
				if(cnt[ind] >= n/m) p[ind] = (ind+1)%m;
			}
		}
	}
	for(int i = 0; i < m; i++){
		assert(v[i].size() == n/m);
		for(auto it : v[i]){
			ll x = a[it];
			a[it] += (i-(a[it]%m)+m)%m;
			ct += a[it]-x;
		}
	}
	deb1(ct);
	for(int i = 0; i < n; i++) cout<<a[i]<<" ";
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