#include<bits/stdc++.h>
using namespace std;
const int LIM=1000000;
int n,m,a[110],b[110],c[110],L[110],R[110],id[110][2100],tot;
namespace MaxFlow{
	const int N=201000,M=2001000;
	int head[N],cur[N],dep[N],cnt,S,T,res;
	struct node{int to,next,val;}edge[M];
	void ae(int u,int v,int w){
//		printf("%d %d %d\n",u,v,w);
		edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
		edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	queue<int>q;
	inline bool bfs(){
		memset(dep,0,sizeof(dep)),q.push(S),dep[S]=1;
		while(!q.empty()){
			register int x=q.front();q.pop();
			for(register int i=cur[x]=head[x];i!=-1;i=edge[i].next)if(edge[i].val&&!dep[edge[i].to])dep[edge[i].to]=dep[x]+1,q.push(edge[i].to);
		}
		return dep[T]>0;
	}
	bool reach;
	inline int dfs(int x,int flow){
		if(x==T){res+=flow,reach=true;return flow;}
		int used=0;
		for(register int &i=cur[x];i!=-1;i=edge[i].next){
			if(!edge[i].val||dep[edge[i].to]!=dep[x]+1)continue;
			register int ff=dfs(edge[i].to,min(edge[i].val,flow-used));
			if(ff){edge[i].val-=ff,edge[i^1].val+=ff,used+=ff;if(used==flow)break;}
		}
		return used;
	}
	inline void Dinic(){while(bfs()){reach=true;while(reach)reach=false,dfs(S,0x3f3f3f3f);}}
}
using namespace MaxFlow;
#define ID(x,y) id[x][(y)+L[x]]
#define VL(x,y) (a[x]*(y)*(y)+b[x]*(y)+c[x])
int main(){
	scanf("%d%d",&n,&m),S=1,T=2,tot=2,memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&L[i],&R[i]);
		for(int j=L[i];j<=R[i];j++)ID(i,j)=++tot;
		ae(S,ID(i,L[i]),LIM-VL(i,L[i]));
		for(int j=L[i]+1;j<=R[i];j++)ae(ID(i,j-1),ID(i,j),LIM-VL(i,j));
		ae(ID(i,R[i]),T,0x3f3f3f3f);
	}
	for(int i=1,u,v,d;i<=m;i++){
		scanf("%d%d%d",&u,&v,&d);
		if(L[v]<=L[u]-d-1&&L[u]-d-1<=R[v])ae(S,ID(v,L[u]-d-1),0x3f3f3f3f);
		for(int j=L[u];j<=R[u];j++){
			if(j-d<L[v])continue;
			if(j-d<=R[v])ae(ID(u,j),ID(v,j-d),0x3f3f3f3f);
			else ae(ID(u,j),T,0x3f3f3f3f);
		}
	}
	Dinic();
	printf("%d\n",LIM*n-res);
	return 0;
}
/*
3 2
-1 0 2
1 -1 -1
-2 1 0
-2 -2
1 2
-1 0
2 1 -1
2 1 -2
*/