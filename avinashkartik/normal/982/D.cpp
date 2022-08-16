#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;  
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  1e+6+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll p[N], sz[N], vis[N], a[N], ct[N], b[N], n;
um m;

void make(ll n){
	for(int i = 1; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y){
	ll a = find(x);
	ll b = find(y);
	if(a != b){
		if(sz[a] >= sz[b]) swap(a,b);
		p[a] = b;
		sz[b] += sz[a];
	}
}

void solve(){
	cin>>n;
	make(n);
	for(int i = 1; i <= n; i++) cin>>a[i], b[i] = a[i], m[a[i]] = i;
	sort(a+1,a+n+1);
	b[0] = b[n+1] = INFi;
	ll ans = 0, mx = 0;
	for(int i = 1; i <= n; i++){
		ll ind = m[a[i]];
		if(b[ind-1] > b[ind] && b[ind+1] > b[ind]){
			ct[1]++;
		}
		else if(b[ind-1] < b[ind]){
			ct[sz[find(ind-1)]]--;
			merge(ind,ind-1);
			ct[sz[find(ind)]]++;
		}
		else if(b[ind+1] < b[ind]){
			ct[sz[find(ind+1)]]--;
			merge(ind,ind+1);
			ct[sz[find(ind)]]++;
		}
		ll s = sz[find(ind)];
		if(ct[s]*s == i){
			if(ct[s] > mx){
				mx = ct[s];
				ans = a[i]+1;
			}
		}
	}	
	cout<<ans<<endl;
}

int main(){
	fastio;
	ll t = 1;
	//cin>>t;
	while(t--){
		solve();
	}
}