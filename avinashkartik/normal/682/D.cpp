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
 
const ll   N     =  1e3+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,m,k,dp[N][N][15][2];
string s,t;

ll mem(int i, int j, int no, int f){
	if(i == n and j == m){
		if(no == k) return 0;
		else return -INFi;
	}
	if(dp[i][j][no][f] != -1) return dp[i][j][no][f];
	ll ans = 0;
	if(s[i] == t[j] and i != n and j != m){
		if(f == 1) ans = mem(i+1,j+1,no,1)+1;
		if(no != k) ans = max(ans,mem(i+1,j+1,no+1,1)+1);
	}
	if(i != n){
		ans = max(ans,mem(i+1,j,no,0));
	}
	if(j != m){
		ans = max(ans,mem(i,j+1,no,0));
	}
	return dp[i][j][no][f] = ans;
}

void solve(){
	mset(dp,-1);
	cin>>n>>m>>k;
	cin>>s>>t;
	deb1(mem(0,0,0,0))
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}