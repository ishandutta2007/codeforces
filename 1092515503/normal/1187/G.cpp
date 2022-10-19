#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,d,occ[100];
pair<int,int>p[100];
namespace MCMF{
	const int N=10000,M=20000000;
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
			for(int i=head[x];i!=-1;i=edge[i].next){
				if(!edge[i].val)continue;
				if(dis[edge[i].to]>dis[x]+edge[i].cost){
					dis[edge[i].to]=dis[x]+edge[i].cost,fr[edge[i].to]=x,id[edge[i].to]=i;
					if(!in[edge[i].to])in[edge[i].to]=true,q.push(edge[i].to);
				}
			}
		}
		if(dis[T]==dis[N-1])return false;
		int x=T,mn=0x3f3f3f3f;
		while(x!=S)mn=min(mn,edge[id[x]].val),x=fr[x];
		cost+=dis[T]*mn,x=T;
		while(x!=S)edge[id[x]].val-=mn,edge[id[x]^1].val+=mn,x=fr[x];
		return true;
	}
}
using namespace MCMF;
int main(){
	scanf("%d%d%d%d%d",&n,&m,&r,&c,&d),memset(head,-1,sizeof(head)),S=(r+n+1)*n+1,T=(r+n+1)*n+2;
	for(int i=1,x;i<=r;i++)scanf("%d",&x),occ[x]++;
	for(int i=1;i<=m;i++)scanf("%d%d",&p[i].first,&p[i].second);
	for(int i=0;i<r+n;i++)for(int j=1;j<=m;j++)for(int k=1;k<=r;k++)ae(i*n+p[j].first,(i+1)*n+p[j].second,1,(2*k-1)*d),ae(i*n+p[j].second,(i+1)*n+p[j].first,1,(2*k-1)*d);
	for(int i=1;i<=r+n;i++){
		ae(i*n+1,T,0x3f3f3f3f,i*c);
		for(int j=2;j<=n;j++)ae((i-1)*n+j,i*n+j,0x3f3f3f3f,0);
	}	
	for(int i=1;i<=n;i++)ae(S,i,occ[i],0);
	while(SPFA());
	printf("%d\n",cost);
	return 0;
}