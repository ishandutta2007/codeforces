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
const ll maxn=2e5+123,inf=1e18,mod=1e9+7;
vector<int>g[maxn],comp;
int n,m,ans;
bool used[maxn];
void dfs(int v){
	used[v]=1;
	comp.pb(v);
	for(int i=0;i<g[v].size();i++)
		if(!used[g[v][i]])
			dfs(g[v][i]);
}
int main(){
	IOS
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			comp.clear();
			dfs(i);
			if(comp.size()<3)
				continue;
			int ok=1;
			for(int j=0;j<comp.size();j++)
				if(g[comp[j]].size()!=2)
					ok=0;
			ans+=ok;
		}
	}
	cout<<ans;
}