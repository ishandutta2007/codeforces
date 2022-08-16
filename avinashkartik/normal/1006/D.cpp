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

ll test = 1, n, cnt[26];
string s,t;

void solve(){
    cin>>n>>s>>t;
    ll ans = 0;
    for(int i = 0; i < (n+1)/2; i++){
    	mset(cnt,0);
    	ll ct = 0, mx = 0;
    	cnt[s[i]-'a']++;
    	cnt[t[i]-'a']++;
		if(i != n-i-1) cnt[s[n-i-1]-'a']++;
		if(i != n-i-1) cnt[t[n-i-1]-'a']++;
		for(int i = 0; i < 26; i++) ct += cnt[i]%2, mx = max(mx,cnt[i]);
		ct /= 2;
		if(s[i] == s[n-i-1] and t[i] != t[n-i-1] and mx == 2) ct++;
    	//deb3(i,ct,mx)
    	ans += ct;
    }
    deb1(ans)
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