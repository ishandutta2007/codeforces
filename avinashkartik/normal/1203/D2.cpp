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

ll test = 1, n, m, pre[N], suf[N];
string s, t;

int bs(ll x, ll R){
	int l = 0, r = R, ans = -1;
	while(l <= r){
		int mid = (l+r)/2;
		if(pre[mid] >= x){
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	return ans;
}

void solve(){
	cin>>s>>t;
	n = s.size();
	m = t.size();
	s = '.'+s+'.';
	t = '#'+t+'#';
	for(int i = 1, j = 1; i <= n; i++){
		pre[i] = pre[i-1];
		if(s[i] == t[j]) pre[i]++, j++;
	}
	for(int i = n, j = m; i > 0; i--){
		suf[i] = suf[i+1];
		if(s[i] == t[j]) suf[i]++, j--;
	}
	ll ans = 0;
	for(int i = 0; i <= n; i++){
		ll j = bs(m-suf[i+1],i);
		if(j == -1) continue;
		ans = max(ans,i-j);
	}
	deb1(ans)
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