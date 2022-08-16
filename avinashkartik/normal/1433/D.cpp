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

const ll   N     =  5e5+5;
const ll   M     =  4e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, a[N], p[N], sz[N];

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
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	make(n);
	vpll ans;
	for(int i = 1; i <= n; i++){
		if(a[1] != a[i]){
			if(find(1) != find(i)){
				merge(1, i);
				ans.pb({1, i});
			}
		}
	}
	if(sz[find(1)] == 1){
		deb1("NO")
		return;
	}
	int f = 1;
	for(int i = 1; i <= n; i++) if(a[i] != a[1]) f = i;
	for(int i = 1; i <= n; i++){
		if(a[f] != a[i]){
			if(find(f) != find(i)){
				merge(f, i);
				ans.pb({f, i});
			}
		}
	}
	assert(ans.size() == n-1);
	deb1("YES")
	for(auto it : ans) deb2(it.f, it.s)
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}