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

const ll   N     =  5e5+3;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, x, y, k, b[N], a[N];
vll v;

ll ch(int l, int r){
	ll mx = max(a[l],a[r]), res = 0;
	set <ll> s1, s2;
	for(int i = l+1; i < r; i++){
		if(a[i] > mx) s1.insert(i);
		s2.insert(i);
	}
	if(s2.size() < k and s1.size()){
		deb1(-1)
		exit(0);
	}
	if(k*x > y){
		res = (s2.size()/k)*y + (s2.size()%k)*x;
	}
	else{
		if(s1.size()) res = y + (s2.size()-k)*x;
		else res = s2.size()*x;
	}
	return res;
}

void solve(){
    cin>>n>>m>>y>>k>>x;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= m; i++) cin>>b[i];
    a[0] = a[n+1] = b[0] = b[m+1] = 0;
    int j = 1;
    v.pb(0);
	for(int i = 1; i <= n; i++) if(a[i] == b[j]) j++, v.pb(i);
	v.pb(n+1);
	if(j != m+1){
		deb1(-1)
		return;
	}
	ll ans = 0;
	for(int i = 1; i <= m+1; i++){
		//deb1(ch(v[i-1],v[i]))
		ans += ch(v[i-1],v[i]);
	}
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