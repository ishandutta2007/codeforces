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

const ll   N     =  2e3+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, u = 0, d = 0, lb = 1e8, rb = -1e8;
vpll a;

ld dist(ld x1, ld y1, ld x2, ld y2){
	return sqrt((ld)(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

ld ch(ld mid){
	ld R = 0;
	for(auto it : a){
		ld xi = it.f, yi = it.s;
		R = max(R,((ld)yi*yi + (xi-mid)*(xi-mid))/(2*yi));
	}
	return R;
}

void bs(){
	ld l = -1e7, r = 1e7;
	int ct = 0;
	while (r - l > 1e-12) {
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l) / 3;
        ld f1 = ch(m1);
        ld f2 = ch(m2);
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
	deb1(ch(l))
}

void solve(){
	cin>>n;
	for(int i = 0; i < n; i++){
		ll x,y;
		cin>>x>>y;
		lb = min(lb,x);
		rb = max(rb,x);
		if(y > 0) u++;
		else if(y < 0) d++;
		a.pb({x,abs(y)});
	}
	if(u and d){
		deb1(-1)
		return;
	}
	bs();
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