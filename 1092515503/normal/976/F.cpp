#include<bits/stdc++.h>
using namespace std;
int n1,n2,m,deg[5010],id[5010],mn=0x3f3f3f3f;
namespace MaxFlow{
	const int N=5000,M=2000000;
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
vector<int>v[5010];
int main(){
	scanf("%d%d%d",&n1,&n2,&m),memset(head,-1,sizeof(head)),S=n1+n2+1,T=n1+n2+2;
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),ae(x,y+n1,1),deg[x]++,deg[y+n1]++;
	for(int i=1;i<=n1+n2;i++)mn=min(mn,deg[i]);
	for(int i=1;i<=n1;i++)id[i]=cnt,ae(S,i,deg[i]-mn);
	for(int i=n1+1;i<=n1+n2;i++)id[i]=cnt,ae(i,T,deg[i]-mn);
	for(int i=0;i<=mn;i++){
		Dinic();
		for(int j=0;j<m;j++)if(edge[j<<1].val)v[i].push_back(j+1);
		for(int j=1;j<=n1+n2;j++)edge[id[j]].val++;
	}
	for(int i=mn;i>=0;i--){
		printf("%d ",v[i].size());
		for(int j=0;j<v[i].size();j++)printf("%d ",v[i][j]);puts("");
	}
	return 0;
}