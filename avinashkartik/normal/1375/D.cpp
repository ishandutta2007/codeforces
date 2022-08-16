#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
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
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], ct[N];
vll dup, ans;

int getMEX(){
	set <int> s;
	for(int i = 1; i <= n; i++) s.insert(a[i]);
	int mex = 0;
	for(auto it : s){
		if(it != mex) break;
		mex++;
	}
	return mex;
}

void solve(){
	dup.clear();
	ans.clear();
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	while(1){
		int x = getMEX();
		if(x == n){
			int f = 0;
			for(int i = 1; i <= n; i++){
				if(a[i] != i-1){
					f = i;
					break;
				}
			}
			if(f == 0) break;
			ans.pb(f);
			a[f] = x;
		}
		else{
			ans.pb(x+1);
			a[x+1] = x;
		}
	}
	assert(ans.size() <= 2*n);
	deb1(ans.size())
	debv(ans)
}

int main(){
	fastio;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}