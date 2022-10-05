#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
 
#include <cstring>
#include <string>
#include <cmath>    
#include <algorithm>
 
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>                                                      
#include <stack>
#include <list>
#include <deque>                                              
 
#include <ctime>
#include <cassert> 
 
#define nm "C" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ld long double                                                                                                             	
#define ll long long                                                                                                            
#define ull unsigned long long 
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define Bystro ios_base::sync_with_stdio(0);

using namespace std;                    
const ll maxn=1e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e17,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
vector<int> g[maxn];
int tin[maxn],tout[maxn],timer,up[maxn][20];
int n,q,m,ans[maxn];
pair<int,int>a[maxn];                
void dfs(int v, int p){
	tin[v]=++timer;
	up[v][0]=p;

	for(int i=1;i<20;i++)
		up[v][i]= up[ up[v][i-1] ][i-1];
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(to!=p)
			dfs(to,v);
	}
	tout[v]=++timer;
}

void dfs2(int v, int p){
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(to!=p){
			dfs2(to,v);
			ans[v]+=ans[to];
		}
	}
}
bool upper(int p,  int v){
	return tin[p]<=tin[v] && tout[p]>=tout[v];
}
int lca(int v, int u){
	if(upper(v,u))
		return v;
	if(upper(u,v))
		return u;
	for(int i=19;i>=0;i--)	
		if(!upper(up[v][i],u))
			v=up[v][i];
	return up[v][0];	
}
int main(){    
	Bystro
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[v].pb(u);
		g[u].pb(v);
		a[i]=mp(u,v);
	}
	dfs(1,1);                 
	cin>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		ans[v]++;
		ans[u]++;
		ans[lca(u,v)]-=2;
	}
	dfs2(1,1);
	for(int i=1;i<n;i++)
		if( up[a[i].f][0]==a[i].s)
			cout<<ans[a[i].f]<<" ";
		else
			cout<<ans[a[i].s]<<" ";
}