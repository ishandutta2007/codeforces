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

const ll   N     =  2e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], vis[N];

bool ch(int x){
	return a[n-1]%x == 0 and vis[a[n-1]/x];
}

void solve(){
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a,a+n);
	ll ans = a[n-1], v1 = a[n-1], v2 = 1;
	for(int j = n-2; j >= 0; j--){
		if(v1%a[j] and v2%a[j]){
			if(v2 == 1) v2 = a[j], ans = v1+v2;
			else{
				ans = v1+v2+a[j];
				break;
			}
		}
		vis[a[j]] = 1;
	}
	ll res = ch(2)&ch(3)&ch(5);
	if(res) ans = max(ans,a[n-1]/2+a[n-1]/3+a[n-1]/5);
	deb1(ans)
	for(int i = 0; i < n; i++) vis[a[i]] = 0;
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