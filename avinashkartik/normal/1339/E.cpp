#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio                ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f                     first                 
#define  s                     second
#define  endl                  "\n"
#define  pb                    push_back  
#define  mset(a,x)             memset(a,x,sizeof(a))             
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll t=1,n,m,k,ans,cubic,a[N];

void solve(){
	cin>>n;
	ll k = ceil((ld)n/3);
	ll s = 1;
	ll d = 1;
	while(d < k){
		s <<= 2;
		d += s;
	}
	d -= s;
	ll a = k-d+s-1;
	ll b = 0;
	while(1){
		ll x = a&(s<<1);
		ll y = a&(s);
		if(x == 0 and y == s)
			b += s<<1;
		else if(x == (s<<1) and y == 0)
			b += s+(s<<1);
		else if(x == (s<<1) and y == s)
			b += s;
		if(s == 1)
			break;
		s >>= 2;
	}
	if(n%3 == 1)
		cout<<a<<endl;
	else if(n%3 == 2)
		cout<<b<<endl;
	else
		cout<<(a^b)<<endl;
}

int main(){
    fastio;
    cin>>t;
    for(int i = 0; i < t; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}