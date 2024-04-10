#include<bits/stdc++.h>
using namespace std;
int n,m;
namespace Tj{
	int head[300100],cnt,tot,dfn[300100],low[300100],col[300100],c;
	struct node{
		int to,next;
		bool bri;
	}edge[600100];
	void ae(int u,int v){
		edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
		edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
	}
	void dfs(int x,int fa){
		dfn[x]=low[x]=++tot;
		for(int i=head[x],y;i!=-1;i=edge[i].next){
			if((y=edge[i].to)==fa)continue;
			if(!dfn[y]){
				dfs(y,x),low[x]=min(low[x],low[y]);
				if(dfn[x]<low[y])edge[i].bri=edge[i^1].bri=true;
			}else low[x]=min(low[x],dfn[y]);
		}
	}
	void dye(int x){
		col[x]=c;
		for(int i=head[x];i!=-1;i=edge[i].next)if(!col[edge[i].to]&&!edge[i].bri)dye(edge[i].to);
	}
}
namespace Tree{
	int head[300100],cnt,f[300100],res;
	struct node{
		int to,next;
	}edge[600100];
	void ae(int u,int v){
		edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	}
	void dfs(int x,int fa){
		for(int i=head[x];i!=-1;i=edge[i].next){
			if(edge[i].to==fa)continue;
			dfs(edge[i].to,x);
			res=max(res,f[x]+f[edge[i].to]+1);
			f[x]=max(f[x],f[edge[i].to]+1);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m),memset(Tj::head,-1,sizeof(Tj::head)),memset(Tree::head,-1,sizeof(Tree::head));
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),Tj::ae(x,y);
	for(int i=1;i<=n;i++)if(!Tj::dfn[i])Tj::dfs(i,0);
	for(int i=1;i<=n;i++)if(!Tj::col[i])Tj::c++,Tj::dye(i);
	for(int i=1;i<=n;i++)for(int j=Tj::head[i];j!=-1;j=Tj::edge[j].next)if(Tj::edge[j].bri)Tree::ae(Tj::col[i],Tj::col[Tj::edge[j].to]);
	Tree::dfs(1,0);
	printf("%d\n",Tree::res);
	return 0;
}