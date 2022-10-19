#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
namespace MCMF{
	const int N=110,M=20000;
	int head[N],cnt,dis[N],fr[N],id[N],S,T,cost,deg[N];
	struct node{int to,next,val,cost;}edge[M];
	void ae(int u,int v,int w,int c){
		if(c<0)deg[v]+=w,deg[u]-=w,cost+=c*w,swap(u,v),c=-c;
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
}using namespace MCMF;
int main(){
	scanf("%d%d",&n,&m),s=1,t=n,S=n+1,T=n+2,memset(head,-1,sizeof(head));
	for(int i=1,x,y,c,f;i<=m;i++){
		scanf("%d%d%d%d",&x,&y,&c,&f);
		cost+=f;
		ae(x,y,min(c,f),-1);
		if(c>=f)ae(x,y,c-f,1);
		else ae(x,y,f-c,0);
		ae(x,y,0x3f3f3f3f,2);
	}
//	printf("%lld\n",cost);
	ae(t,s,0x3f3f3f3f,0);
	for(int i=1;i<=n;i++){
		if(deg[i]>0)ae(S,i,deg[i],0);
		if(deg[i]<0)ae(i,T,-deg[i],0);
	}
	while(SPFA());
	printf("%lld\n",cost);
	return 0;
}