#include<bits/stdc++.h>
#define N 100100
#define all(x) begin(x),end(x)
using namespace std;
int par[N][20],tt[N][20],tb[N][20],md[N],dep[N];
vector<int> g[N];
int mc[N][3];
//md[0]=-1,dep[0]=-1
int DFS(int u,int p){
	par[u][0]=p;
	dep[u]=dep[p]+1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v!=p){
			md[u]=max(md[u],DFS(v,u)+1);
			for(int j=0;j<3;j++){
				if(md[v]>md[mc[u][j]]){
					for(int k=2;k>j;k--){
						mc[u][k]=mc[u][k-1];
					}
					mc[u][j]=v;
					break;
				}
			}
		}
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v!=p){
			if(v==mc[u][0]){
				tt[v][0]=md[mc[u][1]]+1;
			}
			else{
				tt[v][0]=md[mc[u][0]]+1;
			}
			tb[v][0]=tt[v][0]+1;
		}
	}
	return md[u];
}
void build(int n){
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++){
			int k=par[i][j-1];
			par[i][j]=par[k][j-1];
			tb[i][j]=max(tb[i][j-1],tb[k][j-1]+(1<<j-1));
			tt[i][j]=max(tt[i][j-1]+(1<<j-1),tt[k][j-1]);
		}
	}
}
int lca(int u,int v){
	//required: dep[u]>=dep[v];
	for(int s=19;s>=0;s--){
		if(dep[u]-(1<<s)>=dep[v]){
			u=par[u][s];
		}
	}
	if(u==v) return u;
	for(int s=19;s>=0;s--){
		if(par[u][s]!=par[v][s]){
			u=par[u][s];
			v=par[v][s];
		}
	}
	return par[u][0];
}
int get_tb(int u,int d){
	if(d<=0) return -N;
	int res=0,pre=0;
	for(int s=0;s<20;s++){
		if(d&(1<<s)){
			res=max(tb[u][s]+pre,res);
			u=par[u][s];
			pre+=1<<s;
		}
	}
	return res;
}
int get_tt(int u,int d){
	if(d<=0) return -N;
	int res=0,pre=0;
	for(int s=0;s<20;s++){
		if(d&(1<<s)){
			pre+=1<<s;
			res=max(tt[u][s]+d-pre,res);
			u=par[u][s];
		}
	}
	return res;
}
int get_par(int u,int d){
	if(d<0) return -1;
	for(int s=0;s<20;s++){
		if(d&(1<<s)) u=par[u][s];
	}
	return u;
}
int main(){
	md[0]=dep[0]=-1;
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	DFS(1,0);
	build(n);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(dep[x]<dep[y]) swap(x,y);
		int z=lca(x,y),ans=0,dis=dep[x]+dep[y]-2*dep[z];
		int mid=get_par(x,dis/2);
		ans=max(ans,get_tb(z,dep[z])+dep[y]-dep[z]);
		ans=max(ans,get_tb(y,dep[y]-dep[z]-1));
		//printf("py&up: %d\n",ans);
		ans=max(ans,get_tt(mid,dep[mid]-dep[z]-1)+1+dep[y]-dep[z]);
		ans=max(ans,get_tb(x,mid==z?dis/2-1:dis/2));
		//printf("px: %d\n",ans);
		if(x!=z) ans=max(ans,md[x]);
		if(y!=z) ans=max(ans,md[y]);
		//printf("bot: %d\n",ans);
		int cur=0;
		int cx=get_par(x,dep[x]-dep[z]-1),cy=get_par(y,dep[y]-dep[z]-1);
		while(mc[z][cur]==cx || mc[z][cur]==cy) cur++;
		ans=max(ans,1+md[mc[z][cur]]+dep[y]-dep[z]);
		printf("%d\n",ans);
	}
	return 0;
}