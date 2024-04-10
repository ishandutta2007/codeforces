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
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=1e5+123,inf=1e9,mod=1e9+7;
vector< int > g[maxn];
int n,ans[maxn],cur,dp[maxn];
inline void precalc(int v,int p){
	for(int i=0;i<g[v].size();i++){
		if(p==g[v][i])
			swap(g[v][i],g[v][g[v].size()-1]);
		if(g[v][i]!=p)
			precalc(g[v][i],v);
	}
	if(g[v].back()==p)
    	g[v].pop_back();
}
inline void dfs(int v,int k){
	int mx1,mx2;
	mx1=mx2=0;
	for(auto to:g[v]){
		dfs(to,k);
		if( dp[to]>=mx1 )      
			mx2=mx1,mx1=dp[to];
		else if( dp[to]>=mx2 ) 
			mx2=dp[to];	
	}
	if(mx1+mx2+1>=k)
		cur++,dp[v]=0;
	else
		dp[v]=mx1+1;
}
inline void calc(int l,int r,int a,int b){
	if(l>r)
		return;
    if(a==b){
		while(l<=r)
			ans[l++]=a;
		return;
	}
	int m=(l+r)/2;
	cur=0;
	dfs(1,m);
	int c=cur;
	ans[m]=cur;
	calc(l,m-1,a,c);
	calc(m+1,r,c,b);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
    	int v,u;
    	scanf("%d%d",&v,&u);
    	g[v].pb(u);
    	g[u].pb(v);
    }
    precalc(1,1);
    calc(1,n,n,0);

    for(int i=1;i<=n;i++)
    	printf("%d\n",ans[i]);
	return 0;
}