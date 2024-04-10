#include<bits/stdc++.h>
using namespace std;
int n,cnt=1,S[1010],head[10010000],nex[10010000],fa[10010000];
struct AC_Automaton{int ch[2],fail,ed;}t[10010000];
char ss[10010000],*s[1010];
void ins(int id){
	int x=1;
	for(int i=0;i<S[id];i++){
		if(!t[x].ch[s[id][i]-'a'])t[x].ch[s[id][i]-'a']=++cnt;
		x=t[x].ch[s[id][i]-'a'];
	}
	t[x].ed=id;
}
int q[10010000],l,r;
void build(){
	for(int i=0;i<2;i++){
		if(t[1].ch[i])t[q[r++]=t[1].ch[i]].fail=1;
		else t[1].ch[i]=1;
	}
	while(l!=r){
		int x=q[l++];
//		printf("%d:%d\n",x,t[x].fail);
		nex[x]=head[t[x].fail],head[t[x].fail]=x;
		for(int i=0;i<2;i++)
			if(t[x].ch[i])t[q[r++]=t[x].ch[i]].fail=t[t[x].fail].ch[i];
			else t[x].ch[i]=t[t[x].fail].ch[i];
	}
}
void bfs(){
	l=r=0,q[r++]=1;
	while(l!=r){
		int x=q[l++];
		int tmp=fa[x];if(t[x].ed)tmp=t[x].ed;
		for(int y=head[x];y!=-1;y=nex[y])fa[q[r++]=y]=tmp;	
	}
}
bitset<800>bs[800];
void func(int id){
	int x=1;
	for(int i=0;i<S[id];i++){
		x=t[x].ch[s[id][i]-'a'];
		if(fa[x])bs[id].set(fa[x]);
		if(t[x].ed)bs[id].set(t[x].ed);
	}
}
namespace MF{
	const int N=2010,M=2000000;
	int head[N],cur[N],dep[N],cnt,S,T,res;
	struct node{int to,next,val;}edge[M];
	void ae(int u,int v,int w){
		edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
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
	bool vis[N];
	void dfs(int x){
		vis[x]=true;
		for(int i=head[x],y;i!=-1;i=edge[i].next){
			if((y=edge[i].to)>2*n||vis[y]||edge[i].val)continue;
			vis[y]=true;
			for(int j=head[y];j!=-1;j=edge[j].next)if(edge[j].to<=2*n&&!edge[j].val)
				dfs(edge[j].to);
		}
	}
	inline void Dinic(){
		while(bfs()){reach=true;while(reach)reach=false,dfs(S,0x3f3f3f3f);}
		printf("%d\n",n-res);
		for(int x=n+1;x<=2*n;x++){
			if(vis[x])continue;
			bool ok=true;
			for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to==T&&!edge[i].val)ok=false;
			if(ok)dfs(x);
		}
		for(int i=1;i<=n;i++)if(!vis[i]&&vis[i+n])printf("%d ",i);
	}
}
int main(){
	scanf("%d",&n);
	s[1]=ss;
	for(int i=1;i<=n;i++)scanf("%s",s[i]),S[i]=strlen(s[i]),ins(i),s[i+1]=s[i]+S[i];
	memset(head,-1,sizeof(head)),build(),bfs();
	for(int i=1;i<=n;i++)func(i);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)if(bs[i].test(k))bs[i]|=bs[k];
//	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)printf("%d",bs[i].test(j));puts("");}
	memset(MF::head,-1,sizeof(MF::head)),MF::S=2*n+1,MF::T=2*n+2;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(j!=i&&bs[i].test(j))MF::ae(j,i+n,1);
	for(int i=1;i<=n;i++)MF::ae(MF::S,i,1),MF::ae(i+n,MF::T,1);
	MF::Dinic();
	return 0;
}