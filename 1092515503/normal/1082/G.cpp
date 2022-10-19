#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum;
namespace MaxFlow{
	const int N=3000,M=200000;
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
			while(reach)reach=false,dfs(S,0x3f3f3f3f3f3f3f3f);
		}
	}
}
using namespace MaxFlow;
signed main(){
	scanf("%lld%lld",&n,&m),memset(head,-1,sizeof(head)),S=n+m+1,T=n+m+2;
	for(int i=1,x;i<=n;i++)scanf("%lld",&x),ae(S,i,x);
	for(int i=1,x,y,z;i<=m;i++)scanf("%lld%lld%lld",&x,&y,&z),ae(n+i,T,z),sum+=z,ae(x,n+i,0x3f3f3f3f3f3f3f3f),ae(y,n+i,0x3f3f3f3f3f3f3f3f);
	Dinic();
	printf("%lld\n",sum-res);
	return 0;
}