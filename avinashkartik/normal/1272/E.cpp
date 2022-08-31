#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define	 x                     first                 
#define  y                     second                
 
const ll   N     =  1e+6+5;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,dp[N],a[N],vis[N];
vll adj[N];
queue <ll> q;

void solve(ll x){
	if(x - a[x] >= 0){
		adj[x-a[x]].push_back(x);
		if((a[x]+a[x-a[x]])%2 == 1){
			dp[x] = 1;
			q.push(x);
		}
	}
	if(x + a[x] <= n-1){
		adj[x+a[x]].push_back(x);
		if((a[x]+a[x+a[x]])%2 == 1){
			if(dp[x] == 0) q.push(x);
			dp[x] = 1;
		}
	}
}


int main(){
	fastio;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	int key = 0;
	for(int i = 0; i < n; i++){
		solve(i);
	}

	while(!q.empty()){
		ll x = q.front();
		q.pop();
		for(auto it : adj[x]){
			if(dp[it] == 0){
				dp[it] = dp[x]+1;
				q.push(it);
			}
		}
	}

	for(int i = 0; i < n; i++){ 
		if(dp[i] == 0)cout<<-1<<" ";
		else cout<<dp[i]<<" ";
	}

	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}