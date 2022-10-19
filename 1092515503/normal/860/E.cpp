#include<bits/stdc++.h>
using namespace std;
#define int long long
int anc[500100][20],head[500100],cnt,n,rt,dfn[500100],dep[500100],lim,stk[500100],val[500100],fl[500100],fr[500100],f[500100],tp,tot;
struct node{
	int to,next;
}edge[500100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
vector<int>v[500100];
void dfs_dep(int x){
//	printf("%d\n",x);
	dfn[x]=++tot,v[dep[x]].push_back(x),lim=max(lim,dep[x]);
	for(int i=head[x];i!=-1;i=edge[i].next)dep[edge[i].to]=dep[x]+1,dfs_dep(edge[i].to);
}
int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	for(int i=19;i>=0;i--)if(dep[x]<=dep[y]-(1<<i))y=anc[y][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
signed main(){
	scanf("%lld",&n),memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++){
		scanf("%lld",&anc[i][0]);
		if(!anc[i][0])rt=i;
		else ae(anc[i][0],i);
	}
	for(int j=1;j<19;j++)for(int i=1;i<=n;i++)anc[i][j]=anc[anc[i][j-1]][j-1];
	dfs_dep(rt);
	for(int i=0;i<=lim;i++){
//		printf("DEP:%d\n",i);
		int sz=v[i].size();
		if(sz==1){
			f[v[i][0]]=f[anc[v[i][0]][0]]+dep[v[i][0]];
			continue;
		}
		sort(v[i].begin(),v[i].end(),cmp);
//		for(int j=0;j<sz;j++)printf("%d ",v[i][j]);puts("");
		tp=0,stk[0]=0;
//		puts("LDP:");
		for(int j=1;j<sz;j++){
			int LCA=dep[lca(v[i][j-1],v[i][j])]+1;
			while(tp&&val[tp]>=LCA)tp--;
			fl[v[i][j]]=fl[v[i][stk[tp]]]+(j-stk[tp])*LCA;
			stk[++tp]=j,val[tp]=LCA;
		}
		tp=0,stk[0]=sz-1;
//		puts("RDP:");
		for(int j=sz-2;j>=0;j--){
			int LCA=dep[lca(v[i][j+1],v[i][j])]+1;
//			printf("(%d,%d):%d\n",v[i][j+1],v[i][j],LCA);
			while(tp&&val[tp]>=LCA)tp--;
			fr[v[i][j]]=fr[v[i][stk[tp]]]+(stk[tp]-j)*LCA;
			stk[++tp]=j,val[tp]=LCA;
		}
		for(int j=0;j<sz;j++)f[v[i][j]]=f[anc[v[i][j]][0]]+fl[v[i][j]]+fr[v[i][j]]+dep[v[i][j]];
//		for(int j=0;j<sz;j++)printf("POS:%d FA:%d L:%d R:%d DEP:%d\n",v[i][j],f[anc[v[i][j]][0]],fl[v[i][j]],fr[v[i][j]],dep[v[i][j]]);
	}
	for(int i=1;i<=n;i++)printf("%lld ",f[i]);
	return 0;
}