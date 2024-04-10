#include<bits/stdc++.h>
#define N 100100
#define all(x) begin(x),end(x)
using namespace std;
vector<int> g[N];
int cyc[N],f[N],in[N];
bool vis[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void uni(int x,int y){
	int fx=find(x),fy=find(y);
	f[fx]=fy;
}
bool DFS(int u){
	in[u]=1;
	bool ans=false;
	vis[u]=true;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v]){
			if(in[v]) ans=true;
		}
		else if(DFS(v)) ans=true;
	}
	in[u]=0;
	return ans;
}
int main(){
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		uni(x,y);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&DFS(i)) cyc[find(i)]=1;
	}
	int ans=n;
	for(int i=1;i<=n;i++){
		if(f[i]==i){
			ans--;
			if(cyc[i]) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}