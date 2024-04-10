#include<bits/stdc++.h>
using namespace std;
int n,m,cut[210][210];
namespace MF{
	const int N=2100,M=20100;
	int head[N],cur[N],dep[N],cnt,S,T,res;
	struct node{
		int to,next,val,org;
	}edge[M];
	void ae(int u,int v,int w){
		edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=edge[cnt].org=w,head[u]=cnt++;
		edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=edge[cnt].org=w,head[v]=cnt++;
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
		res=0;
		while(bfs()){
			reach=true;
			while(reach)reach=false,dfs(S,0x3f3f3f3f);
		}
	}
	void initialize(){
		for(int i=0;i<cnt;i++)edge[i].val=edge[i].org;
	}
}
namespace GMT{
	int ord[2100],cnt,head[2100],p,q,id,mn,res;
	struct node{
		int to,next,val;
		bool vis;
	}edge[4100];
	void ae(int u,int v,int w){
		edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,edge[cnt].vis=false,head[u]=cnt++;
		edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,edge[cnt].vis=false,head[v]=cnt++;
	}
	bool cmp(int x,int y){
		return MF::dep[x]<MF::dep[y];
	}
	void work(int l,int r){
		if(l==r)return;
		MF::S=ord[l],MF::T=ord[r];
		MF::Dinic(),ae(ord[l],ord[r],MF::res),MF::initialize();
		sort(ord+l,ord+r+1,cmp);
		int mid=upper_bound(ord+l,ord+r+1,0,cmp)-ord;
		work(l,mid-1),work(mid,r);
	}
	bool vis[2100];
	vector<int>v;
	void dfs(int x,int fa){
		for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa&&!edge[i].vis){
			if(edge[i].val<mn)mn=edge[i].val,p=x,q=edge[i].to,id=i;
			dfs(edge[i].to,x);
		}
	}
	void solve(int x){
		mn=0x3f3f3f3f,dfs(x,0);
		if(mn==0x3f3f3f3f){v.push_back(x);return;}
		edge[id].vis=edge[id^1].vis=true,res+=mn;
		int u=p,v=q;
		solve(u),solve(v);
	}
}
int main(){
	scanf("%d%d",&n,&m),memset(MF::head,-1,sizeof(MF::head)),memset(GMT::head,-1,sizeof(GMT::head));
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),MF::ae(x,y,z);
	for(int i=1;i<=n;i++)GMT::ord[i]=i;
	GMT::work(1,n);
	GMT::solve(1);
	printf("%d\n",GMT::res);
	for(int i=0;i<GMT::v.size();i++)printf("%d ",GMT::v[i]);
	return 0;
}