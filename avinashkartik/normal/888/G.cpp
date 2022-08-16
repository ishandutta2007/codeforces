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

const ll   N     =  3e5+8;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N];

ll minxor(int i, int l1, int r1, int l2, int r2){
	if(r1 <= l1 or r2 <= l2) return INF;
	if(i < 0) return 0;
	ll mid1 = l1, mid2 = l2;
	while(mid1 < r1 and (a[mid1]&(1ll<<i)) == 0) mid1++;
	while(mid2 < r2 and (a[mid2]&(1ll<<i)) == 0) mid2++;
	if ((l1 < mid1 && l2 < mid2) || (mid1 < r1 && mid2 < r2))
		return min(minxor(i-1,l1,mid1,l2,mid2),minxor(i-1,mid1,r1,mid2,r2));
	else
		return min(minxor(i-1,l1,mid1,mid2,r2),minxor(i-1,mid1,r1,l2,mid2)) + (1ll<<i);
}

ll rec(ll i, ll l, ll r){
	if(i < 0 or r-l <= 1) return 0;
	ll mid = l;
	while(mid < r and (a[mid]&(1ll<<i)) == 0) mid++;
	ll cost = rec(i-1,l,mid)+rec(i-1,mid,r);
	if(l < mid and r > mid) cost += minxor(i-1,l,mid,mid,r) + (1ll<<i);
	return cost;
}

void solve(){
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	deb1(rec(30,1,n+1));
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