#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#define N 1010
using namespace std;
int dis[N],col[N],f[N],ans[N];
int q[N],qt,qf;
vector<int> g[N];
bool DFS(int p,int u,int c){
	f[u]=p;
	col[u]=c;
	for(int i=0;i<g[u].size();i++){
		if(col[g[u][i]]&&col[g[u][i]]==col[u]) return 0;
		else if(!col[g[u][i]]){
			if(!DFS(p,g[u][i],-c)) return 0;
		}
	}
	return 1;
}
int main(){
	int n,m,x,y,i,j;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(i=1;i<=n;i++){
		if(!col[i]){
			if(!DFS(i,i,1)){
				printf("-1\n");
				return 0;
			}
		}
	}
	y=0;
	for(i=1;i<=n;i++){
		memset(dis,-1,sizeof(dis));
		dis[i]=0;
		qt=qf=0;
		q[qt++]=i;
		dis[i]=0;
		while(qf<qt){
			x=q[qf++];
			for(j=0;j<g[x].size();j++){
				if(dis[g[x][j]]==-1){
					dis[g[x][j]]=dis[x]+1;
					q[qt++]=g[x][j];
				}
			}
		}
		if(dis[x]>ans[f[i]]) ans[f[i]]=dis[x];
	}
	for(i=1;i<=n;i++) if(f[i]==i) y+=ans[i];
	printf("%d\n",y);
	return 0;
}