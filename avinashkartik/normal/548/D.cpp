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

const ll   N     =  5e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], ans[N], l[N], r[N];
stack <ll> s;

void solve(){
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	int x = *min_element(a+1,a+n+1);
	for(int i = 1; i <= n; i++) ans[i] = x;
	s.push(0);
	for(int i = 1; i <= n; i++){
		while(a[s.top()] >= a[i]) s.pop();
		l[i] = s.top();
		s.push(i);
	}
	while(s.size()) s.pop();
	s.push(n+1);
	for(int i = n; i > 0; i--){
		while(a[s.top()] >= a[i]) s.pop();
		r[i] = s.top();
		s.push(i);
	}
	for(int i = 1; i <= n; i++) ans[r[i]-l[i]-1] = max(ans[r[i]-l[i]-1],a[i]);
	for(int i = n-1; i > 0; i--) ans[i] = max(ans[i],ans[i+1]);
	for(int i = 1; i <= n; i++) cout<<ans[i]<<" ";
}

int main(){
    GODSPEED;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}