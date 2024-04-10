#include<bits/stdc++.h>
using namespace std;
int n,m,q,dsu[100100],dis[100100];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
void merge(int x,int y){x=find(x),y=find(y);if(x!=y)dsu[y]=x;}
namespace Tree{
	int head[200100],cnt;
	struct Edge{
		int to,next;
	}edge[400100];
	void ae(int u,int v){
		edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
		edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
	}
//----------------------------------------------------------
	int tot;
	bool odd[200100],ok[200100][20];
	int anc[200100][20],dep[200100];
	void dfs(int x,int fa){
		anc[x][0]=fa,ok[x][0]=odd[fa],dep[x]=dep[fa]+1;
		for(int i=1;(1<<i)<dep[x];i++)anc[x][i]=anc[anc[x][i-1]][i-1],ok[x][i]=(ok[x][i-1]|ok[anc[x][i-1]][i-1]);
		for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa)dfs(edge[i].to,x);
	}
	bool query(int x,int y){
		if(find(x)!=find(y))return false;
		if((dis[x]^dis[y])&1)return true;
		if(dep[x]>dep[y])swap(x,y);
		bool ret=false;
		for(int i=19;i>=0;i--)if(dep[x]<=dep[y]-(1<<i))ret|=ok[y][i],y=anc[y][i];
		if(x==y)return ret;
		for(int i=19;i>=0;i--)if(anc[x][i]!=anc[y][i])ret|=(ok[x][i]|ok[y][i]),x=anc[x][i],y=anc[y][i];
		return ret|ok[x][0];
	}
}
namespace Graph{
	int head[100100],cnt;
	struct Edge{
		int to,next;
	}edge[200100];
	void ae(int u,int v){
		edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
		edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
	}
//-----------------------------------------------------------
	priority_queue<pair<int,int> >q;
	bool vis[100100];
	void Dijkstra(int S){
		dis[S]=0,q.push(make_pair(0,S));
		while(!q.empty()){
			int x=q.top().second;q.pop();
			if(vis[x])continue;vis[x]=true;
			for(int i=head[x],y;i!=-1;i=edge[i].next)if(dis[y=edge[i].to]>dis[x]+1)dis[y]=dis[x]+1,q.push(make_pair(-dis[y],y));
		}
	}
//-----------------------------------------------------------
	stack<int>s;
	int dfn[100100],low[100100],tot,col[100100],DYE[100100];
	bool Dye(int x){
		for(int i=head[x];i!=-1;i=edge[i].next){
			if(col[edge[i].to]!=Tree::tot)continue;
			if(!DYE[edge[i].to]){
				DYE[edge[i].to]=DYE[x]^3;
				if(Dye(edge[i].to))return true;
			}else if(DYE[edge[i].to]==DYE[x])return true;
		}
		return false;
	}
	void Tarjan(int x){
		dfn[x]=low[x]=++tot,s.push(x);
		for(int i=head[x];i!=-1;i=edge[i].next){
			if(!dfn[edge[i].to]){
				Tarjan(edge[i].to),low[x]=min(low[x],low[edge[i].to]);
				if(low[edge[i].to]>=dfn[x]){
					Tree::tot++;
					while(true){
						int y=s.top();
						Tree::ae(Tree::tot,y),col[y]=Tree::tot,DYE[y]=0,s.pop();
						if(y==edge[i].to)break;
					}
					Tree::ae(Tree::tot,x),DYE[x]=1,col[x]=Tree::tot;
					Tree::odd[Tree::tot]=Dye(x);
				}
			}else low[x]=min(low[x],dfn[edge[i].to]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m),Tree::tot=n,memset(Tree::head,-1,sizeof(Tree::head)),memset(Graph::head,-1,sizeof(Graph::head)),memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)dsu[i]=i;
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),Graph::ae(x,y),merge(x,y);
	for(int i=1;i<=n;i++){
		if(dsu[i]!=i)continue;
		Graph::Dijkstra(i);
		while(!Graph::s.empty())Graph::s.pop();
		Graph::Tarjan(i);
		Tree::dfs(i,0);
	}
	scanf("%d",&q);
	for(int i=1,x,y;i<=q;i++)scanf("%d%d",&x,&y),puts(Tree::query(x,y)?"Yes":"No");
	return 0;
}
/*
7 7
1 3
1 4
2 3
2 4
5 6
6 7
7 5
8
1 2
1 3
1 4
2 4
1 5
5 6
5 7
6 7

5 5
1 2
2 3
3 4
4 5
5 1
4
1 2
1 3
1 4
1 5
*/