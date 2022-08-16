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
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  205;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n;

ll ch(ll mid){
	ll res = 0;
	for(ll i = 0, j = 1; j <= mid; i++, j *= 10){
		ll st = j-1, en = min(mid,j*10-1);
		res += (i+1)*((mid-st)*(mid-st+1)/2 - (mid-en)*(mid-en+1)/2);
	}
	return res;
}

ll bs(){
	ll l = 0, r = 1e9, ans = 0;
	while(l <= r){
		ll mid = (l+r)/2;
		if(ch(mid) >= n){
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	return ans;
}

ll ch2(ll mid){
	ll res = 0;
	for(ll i = 0, j = 1; j <= mid; i++, j *= 10){
		ll st = j-1, en = min(mid,j*10-1);
		res += (i+1)*(en-st);
	}
	return res;
}

ll bs2(){
	ll l = 0, r = 1e18, ans = 0;
	while(l <= r){
		ll mid = (l+r)/2;
		if(ch2(mid) >= n){
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	return ans;
}

void solve(){
	cin>>n;
	ll x = bs();
	n -= ch(x-1);
	ll y = bs2();
	n -= ch2(y-1);
    vll v;
	while(y){v.pb(y%10), y /= 10;}
	reverse(v.begin(), v.end());
	deb1(v[n-1])
}

int main(){
    GODSPEED;
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}