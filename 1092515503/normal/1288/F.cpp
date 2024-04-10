#include<bits/stdc++.h>
using namespace std;
int n1,n2,m,R,B,s,t,tot;
namespace MCMF{
	const int N=10000,M=20000;
	int head[N],cnt,dis[N],fr[N],id[N],S,T,cost,degree[N],flow;
	struct node{
		int to,next,val,cost;
	}edge[M];
	void ae(int u,int v,int l,int r,int c){
		degree[u]-=l,degree[v]+=l;
//		printf("%d %d %d %d %d\n",u,v,l,r,c);
		edge[cnt].cost=c,edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=r-l,head[u]=cnt++;
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
		cost+=dis[T]*mn,x=T,flow+=mn;
		while(x!=S)edge[id[x]].val-=mn,edge[id[x]^1].val+=mn,x=fr[x];
		return true;
	}
}
using namespace MCMF;
char ll[210],rr[210];
int main(){
	scanf("%d%d%d%d%d",&n1,&n2,&m,&R,&B),memset(head,-1,sizeof(head)),s=n1+n2+1,t=n1+n2+2,S=n1+n2+3,T=n1+n2+4;
	scanf("%s%s",ll+1,rr+1);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		ae(x,y+n1,0,1,R);
		ae(y+n1,x,0,1,B);
	}
	for(int i=1;i<=n1;i++){
		if(ll[i]=='R')ae(s,i,1,0x3f3f3f3f,0);
		if(ll[i]=='B')ae(i,t,1,0x3f3f3f3f,0);
		if(ll[i]=='U')ae(s,i,0,0x3f3f3f3f,0),ae(i,t,0,0x3f3f3f3f,0);
	}
	for(int i=1;i<=n2;i++){
		if(rr[i]=='R')ae(i+n1,t,1,0x3f3f3f3f,0);
		if(rr[i]=='B')ae(s,i+n1,1,0x3f3f3f3f,0);
		if(rr[i]=='U')ae(s,i+n1,0,0x3f3f3f3f,0),ae(i+n1,t,0,0x3f3f3f3f,0);
	}
	ae(t,s,0,0x3f3f3f3f,0);
	for(int i=1;i<=t;i++){
		if(degree[i]>0)tot+=degree[i],ae(S,i,0,degree[i],0);
		if(degree[i]<0)ae(i,T,0,-degree[i],0);
	}
	while(SPFA());
	if(flow!=tot){puts("-1");return 0;}
	printf("%d\n",cost);
	for(int i=0;i<4*m;i+=4){
		if(!edge[i].val)putchar('R');
		else if(!edge[i+2].val)putchar('B');
		else putchar('U');
	}
	return 0;
}