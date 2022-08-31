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
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,k;
ll dp[N][N];

ll mem(ll ind,ll p){
	if(ind == k)
		return 1;
	if(dp[ind][p] != -1) return dp[ind][p];
	dp[ind][p] = 0;
	for(int i = p; i <= n; i += p)
		dp[ind][p] = (dp[ind][p] + mem(ind+1,i))%mod;
	return dp[ind][p];
}

void solve(){
	mset(dp,-1);
	cin>>n>>k;
	cout<<mem(0,1)<<endl;
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
}