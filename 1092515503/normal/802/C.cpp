#include<bits/stdc++.h>
using namespace std;
int n,m,s,t,c[20100];
namespace MCMF{
	int head[20100],cnt,dis[20100],fr[20100],id[20100],S,T,cost,deg[20100];
	struct node{
		int to,next,val,cost;
	}edge[4010000];
	void ae(int u,int v,int w,int c){
//		printf("%d %d (%d,%d)\n",u,v,w,c);
		edge[cnt].cost=c,edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
		edge[cnt].cost=-c,edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	void ae(int u,int v){deg[v]++,deg[u]--;}
	queue<int>q;
	bool in[20100];
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
		if(dis[T]==dis[T+1])return false;
		int x=T,mn=0x3f3f3f3f;
		while(x!=S)mn=min(mn,edge[id[x]].val),x=fr[x];
		cost+=dis[T]*mn,x=T;
		while(x!=S)edge[id[x]].val-=mn,edge[id[x]^1].val+=mn,x=fr[x];
		return true;
	}	
}
using namespace MCMF;
int main(){
	scanf("%d%d",&n,&m),s=2*n*n+n,t=2*n*n+n+1,S=2*n*n+n+2,T=2*n*n+n+3,memset(head,-1,sizeof(head));
	for(int i=0,x;i<n;i++){
		scanf("%d",&x),x--;
		for(int j=0;j<n;j++)if(j==x)ae(i*n+j,n*n+i*n+j);else ae(i*n+j,n*n+i*n+j,1,0);
		for(int j=0;j<n;j++)if(i+1<n)ae(n*n+i*n+j,(i+1)*n+j,1,0);else ae(n*n+i*n+j,t,1,0);
	}
	for(int i=0;i<n;i++)scanf("%d",&c[i]);
	ae(s,2*n*n,m,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)ae(2*n*n+i,i*n+j,1,c[j]);
		if(i)for(int j=0;j<n;j++)ae(n*n+(i-1)*n+j,2*n*n+i,1,0);
	}
	ae(t,s,0x3f3f3f3f,0);
	for(int i=0;i<=t;i++){
		if(deg[i]>0)ae(S,i,deg[i],0);
		if(deg[i]<0)ae(i,T,-deg[i],0);
	}
	while(SPFA());
	printf("%d\n",cost);
	return 0;
}