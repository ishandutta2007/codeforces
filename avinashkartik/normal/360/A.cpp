#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
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

const ll   N     =  5e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

int n, m, ub[N], val[N], q[N], l[N], r[N], d[N];

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) ub[i] = 1e9;
	for(int i = 1; i <= m; i++){
		cin >> q[i] >> l[i] >> r[i] >> d[i];
		if(q[i] == 1){
			for(int j = l[i]; j <= r[i]; j++){
				val[j] += d[i];
			}
		} else {
			int f = 0;
			for(int j = l[i]; j <= r[i]; j++){
				ub[j] = min(ub[j], d[i] - val[j]);
				if(ub[j] + val[j] == d[i]) f = 1;
			}
			if(f == 0){
				deb1("NO")
				return;
			}
		}
	}
	mset(val,0);
	for(int i = 1; i <= m; i++){
		if(q[i] == 1){
			for(int j = l[i]; j <= r[i]; j++){
				val[j] += d[i];
			}
		} else {
			int mx = -1e9;
			for(int j = l[i]; j <= r[i]; j++){
				mx = max(mx, ub[j] + val[j]);
			}
			if(mx != d[i]){
				deb1("NO")
				return;
			}
		}
	}
	deb1("YES")
	for(int i = 1; i <= n; i++) cout << ub[i] << " "; newl;
}

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}