#include<bits/stdc++.h>
using namespace std;
int n,m,p,r,dis[610][610],occ[610];
namespace MaxFlow{
	const int N=10000,M=2000000;
	int head[N],cur[N],dep[N],cnt,S,T,res;
	struct node{
		int to,next,val;
	}edge[M];
	void ae(int u,int v,int w){
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
		if(x==T){
			res+=flow;
			reach=true;
			return flow;
		}
		int used=0;
		for(register int &i=cur[x];i!=-1;i=edge[i].next){
			if(!edge[i].val||dep[edge[i].to]!=dep[x]+1)continue;
			register int ff=dfs(edge[i].to,min(edge[i].val,flow-used));
			if(ff){
				edge[i].val-=ff;
				edge[i^1].val+=ff;
				used+=ff;
				if(used==flow)break;
			}
		}
		return used;
	}
	inline void Dinic(){
		while(bfs()){
			reach=true;
			while(reach)reach=false,dfs(S,0x3f3f3f3f);
		}
	}
}
using namespace MaxFlow;
int che(int ip){
	memset(head,-1,sizeof(head)),cnt=res=0;
	for(int i=1;i<=n;i++)ae(S,i,occ[i]),ae(i+n,T,1);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(dis[i][j]<=ip)ae(i,j+n,0x3f3f3f3f);
	Dinic();
	return res>=r;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&p,&r),memset(dis,0x3f3f3f3f,sizeof(dis)),S=n*2+1,T=n*2+2;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1,x;i<=p;i++)scanf("%d",&x),occ[x]++;
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),dis[x][y]=dis[y][x]=min(dis[x][y],z);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	int L=0,R=1731311;
	while(L<R){
		int mid=(L+R)>>1;
		if(che(mid))R=mid;
		else L=mid+1;
	}
	if(!che(R))puts("-1");
	else printf("%d\n",R);
	return 0;
}