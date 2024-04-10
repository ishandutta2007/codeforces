#include<bits/stdc++.h>
using namespace std;
int n,m,q,dfn[200100],low[200100],col[200100],c,stk[200100],tp,head[200100],cnt,tot;
struct node{int to,next;}edge[400100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
}
void Tarjan(int x,int fi){
	dfn[x]=low[x]=++tot,stk[++tp]=x;
	for(int i=head[x],y;i!=-1;i=edge[i].next){
		if(!dfn[y=edge[i].to])Tarjan(y,i),low[x]=min(low[x],low[y]);
		else if((i^fi)!=1)low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]!=low[x])return;
	c++;int y;do col[y=stk[tp--]]=c;while(y!=x);
}
int anc[20][200100],dep[200100],d[2][200100];
vector<int>v[200100];
void dfs(int x,int fa){
	anc[0][x]=fa,dep[x]=dep[fa]+1;
	for(int i=1;i<=17;i++)anc[i][x]=anc[i-1][anc[i-1][x]];
	for(auto y:v[x])if(y!=fa)dfs(y,x);
}
int LCA(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	for(int i=17;i>=0;i--)if(dep[x]<=dep[y]-(1<<i))y=anc[i][y];
	if(x==y)return x;
	for(int i=17;i>=0;i--)if(anc[i][x]!=anc[i][y])x=anc[i][x],y=anc[i][y];
	return anc[0][x];
}
void sfd(int x,int fa){
	for(auto y:v[x])if(y!=fa)sfd(y,x),d[0][x]+=d[0][y],d[1][x]+=d[1][y];
	if(d[0][x]&&d[1][x]){puts("No");exit(0);}
}
int main(){
	scanf("%d%d%d",&n,&m,&q),memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),ae(x,y);
	for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i,-1);
	for(int x=1;x<=n;x++)for(int i=head[x];i!=-1;i=edge[i].next)
		if(col[x]!=col[edge[i].to])v[col[x]].push_back(col[edge[i].to]);
	for(int i=1;i<=c;i++)if(!dep[i])dfs(i,0);
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y),x=col[x],y=col[y];
		int z=LCA(x,y);
		if(!z){puts("No");return 0;}
		d[0][x]++,d[0][z]--;
		d[1][y]++,d[1][z]--;
	}
	for(int i=1;i<=c;i++)if(dep[i]==1)sfd(i,0);
	puts("Yes");
	return 0;
}