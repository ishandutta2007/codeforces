#include<bits/stdc++.h>
#define N 200100
using namespace std;
vector<int> g[N],w[N];
long long len[N],val[N];
int sz[N];
void solve1(int u,int p){
	sz[u]=1;
	val[u]=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p) continue;
		solve1(v,u);
		sz[u]+=sz[v];
		val[u]+=val[v];
		if(sz[v]&1) val[u]+=w[u][i];
	}
}
void solve2(int u,int p){
	sz[u]=1;
	len[u]=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p) continue;
		solve2(v,u);
		sz[u]+=sz[v];
		len[u]+=len[v];
		len[u]+=1LL*w[u][i]*sz[v];
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,x,y,z;
		scanf("%d",&n);
		n*=2;
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			g[x].push_back(y);
			g[y].push_back(x);
			w[x].push_back(z);
			w[y].push_back(z);
		}
		solve1(1,0);
		int u=1,p=0;
		bool flag=true;
		while(flag){
			flag=false;
			for(int i=0;i<g[u].size();i++){
				if(g[u][i]==p)  continue;
				//printf("%d->%d: %d\n",u,g[u][i],sz[g[u][i]]);
				if(sz[g[u][i]]>n/2){
					p=u;
					u=g[u][i];
					flag=true;
					break;
				}
			}
		}
		solve2(u,0);
		printf("%lld %lld\n",val[1],len[u]);
		for(int i=1;i<=n;i++){
			g[i].clear();
			w[i].clear();
		}
	}
	return 0;
}