#include<bits/stdc++.h>
using namespace std;
const int N=90100,M=5000000;
int n,m,id[N],vl[N];
namespace MaxFlow{
	int head[N],cur[N],dep[N],cnt,S,T,res;
	struct node{int to,next,val;}edge[M];
	void ae(int u,int v,int w){
//		printf("%d %d %d\n",u,v,w);
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
}
using MaxFlow::S;
using MaxFlow::T;
using MaxFlow::Dinic;
using MaxFlow::res;
using MaxFlow::head;
using MaxFlow::ae;
using MaxFlow::edge;
vector<pair<int,int> >v[20100];
int fa[20100],sz[20100],son[20100],dep[20100],dfn[20100],rev[20100],top[20100],fid[20100],tot,cnt;
void dfs1(int x){
	dep[x]=dep[fa[x]]+1,sz[x]=1;
	for(auto y:v[x])if(y.first!=fa[x]){
		fa[y.first]=x,fid[y.first]=y.second,dfs1(y.first),sz[x]+=sz[y.first];
		if(sz[y.first]>sz[son[x]])son[x]=y.first;
	}
}
void dfs2(int x){
	dfn[x]=++tot,rev[tot]=x;if(!top[x])top[x]=x;
	if(son[x])top[son[x]]=top[x],dfs2(son[x]);
	for(auto y:v[x])if(y.first!=fa[x]&&y.first!=son[x])dfs2(y.first);
}
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
void build(int x,int l,int r){
	id[x]=++cnt;
	if(l==r)ae(id[x],T,1),vl[id[x]]=fid[rev[l]];
	else build(lson,l,mid),build(rson,mid+1,r),ae(id[x],id[lson],0x3f3f3f3f),ae(id[x],id[rson],0x3f3f3f3f);
}
void AE(int x,int l,int r,int L,int R,int ID){
//	printf("%d:[%d,%d]:[%d,%d]:%d\n",x,l,r,L,R,ID);
	if(l>R||r<L)return;
	if(L<=l&&r<=R){ae(ID,id[x],0x3f3f3f3f);return;}
	AE(lson,l,mid,L,R,ID),AE(rson,mid+1,r,L,R,ID);
}
void AE(int ID,int x,int y){
	ae(S,ID,1);
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		AE(1,2,n,dfn[top[x]],dfn[x],ID),x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(x!=y)AE(1,2,n,dfn[x]+1,dfn[y],ID);
}
bool vis[N][2];
void dfs(int x,bool sd){
	vis[x][sd]=true;
	if(vl[x])sd=true;
	if(x>cnt)sd=false;
//	printf("%d,%d\n",x,sd);
	for(int i=head[x];i!=-1;i=edge[i].next){
		if(!edge[i^1].val||vis[edge[i].to][sd]||edge[i].to==S||edge[i].to==T)continue;
		if(!sd&&x<=cnt&&edge[i].to<x)continue;
		if(sd&&!vl[x]&&edge[i].to>x&&edge[i].to<=cnt)continue;
		dfs(edge[i].to,sd);
	}
}
vector<int>U,V;
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head)),S=1,T=2,cnt=2;
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(make_pair(y,i)),v[y].push_back(make_pair(x,i));
	dfs1(1),dfs2(1),build(1,2,n);
//	for(int i=1;i<=n;i++)printf("FA:%d DP:%d SZ:%d SN:%d DF:%d RV:%d TP:%d\n",fa[i],dep[i],sz[i],son[i],dfn[i],rev[i],top[i]);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),AE(cnt+i,x,y);
	Dinic();
	dfs(T,false);
	for(int i=cnt+1;i<=cnt+m;i++)if(vis[i][true])U.push_back(i-cnt);
	for(int i=3;i<=cnt;i++)if(vl[i]&&!vis[i][false])V.push_back(vl[i]);
	printf("%d\n",res);
	printf("%d ",U.size());for(auto i:U)printf("%d ",i);puts("");
	printf("%d ",V.size());for(auto i:V)printf("%d ",i);puts("");
	return 0;
}