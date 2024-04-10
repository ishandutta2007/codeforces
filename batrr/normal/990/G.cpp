#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+123,inf=1e9+123,LOG=18,block=450,mod=1e9+7,N=2e5;
vector<int>g[maxn],dv[maxn];
int n,pr[maxn],sz[maxn],p[maxn],was[maxn],x[maxn];
ll dp[maxn];
void dfs(int v,int p){
	for(int j=1;j*j<=x[v];j++){
		if(x[v]%j==0){
			dv[j].pb(v);
			if(j*j!=x[v])
				dv[x[v]/j].pb(v);
		}
	}
	pr[v]=p;
	for(auto to:g[v] )
		if(to!=p)	
			dfs(to,v);
}   
int main(){
    #ifdef LOCAL
		freopen ("test.in", "r", stdin);
    #endif
    scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<n;i++){
		int v,u;
		scanf("%d%d",&v,&u);
        g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1,1);
	for(int i=1;i<=N;i++){
		
		for( auto v:dv[i] )
			was[v]=1;

        for( auto v:dv[i] )
			if( v!=1 && was[pr[v]] )
				p[v]=p[pr[v]],sz[p[v]]++;
        	else
        		p[v]=v,sz[v]=1;
        
        for( auto v:dv[i] )
			if(p[v]==v)
		    	dp[i]+=1ll*sz[v]*(sz[v]+1)/2;
		
		for( auto v:dv[i] )
			was[v]=0;
	
	}
	for(int i=N;i>=1;i--)
		for(int j=i+i;j<=N;j+=i)
			dp[i]-=dp[j];

	for(int i=1;i<=N;i++)
		if(dp[i])
	        printf("%d %lld\n",i,dp[i]);
}