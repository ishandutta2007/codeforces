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
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int test = 1, n, m, dp[N], ct[22][22];
string s;

int mem(int ind, int msk){
	if(ind == m) return 0;
	if(dp[msk] != -1) return dp[msk];
	dp[msk] = INFi;
	for(int i = 0; i < m; i++){
		if(((1<<i)&msk) == 0){
			int res = 0;
			for(int j = 0; j < m; j++){
				if(j == i) continue;
				if((1<<j)&msk) res += ct[j][i]*ind;
				else res -= ct[j][i]*ind;
			}
			dp[msk] = min(dp[msk],mem(ind+1,msk|(1<<i))+res);
		}
	}
	return dp[msk];
}

void solve(){
	mset(dp,-1);
	cin>>n>>m>>s;
	for(int i = 1; i < n; i++) ct[s[i-1]-'a'][s[i]-'a']++, ct[s[i]-'a'][s[i-1]-'a']++;
	deb1(mem(0,0));
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