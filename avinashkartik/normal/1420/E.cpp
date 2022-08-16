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

const int  N     =  3e5+5;
const int  mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, k, a[N], f[N];

ll calc(){
	ll cur = 0, prv = 0, ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 1){
			prv += cur;
			cur = 0;
		} else {
			ans += prv;
			cur++;
		}
	}
	return ans;
}

void solve(){
	cin >> n;
	int no = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], no += 1 - a[i];
	a[0] = a[n + 1] = 0;
	ll ans = calc();
	for(int i = 0; i <= n+1; i++) f[i] = 1;
	vll p;
	for(int i = 1; i <= no; i++){
		int o = ceil((ld) no / i) - 1;
		if(no + o <= n){
			for(int j = 1, ct = 0; j <= n; j++){
				if(ct == i){
					ct = 0;
					continue;
				}
				f[j] = 0;
				p.pb(j);
				ct++;
				no--;
				if(no == 0) break;
			}
			break;
		}
	}
	cout << ans << " ";
	for(int i = 1; i <= n * (n - 1) / 2; i++){
		int ind = 0, d =  0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 1) continue;
			if(a[i-1] == 1) {
				swap(a[i], a[i-1]);
				ll res = calc();
				if(res > ans){
					ans = res;
					ind = i;
					d = -1;
				}
				swap(a[i], a[i-1]);
			}
			if(a[i+1] == 1){
				swap(a[i], a[i+1]);
				ll res = calc();
				if(res > ans){
					ans = res;
					ind = i;
					d = 1;
				}
				swap(a[i], a[i+1]);
			}
		}
		if(ind == 0){
			for(int i = 1, j = 0; i <= n; i++){
				if(a[i] == 0){
					if(i > p[j] and a[i-1] == 1){
						swap(a[i-1], a[i]);
						break;
					}
					if(i < p[j] and a[i+1] == 1){
						swap(a[i+1], a[i]);
						break;
					}
					j++;
				}
			}
		} else swap(a[ind], a[ind + d]);
		cout << ans << " ";
	}
	newl;
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