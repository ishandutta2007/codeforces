#include<bits/stdc++.h>
using namespace std;
const int lim=50000000;
int n,m,a[20];
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
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head)),S=n*n,T=n*n+1;
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z),a[--x]+=z,a[--y]-=z;
		for(int j=1;j<n;j++)ae(y*n+(j-1),x*n+j,0x3f3f3f3f);
		ae(S,x*n,0x3f3f3f3f);
	}
	for(int i=0;i<n;i++){
		ae(S,i*n,lim);
		for(int j=1;j<n;j++)ae(i*n+(j-1),i*n+j,lim+a[i]*j);
		ae(i*n+n-1,T,0x3f3f3f3f);
	}
	Dinic();
//	printf("%d\n",res-lim*n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(!dep[i*n+j]){printf("%d ",j);break;}
	return 0;
}