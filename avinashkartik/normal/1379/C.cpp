#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
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
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, pre[N]; 
vpll v;

ll f(ll mid, ll ind){
	ll ct = v[ind].f + (n-1-mid)*v[ind].s;
	ct += pre[mid-1];
	if(ind < mid) ct += v[mid].f-v[ind].f;
	return ct;
}

ll ternary_search(ll l, ll r, ll ind){
    for(int i = 0; i < 50; i++){
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        ll f1 = f(m1,ind);
        ll f2 = f(m2,ind);
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    ll ans = -INF;
    for(int i = l; i <= r; i++) ans = max(ans,f(i,ind));
    return ans;
}

void solve(){
	v.clear();
	cin>>n>>m;
	for(int i = 1; i <= m; i++){
		int x,y; cin>>x>>y;
		v.pb({x,y});
	}
	sort(all(v)); reverse(all(v));
	pre[0] = v[0].f;
	for(int i = 1; i < m; i++){
		pre[i] = pre[i-1]+v[i].f;
	}
	ll ans = -INF;
	for(int i = 0; i < m; i++){
		ans = max(ans,ternary_search(0,min(n-1,m-1),i));
	}
	deb1(ans)
}

int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}