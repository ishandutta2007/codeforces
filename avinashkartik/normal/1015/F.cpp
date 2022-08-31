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

ll test = 1, n, m, dp[N][N][N][2], lps[N];
string s;

ll mem(int i, int bal, int k, int f){
	if(i == 2*n) return bal == 0 and f;
	if(dp[i][bal][k][f] != -1) return dp[i][bal][k][f];
	ll ans = 0, nk = 0, nf = 0;
	if(bal){
		if(s[k+1] == ')') nk = k+1;
		else nk = lps[k];
		if(nk == m) nk = 0, nf = 1;
		ans += mem(i+1,bal-1,nk,f|nf);
	}
	nk = 0, nf = 0;
	if(s[k+1] == '(') nk = k+1;
	else nk = lps[k];
	if(nk == m) nk = 0, nf = 1;
	ans += mem(i+1,bal+1,nk,f|nf);
	return dp[i][bal][k][f] = ans%mod;
}

ll check(ll i, string t){
	ll tsz = i+1;
	for(int k = i+1; k >= 1; k--){
		if(s.substr(1, k) == t.substr(tsz-k+1, k))
			return k;
	}
	return 0;
}

void solve(){
	mset(dp,-1);
	cin>>n>>s;
	m = s.size();
	s = '.'+s+'.';
	string temp;
	for(int i = 0; i < m; i++){
		temp += s[i];
		if(s[i+1] == '(') lps[i] = check(i,temp+')');
		else lps[i] = check(i,temp+'(');
	}
	deb1(mem(0,0,0,0));
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