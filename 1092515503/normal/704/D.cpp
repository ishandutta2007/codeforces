#include<bits/stdc++.h>
using namespace std;
int n,m,r,b;
namespace MaxFlow{
	const int N=200100,M=2000000;
	int head[N],cur[N],dep[N],cnt,S,T,s,t,res,deg[N];
	struct node{int to,next,val;}edge[M];
	void ae(int u,int v,int l,int r){
		deg[v]+=l,deg[u]-=l;
		edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=r-l,head[u]=cnt++;
		edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	queue<int>q;
	inline bool bfs(){
		memset(dep,0,sizeof(dep)),q.push(S),dep[S]=1;
		while(!q.empty()){
			register int x=q.front();q.pop();
			for(register int i=cur[x]=head[x];i!=-1;i=edge[i].next)
				if(edge[i].val&&!dep[edge[i].to])dep[edge[i].to]=dep[x]+1,q.push(edge[i].to);
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
}using namespace MaxFlow;
int id,lim[N],DEG[N];
map<int,int>mp[2];
int main(){
	scanf("%d%d%d%d",&n,&m,&r,&b),memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(!mp[0][x])mp[0][x]=++id;
		if(!mp[1][y])mp[1][y]=++id;
		DEG[mp[1][y]]++,DEG[mp[0][x]]--;
		ae(mp[0][x],mp[1][y],0,1);
	}
	for(int i=1;i<=id;i++)lim[i]=0x3f3f3f3f;
	s=id+1,t=id+2,S=id+3,T=id+4;
	for(int i=1,tp,x,y;i<=m;i++){
		scanf("%d%d%d",&tp,&x,&y),tp--;
		if(mp[tp].find(x)!=mp[tp].end())lim[mp[tp][x]]=min(lim[mp[tp][x]],y);
	}
	for(int i=1;i<=id;i++){
//		printf("%d %d\n",DEG[i],lim[i]);
		if((DEG[i]&1)!=(lim[i]&1))lim[i]--;
		if(lim[i]<0){puts("-1");return 0;}
		lim[i]=min(lim[i],abs(DEG[i]));
		if(DEG[i]>0)ae(i,t,(DEG[i]-lim[i])>>1,(DEG[i]+lim[i])>>1);
		else ae(s,i,(-lim[i]-DEG[i])>>1,(lim[i]-DEG[i])>>1);
	}
	int sum=0;
	for(int i=1;i<=t;i++){
		if(deg[i]>0)ae(S,i,0,deg[i]),sum+=deg[i];
		if(deg[i]<0)ae(i,T,0,-deg[i]);
	}
	Dinic();
	ae(t,s,0,0x3f3f3f3f);
	Dinic();
	if(sum!=res){puts("-1");return 0;}
	int flow=edge[cnt-1].val;
	printf("%lld\n",1ll*min(r,b)*(n-flow)+1ll*max(r,b)*flow);
	for(int i=0;i<n;i++)putchar(edge[i<<1|1].val^(r<=b)?'r':'b');
	return 0;
}