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
 
const ll   N     =  1e7+5;
const ll   M     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, a[M], p[N], ans1[M], ans2[M];
ll spf[N];

void solve(){
	mset(spf,-1);
	mset(ans1,-1);
	mset(ans2,-1);
	for(ll i = 2; i*i < N; i++){
		if(p[i] == 0){
			for(int j = 2*i; j < N; j += i){
				p[j] = 1;
				if(spf[j] == -1) spf[j] = i;
			}
		}
	}
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		if(p[a[i]] == 0){
			continue;
		}
		else{
			ll ct = spf[a[i]], y = spf[a[i]];
			while(a[i]%y == 0){
				ct *= y;
				a[i] /= y;
			}
			ll x = ct/y;
			if(__gcd(a[i]+x,a[i]*x) == 1 and a[i] > 1) ans1[i] = x, ans2[i] = a[i];
		}
	}
	for(int i = 0; i < n; i++) cout<<ans1[i]<<" "; cout<<endl;
	for(int i = 0; i < n; i++) cout<<ans2[i]<<" "; cout<<endl;
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