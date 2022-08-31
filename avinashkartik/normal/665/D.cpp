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
typedef  vector<pll>           vpll;

const ll   N     =  2e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], p[N];
void solve(){
	for(int i = 2; i*i < N; i++){
		if(p[i] == 0){
			for(int j = i*i; j < N; j += i) p[j] = 1;
		}
	}
	cin>>n;
	vll ans, v;
	for(int i = 1; i <= n; i++) cin>>a[i];
	ans.pb(a[1]);
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(p[a[i]+a[j]] == 0){
				ans.clear();
				ans.pb(a[i]); ans.pb(a[j]);
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++) if(a[i] == 1) v.pb(a[i]);
	for(int i = 1; i <= n; i++){
		if(p[a[i]+1] == 0 and a[i] != 1 and v.size()){
			v.pb(a[i]);
			break;
		}
	}
	if(v.size() > ans.size()) ans = v;
	deb1(ans.size())
	debv(ans)
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