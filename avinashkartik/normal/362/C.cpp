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

const int  N     =  5e3+5;
const int  mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, a[N], pre[N][N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < n; j++) pre[i][j] = pre[i-1][j];
		for(int j = 0; j < a[i]; j++) pre[i][j]++;
		ans += pre[i][a[i]];
	}
	int mn = INFi, ct = 0;
	for(int i = 1; i <= n; i++){
		ll res = ans;
		for(int j = i + 1; j <= n; j++){
			if(a[j] < a[i]) res--;
			else res++;
			ll nres = res;
			nres += (j - i - 1) - 2*(pre[j][a[j]] - pre[i][a[j]]);
			if(nres < mn){
				mn = nres;
				ct = 1;
			} else if(nres == mn) ct++;
		}
	}
	deb2(mn, ct)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}