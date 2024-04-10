#include<bits/stdc++.h>
using namespace std;
int n;
namespace MCMF{
	const int N=1000,M=2000000;
	int head[N],cnt,fr[N],id[N],S,T,flow;
	double dis[N],cost;
	struct node{
		int to,next,val;
		double cost;
	}edge[M];
	void ae(int u,int v,int w,double c){
		edge[cnt].cost=c,edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
		edge[cnt].cost=-c,edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	queue<int>q;
	bool in[N];
	bool SPFA(){
		for(int i=1;i<=T;i++)dis[i]=0x3f3f3f3f;
		dis[S]=0,q.push(S),in[S]=true;
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
		if(fabs(dis[T]-0x3f3f3f3f)<1e-6)return false;
		int x=T,mn=0x3f3f3f3f;
		while(x!=S)mn=min(mn,edge[id[x]].val),x=fr[x];
		cost+=dis[T]*mn,x=T,flow+=mn;
		while(x!=S)edge[id[x]].val-=mn,edge[id[x]^1].val+=mn,x=fr[x];
		return true;
	}
}
using namespace MCMF;
pair<int,int>p[410];
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head)),S=2*n+1,T=2*n+2;
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].first,&p[i].second);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(p[i].second>p[j].second)ae(i,j+n,1,sqrt((p[i].first-p[j].first)*(p[i].first-p[j].first)+(p[i].second-p[j].second)*(p[i].second-p[j].second)));
	for(int i=1;i<=n;i++)ae(S,i,2,0),ae(i+n,T,1,0);
	while(SPFA());
	if(flow!=n-1){puts("-1");return 0;}
	printf("%.8lf\n",cost);
	return 0;
}