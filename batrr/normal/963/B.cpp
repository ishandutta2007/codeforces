/*
Tima the best
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define nm "A" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO(nm) freopen(nm".in","r",stdin); freopen(nm".out","w",stdout);                  
#define ll long long                                                                                                           
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=5e5+123,N=500,mod=1e9+9; 
vector<int>g[maxn];
int n,m,dp[maxn][2];// dp[v][1]-have p ,0 - no
vector<int>ans; 
void dfs(int v, int p){
	vector<int> v1,v2,v3;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(to!=p){
			dfs(to,v);
			if(dp[to][0] && !dp[to][1])
				v1.pb(to);
			if(dp[to][1] && !dp[to][0])
				v2.pb(to);
            if(dp[to][0] && dp[to][1])
				v3.pb(to);
   		}
	}	
	if( ( v1.size()%2==0 || v3.size()>0) )
		dp[v][0]=1;

	if( v!=1 && ( v1.size()%2==1 || v3.size()>0) )
		dp[v][1]=1;
    
}

void dfs2(int v, int p,int hp){
	vector<int> v1,v2,v3;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(to!=p){
			if(dp[to][0] && !dp[to][1])
				v1.pb(to);
			if(dp[to][1] && !dp[to][0])
				v2.pb(to);
            if(dp[to][0] && dp[to][1])
				v3.pb(to);
   		}
	}	
	
    if(v1.size()%2==1-hp){
    	v1.pb(v3.back());
    	v3.pop_back();
    }
    if(hp==0){                                 
    	for(int i=0;i<v2.size();i++)
    		dfs2(v2[i],v,1);
    	for(int i=0;i<v3.size();i++)
    		dfs2(v3[i],v,1);
	    cout<<v<<endl;
	    for(int i=0;i<v1.size();i++)
    		dfs2(v1[i],v,0);
	}else{
        for(int i=0;i<v2.size();i++)
    		dfs2(v2[i],v,1);
    	for(int i=0;i<v3.size();i++)
    		dfs2(v3[i],v,1);
	    cout<<v<<endl;
	    for(int i=0;i<v1.size();i++)
    		dfs2(v1[i],v,0);
	}	
}
int main(){
	cin>>n;  
	for(int i=1;i<=n;i++){
		int v;
		cin>>v;
		if(v!=0){      
			g[v].pb(i);
			g[i].pb(v);
		}
	}
	dfs(1,1);
	if(dp[1][0]==0){
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	dfs2(1,1,0);
}