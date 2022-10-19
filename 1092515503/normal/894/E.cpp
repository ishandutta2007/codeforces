#include<bits/stdc++.h>
using namespace std;
const int INF=1e8;
typedef long long ll;
int n,m,q,col[1001000],c;
ll val[1001000],f[1001000];
namespace SCC{
	int tot,dfn[1001000],low[1001000],head[1001000],cnt;
	struct node{
		int to,next,val;
	}edge[1001000];
	void ae(int u,int v,int w){
		edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	}
	stack<int>stk;
	void Tarjan(int x){
		dfn[x]=low[x]=++tot,stk.push(x);
		for(int i=head[x];i!=-1;i=edge[i].next){
			if(!dfn[edge[i].to])Tarjan(edge[i].to),low[x]=min(low[x],low[edge[i].to]);
			if(!col[edge[i].to])low[x]=min(low[x],dfn[edge[i].to]);
		}
		if(low[x]<dfn[x])return;
		c++;
		while(stk.top()!=x)col[stk.top()]=c,stk.pop();
		col[stk.top()]=c,stk.pop();
	}
}
namespace DAG{
	int head[1001000],cnt;
	struct node{
		int to,next,val;
	}edge[1001000];
	void ae(int u,int v,int w){
		edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	}
	void dfs(int x){
		if(f[x]!=-1)return;
		f[x]=0;
		for(int i=head[x];i!=-1;i=edge[i].next)dfs(edge[i].to),f[x]=max(f[x],f[edge[i].to]+edge[i].val);
		f[x]+=val[x];
	}
}
ll calc(int w){
	int k=(sqrt(8*w+1)-1)/2;
	return 1ll*w*(k+1)-1ll*k*(k+1)*(k+2)/6;
}
int main(){
	scanf("%d%d",&n,&m),memset(SCC::head,-1,sizeof(SCC::head)),memset(DAG::head,-1,sizeof(DAG::head));
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),SCC::ae(x,y,z);
	for(int i=1;i<=n;i++)if(!SCC::dfn[i])SCC::Tarjan(i);
	for(int i=1;i<=n;i++)for(int j=SCC::head[i];j!=-1;j=SCC::edge[j].next){
		int x=col[i],y=col[SCC::edge[j].to];
		if(x==y)val[x]+=calc(SCC::edge[j].val);
		else DAG::ae(x,y,SCC::edge[j].val);
	}
//	for(int i=1;i<=n;i++)printf("%d ",col[i]);puts("");
	memset(f,-1,sizeof(f));
	scanf("%d",&q);
	DAG::dfs(col[q]);
	printf("%lld\n",f[col[q]]);
	return 0;
}
/*
4 5
1 4 5
1 2 5
1 1 1
2 1 1
3 1 3
3
*/