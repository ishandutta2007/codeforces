#include<cstdio>
#include<vector>
#define N 100100
#define K 1001000
#define Q 1000000007
using namespace std;
vector<int> q[N],rq[N];
vector<int> g[N],val[N];
int up[N],down[N],f[N];
int cost[K],ans;
bool vis[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void DFS(int u,int p){
	vis[u]=true;
	f[u]=u;
	for(int i=0;i<q[u].size();i++){
		int v=q[u][i];
		if(vis[v]){
			int lca=find(v);
			up[u]++,down[v]++;
			up[lca]--,down[lca]--;
		}
	}
	for(int i=0;i<rq[u].size();i++){
		int v=rq[u][i];
		if(vis[v]){
			int lca=find(v);
			down[u]++,up[v]++;
			up[lca]--,down[lca]--;
		}
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p) continue;
		DFS(v,u);
	}
	f[u]=p;
}
void count(int u,int p,int x){
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p) continue;
		count(v,u,val[u][i]);
		up[u]+=up[v];
		down[u]+=down[v];
	}
	if(x==1){
		ans=(ans+cost[up[u]])%Q;
	}
	else if(x==-1){
		ans=(ans+cost[down[u]])%Q;
	}
}
int main(){
	cost[0]=0;
	cost[1]=1;
	for(int i=2;i<K;i++){
		cost[i]=(cost[i-1]+cost[i-1]+1)%Q;
	}
	int n,k,x,y,z;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(y);
		val[x].push_back(z);
		g[y].push_back(x);
		val[y].push_back(-z);
	}
	scanf("%d",&k);
	x=1;
	for(int i=0;i<k;i++){
		scanf("%d",&y);
		q[x].push_back(y);
		rq[y].push_back(x);
		x=y;
	}
	DFS(1,0);
	count(1,0,0);
	printf("%d\n",ans);
	return 0;
}