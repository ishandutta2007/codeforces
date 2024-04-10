#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,f[5010][5010][2],head[5010],cnt,c[5010],d[5010],sz[5010],g[5010];//0:anything in the subtree 1:path from root must hold
struct node{
	int to,next;
}edge[5010];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
void dfs(int x){
	sz[x]=1,f[x][0][0]=0,f[x][1][0]=c[x],f[x][1][1]=c[x]-d[x];
	for(int e=head[x],y;e!=-1;e=edge[e].next){
		y=edge[e].to,dfs(y);
		for(int i=0;i<=sz[x]+sz[y];i++)g[i]=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=sz[x];i++)for(int j=0;j<=sz[y];j++)g[i+j]=min(g[i+j],f[x][i][1]+min(f[y][j][0],f[y][j][1]));
		for(int i=0;i<=sz[x]+sz[y];i++)f[x][i][1]=g[i];
		for(int i=0;i<=sz[x]+sz[y];i++)g[i]=0x3f3f3f3f;
		for(int i=0;i<=sz[x];i++)for(int j=0;j<=sz[y];j++)g[i+j]=min(g[i+j],f[x][i][0]+f[y][j][0]);
		for(int i=0;i<=sz[x]+sz[y];i++)f[x][i][0]=g[i];
		sz[x]+=sz[y];
	}
}
signed main(){
	scanf("%lld%lld",&n,&m),memset(head,-1,sizeof(head)),memset(f,0x3f,sizeof(f));
	for(int i=1,x;i<=n;i++){
		scanf("%lld%lld",&c[i],&d[i]);
		if(i>1)scanf("%lld",&x),ae(x,i);
	}
	dfs(1);
//	for(int i=1;i<=n;i++)printf("%d ",sz[i]);puts("");
	for(int i=1;i<=n+1;i++){
		if(min(f[1][i][0],f[1][i][1])<=m)continue;
		printf("%lld\n",i-1);break;
	}
	return 0;
}