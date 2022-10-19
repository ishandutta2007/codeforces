#include<bits/stdc++.h>
using namespace std;
int n,m,up[100],lw[100];
namespace MCMF{
	const int N=1000,M=20000;
	int head[N],cnt,dis[N],fr[N],id[N],S,T,cost;
	struct node{
		int to,next,val,cost;
	}edge[M];
	void ae(int u,int v,int w,int c){
		edge[cnt].cost=c,edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
		edge[cnt].cost=-c,edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	queue<int>q;
	bool in[N];
	bool SPFA(){
		memset(dis,0x3f,sizeof(dis)),dis[S]=0,q.push(S),in[S]=true;
		while(!q.empty()){
			int x=q.front();q.pop(),in[x]=false;
	//		printf("%d\n",x);
			for(int i=head[x];i!=-1;i=edge[i].next){
				if(!edge[i].val)continue;
				if(dis[edge[i].to]>dis[x]+edge[i].cost){
					dis[edge[i].to]=dis[x]+edge[i].cost,fr[edge[i].to]=x,id[edge[i].to]=i;
					if(!in[edge[i].to])in[edge[i].to]=true,q.push(edge[i].to);
				}
			}
		}
		if(dis[T]==dis[0])return false;
		int x=T,mn=0x3f3f3f3f;
		while(x!=S)mn=min(mn,edge[id[x]].val),x=fr[x];
		cost+=dis[T]*mn,x=T;
		while(x!=S)edge[id[x]].val-=mn,edge[id[x]^1].val+=mn,x=fr[x];
		return true;
	}
}
using namespace MCMF;
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head)),S=2*n+1,T=2*n+2;
	for(int i=1;i<=n;i++)up[i]=n,lw[i]=1;
	for(int i=1,t1,t2,t3,t4;i<=m;i++){
		scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
		if(t1==1)for(int j=t2;j<=t3;j++)lw[j]=max(lw[j],t4);
		else for(int j=t2;j<=t3;j++)up[j]=min(up[j],t4);
	}
	for(int i=1;i<=n;i++)if(up[i]<lw[i]){puts("-1");return 0;}
	for(int i=1;i<=n;i++)for(int j=lw[i];j<=up[i];j++)ae(j,i+n,1,0);
	for(int i=1;i<=n;i++){
		ae(i+n,T,1,0);
		for(int j=1;j<=n;j++)ae(S,i,1,2*j-1);
	}
	while(SPFA());
	printf("%d\n",cost);
	return 0;
}