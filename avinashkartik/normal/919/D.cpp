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
 
const ll   N     =  3e+5+8;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,m,u,v,visit[N],recurSt[N],dp[N][26],ans=0;
vll adj[N],rev[N];
string s;

void dfs(ll x){
	if(!visit[x]){
		visit[x] = 1;
		ll maxx[26]={};
		for(auto it : adj[x]){
			dfs(it);
			for(int i = 0; i < 26; i++){
				if(dp[it][i] >= maxx[i]){
					maxx[i] = dp[it][i];
				}
			}
		}
		maxx[(s[x-1]-'a')]++;
		for(int i = 0; i < 26; i++){
			dp[x][i] = maxx[i];
			ans = max(ans,maxx[i]);
		}
		//cout<<x<<" "<<ans<<endl;
	}
}

int cycleUtil(ll child){
	recurSt[child]=1;
	visit[child]=1;
	for(auto it: adj[child]){
		if(!visit[it] && cycleUtil(it)) return 1;
		else if(recurSt[it]) return 1;
	}
	recurSt[child]=0;
	return 0;
}
 
int isCycle(){
	memset(visit,0,sizeof(visit));
	memset(recurSt,0,sizeof(recurSt));
	for(int i = 1; i <= n; i++) if(cycleUtil(i)) return 1;
	return 0;
}


int main(){
	fastio;
	cin>>n>>m;
	cin>>s;
	for(int i = 0; i < m; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		rev[v].push_back(u);
	}

	if(isCycle() == 1){
		cout<<-1<<endl;
		return 0;
	}
	memset(visit,0,sizeof(visit));
	for(int i = 1; i <= n; i++){
		if(rev[i].size() == 0){
			dfs(i);
		}
	}
	cout<<ans<<endl;

	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}