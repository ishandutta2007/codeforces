// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=5e5+123,inf=1e18,mod=1e9+7,LOG=22;
vector< pair<int,int> >g[maxn];                  
int n,a[maxn],lvl[maxn],ans[maxn],sz[maxn];
int d[(1<<LOG)+132];

void dfs(int v,int p){
	lvl[v]=lvl[p]+1;
	sz[v]=1;
    for(int i=0;i<g[v].size();i++){
		int to=g[v][i].f,c=g[v][i].s-'a';
		if(to!=p){
		    a[to]=(1<<c)^a[v];
		    dfs(to,v);
	    	sz[v]+=sz[to];
		}
	}                                
}
void dfscl(int v,int p){
	d[a[v]]=-1e9;
	for(int i=0;i<g[v].size();i++){
	    int to=g[v][i].f;
		if(to!=p)
			dfscl(to,v);
	}
}


void add(int v,int p){
	d[a[v]]=max(d[a[v]],lvl[v]);
	for(int i=0;i<g[v].size();i++){
	    int to=g[v][i].f;
		if(to!=p)
			add(to,v);
	}
}
void upd(int v,int p, int V){
	ans[V]=max(ans[V],d[a[v]]+lvl[v]-2*lvl[V]);
	for(int j=0;j<LOG;j++)
		ans[V]=max(ans[V],d[a[v]^(1<<j)]+lvl[v]-2*lvl[V]);
	
	for(int i=0;i<g[v].size();i++){
	    int to=g[v][i].f;
		if(to!=p)
			upd(to,v,V);
	}
}
void solve(int v,int p,bool cl){
	int u=0;
	// get mx child
	for(int i=0;i<g[v].size();i++){
	    int to=g[v][i].f;
		if(to!=p && sz[to]>sz[u])
				u=to; 
	}
	// solve child
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i].f;
		if(to!=u && to!=p){
			solve(to,v,1);
			ans[v]=max(ans[v],ans[to]);
		}	
	}
	if(u!=0){
		solve(u,v,0);
		ans[v]=max(ans[v],ans[u]);
	}
	
	// calc ans
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i].f;
		if(to!=u && to!=p){
			upd(to,v,v);
			add(to,v);
		}	
	}

	ans[v]=max(ans[v],d[a[v]]-lvl[v]);
	for(int j=0;j<LOG;j++)
		ans[v]=max(ans[v],d[a[v]^(1<<j)]-lvl[v]);
	d[a[v]]=max(d[a[v]],lvl[v]);
	
	if( cl )
		dfscl(v,p);
}

int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
 	#endif
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
		int p;
		char ch;
		scanf("%d ",&p);
        ch=getchar();
        g[i].pb(mp(p,ch));
		g[p].pb(mp(i,ch));
	}
	for(int i=0;i<(1<<LOG)+132;i++)
		d[i]=-1e9;  
	dfs(1,1);
	solve(1,1,0);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}