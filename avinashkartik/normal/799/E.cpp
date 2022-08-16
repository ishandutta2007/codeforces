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

const ll   N     =  3e5+8;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, C, D, preC[N], preD[N], ans = 0;
vpll vc, vd;

void solve(){
	cin>>n>>C>>D;
	for(int i = 1; i <= n; i++){
		int bi,pi; char ch;
		cin>>bi>>pi>>ch;
		if(ch == 'C'){
			if(pi <= C) vc.pb({pi,bi});
		}
		else{
			if(pi <= D) vd.pb({pi,bi});
		}
	}
	sort(vc.begin(), vc.end());
	sort(vd.begin(), vd.end());
	ll pc = 0, pd = 0;
	for(int i = 0; i < vc.size(); i++){
		if(C <= 2*(vc[i].f)) ans = max(ans,vc[i].s+preC[C-vc[i].f]);
		else if(pc) ans = max(ans,vc[i].s+pc);
		pc = max(pc,vc[i].s);
		preC[vc[i].f] = pc;
	}
	for(int i = 0; i < vd.size(); i++){
		if(D <= 2*(vd[i].f)) ans = max(ans,vd[i].s+preD[D-vd[i].f]);
		else if(pd) ans = max(ans,vd[i].s+pd);
		pd = max(pd,vd[i].s);
		preD[vd[i].f] = pd;
	}
	if(pc and pd) ans = max(ans,pc+pd);
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