// Tima the best
#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+123,inf=1e18,mod=1e9+7;
vector<int>g[maxn];
int n;
double ans;
void dfs(int v,int p, int lvl){
	ans+=1.0/lvl;
	for( auto to:g[v] )
		if(to!=p)	
			dfs(to,v,lvl+1);
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
    #endif     
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1,1,1);
	cout<<fixed<<setprecision(20)<<ans;
}