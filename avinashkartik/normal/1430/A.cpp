#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e5+5;
const ll   M     =  4e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, dp[1005];

void solve(){
	cin >> n;
	dp[0] = 1, dp[3] = 1, dp[5] = 1, dp[6] = 1, dp[7] = 1;
	for(int i = 8; i <= n; i++){
		dp[i] = dp[i-3] | dp[i-5] | dp[i-7];
	}
	if(dp[n] == 0) deb1(-1)
	else{
		int ct3 = 0, ct5 = 0, ct7 = 0;
		while(n){
			if(n >= 3 and dp[n-3]){
				ct3++, n -= 3;
			} else if(n >= 5 and dp[n-5]){
				ct5++, n -= 5;
			} else {
				ct7++, n -= 7;
			}
		}
		deb3(ct3, ct5, ct7)
	}
}

int main(){
	GODSPEED;
	int test = 1;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}