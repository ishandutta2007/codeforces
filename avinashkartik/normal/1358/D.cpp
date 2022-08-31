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
 
const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,a[N],pre[N],hug[N],x;

ll bs(ll x){
	ll l = 0;
	ll r = 2*n-1;
	while(l <= r){
		ll mid = (l+r)/2;
		if(mid != 0 and pre[mid-1] < x and pre[mid] >= x) return mid;
		if(pre[mid] > x) r = mid-1;
		else l = mid+1;
	}
	return l-1;
}

void solve(){
	cin>>n>>x;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		a[n+i] = a[i];
	}
	pre[0] = a[0];
	hug[0] = a[0]*(a[0]+1)/2;
	for(int i = 1; i < 2*n; i++){
		pre[i] = pre[i-1]+a[i];
		hug[i] = hug[i-1]+a[i]*(a[i]+1)/2;
	}
	ll ans = 0;
	for(int i = 2*n-1; i >= n; i--){
		ll y = pre[i]-x,ind,d;
		ind = bs(y+1);
		d = pre[i]-pre[ind-1]-x;
		ll tot = hug[i]-hug[ind]+a[ind]*(a[ind]+1)/2-d*(d+1)/2;
		ans = max(ans,tot);
	}
	deb1(ans)
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}