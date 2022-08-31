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
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, m, vis[N];

ll fastmod(ll x, ll y){
	ll res = 1, mod = y;
	y -= 2;
	while(y){
		if(y&1) res = (res*x)%mod;
		x = (x*x)%mod;
		y /= 2;
	}
	return res;
}

pll calc(){
	mset(vis,0);
	ll h, a, x, y, ct = -1,tct = 0;
	cin>>h>>a>>x>>y;
	vis[h] = 1;
	for(int i = 1; i <= m; i++){
		ll nh = (x*h+y)%m;
		if(nh == a){
			ct = i;
			break;
		}
		if(vis[nh] == 1) break;
		h = nh;
		vis[nh] = 1;
	}
	if(ct == -1) return {-1,-1};
	mset(vis,0);
	h = a;
	vis[h] = 1;
	for(int i = 1; i <= m; i++){
		tct = i;
		ll nh = (x*h+y)%m;
		h = nh;
		if(vis[h] == 1) break;
		vis[h] = 1;
	}
	if(h != a) tct = -1;
	return {ct,tct};
}

void solve(){
	cin>>m;
	pll p = calc(), q = calc();
	if(p.f == -1 or q.f == -1){
		deb1(-1)
		return;
	}
	if(p.f == q.f){
		deb1(p.f)
		return;
	}
	if(p.s != -1 and q.s == -1){
		if(q.f > p.f and (q.f-p.f)%p.s == 0) deb1(q.f)
		else deb1(-1)
		return;
	}
	if(p.s == -1 and q.s != -1){
		if(p.f > q.f and (p.f-q.f)%q.s == 0) deb1(p.f)
		else deb1(-1)
		return;
	}
	if(p.s == -1 and q.s == -1){
		deb1(-1)
		return;
	}
	for(int i = 0; i <= m; i++){
		if(p.f+i*p.s < q.f) continue;
		if((p.f+i*p.s-q.f)%q.s == 0){
			deb1(p.f+i*p.s)
			return;
		}
	}
	deb1(-1)
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