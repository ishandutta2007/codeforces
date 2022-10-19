#include<bits/stdc++.h>
using namespace std;
const int lim=25;
const int N=10003,M=20000;
struct MaxFlow{
	int head[N],cur[N],dep[N],cnt,S,T,res;
	MaxFlow(){memset(head,-1,sizeof(head));}
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
	int fr[N];
	inline bool Augment(){
		memset(dep,0,sizeof(dep));
		while(!q.empty())q.pop();
		q.push(S),dep[S]=0x3f3f3f3f;
		while(!q.empty()){
			register int x=q.front();q.pop();
			if(x==T)break;
			for(register int i=head[x];i!=-1;i=edge[i].next)if(edge[i].val&&!dep[edge[i].to])dep[edge[i].to]=min(dep[x],edge[i].val),fr[edge[i].to]=i,q.push(edge[i].to);
		}
		if(!dep[T])return false;
		res+=dep[T];
		for(int x=T;x!=S;x=edge[fr[x]^1].to)edge[fr[x]].val-=dep[T],edge[fr[x]^1].val+=dep[T];
		return true;
	}
	inline void FF(){while(Augment());}
}G[11];
int cnt,bin[20],tp,id[1<<10];
int n,m,k,q,a[10];
int f[1<<10];
inline void read(int&x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
inline void print(int x){if(x<=9)putchar('0'+x);else print(x/10),putchar('0'+x%10);}
int g[1<<10],lb[1<<10],num;
int main(){
	read(n),read(m),read(k),read(q),G[0].S=1,G[0].T=n,num=1<<k;
	for(register int i=0,x,y,z;i<m;i++)read(x),read(y),read(z),G[0].ae(x,y,i<k?0:z);
	G[0].Dinic();
	for(int i=0;i<num;i++){
		f[i]=G[id[i]].res; 
		for(int j=0;j<k;j++){
			if(i&(1<<j))break;
			G[id[i|(1<<j)]=(tp?bin[tp--]:++cnt)]=G[id[i]];
			G[id[i|(1<<j)]].edge[j<<1].val=lim;
			G[id[i|(1<<j)]].FF();
		}
		bin[++tp]=id[i];
	}
//	for(int i=0;i<(1<<k);i++)printf("%d ",f[i]);puts("");
	for(int i=1;i<num;i++)for(lb[i]=0;;lb[i]++)if(i&(1<<lb[i]))break;
	for(register int i=1;i<=q;i++){
		register int ans=0x3f3f3f3f;
		for(register int j=0;j<k;j++)read(a[j]);
		for(register int msk=1;msk<num;msk++)g[msk]=g[msk^(1<<lb[msk])]+a[lb[msk]];
		for(register int msk=0;msk<num;msk++)ans=min(ans,f[msk]+g[(num-1)^msk]);
		print(ans),putchar('\n');
	}
	return 0;
}