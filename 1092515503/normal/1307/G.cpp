#include<bits/stdc++.h>
using namespace std;
int n,m,Q;
vector<pair<int,int> >v;
namespace MCMF{
	int S,T,dis[60],fr[60],res,cost,cnt,head[60];
	struct node{int to,next,val,cost;}edge[5010];
	void ae(int u,int v,int w){
		edge[cnt].cost=w,edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=1,head[u]=cnt++;
		edge[cnt].cost=-w,edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	bool in[60];
	queue<int>q;
	bool SPFA(){
		memset(dis,0x3f,sizeof(dis)),in[S]=true,dis[S]=0,q.push(S);
		while(!q.empty()){
			int x=q.front();q.pop(),in[x]=false;
			for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].val&&dis[edge[i].to]>dis[x]+edge[i].cost){
				dis[edge[i].to]=dis[x]+edge[i].cost,fr[edge[i].to]=i;
				if(!in[edge[i].to])in[edge[i].to]=true,q.push(edge[i].to);
			}
		}
//		for(int i=1;i<=n;i++)printf("%d ",dis[i]);puts("");
		if(dis[T]==0x3f3f3f3f)return false;
		int mn=0x3f3f3f3f;
		for(int x=T;x!=S;x=edge[fr[x]^1].to)mn=min(mn,edge[fr[x]].val);
		res+=mn,cost+=dis[T]*mn;
//		printf("%d %d\n",res,cost);
		v.emplace_back(res,cost);
		for(int x=T;x!=S;x=edge[fr[x]^1].to)edge[fr[x]].val-=mn,edge[fr[x]^1].val+=mn;
		return true;
	}
}
using namespace MCMF;
int main(){
	scanf("%d%d",&n,&m),S=1,T=n,memset(head,-1,sizeof(head));
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),ae(x,y,z);
	while(SPFA());
	scanf("%d",&Q);
	for(int i=1,x;i<=Q;i++){
		scanf("%d",&x);
		double mx=0x3f3f3f3f;
		for(auto p:v)mx=min(mx,1.0*(p.second+x)/p.first);
		printf("%lf\n",mx);
	}
	return 0;
}