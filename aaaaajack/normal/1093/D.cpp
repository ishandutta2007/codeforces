#include<bits/stdc++.h>
#define N 300100
#define Q 998244353
using namespace std;
vector<int> g[N];
int vis[N];
bool DFS(int u, int c, int &c0, int &c1){
	vis[u]=c;
	c0++;
	bool gg=true;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v]){
			if(vis[v]==vis[u]) gg=false;
		}
		else{
			if(!DFS(v,-c,c1,c0)) gg=false;
		}
	}
	return gg;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		int x,y;
		long long ans=1;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			int c0=0,c1=0;
			if(!vis[i]){
				bool gg=DFS(i,1,c0,c1);
				if(gg){
					long long r1=1,r2=1;
					while(c0--) r1=(r1+r1)%Q;
					while(c1--) r2=(r2+r2)%Q;
					ans=ans*(r1+r2)%Q;
				}
				else ans=0;
			}
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++){
			g[i].clear();
			vis[i]=0;
		}
	}
	return 0;
}