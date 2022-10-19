#include<bits/stdc++.h>
using namespace std;
int n,g[10][10],id[10][10],tot,num[10],lim;
char s[10];
namespace MaxFlow{
	const int N=50,M=200000;
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
	inline void Dinic(){res=0;while(bfs()){reach=true;while(reach)reach=false,dfs(S,0x3f3f3f3f);}}
}using namespace MaxFlow;
int rt[10]={1,10,100,1000,10000,100000},od[10]={1,10,100,1000,10000,100000};
int arr[10],u[10],v[10];
bool us[10];int tms[10];
void dfs(int pos){
	if(pos>=lim-2){
		for(int i=0;i<pos;i++)tms[arr[i]]++;
		for(int i=0;i<lim;i++)us[i]=false;
		for(int i=0;i<pos;i++){
			for(int j=0;j<lim;j++)if(!tms[j]&&!us[j]){us[j]=true,u[i]=arr[i],v[i]=j;break;}
			tms[arr[i]]--;
		}
		for(int i=0;i+1<lim;i++)if(!us[i]){u[lim-2]=i,v[lim-2]=lim-1;break;}
		bool ok=true;
		for(int i=0;i+1<lim;i++){
			if(u[i]>v[i])swap(u[i],v[i]);
			if(!g[u[i]][v[i]]--)ok=false;
		}
		memset(head,-1,sizeof(head)),cnt=0;
		for(int i=0;i<lim;i++)for(int j=i;j<lim;j++)
			ae(id[i][j],T,g[i][j]),ae(i,id[i][j],0x3f3f3f3f),ae(j,id[i][j],0x3f3f3f3f);
		for(int i=0;i+1<lim;i++)g[u[i]][v[i]]++;
		if(!ok)return;
		for(int i=0;i<lim;i++)ae(S,i,num[i]-1);
		Dinic();
		if(res!=n-lim)return;
		for(int i=0;i+1<lim;i++)printf("%d %d\n",rt[u[i]],rt[v[i]]);
		for(int i=0;i<lim;i++)for(int j=i;j<lim;j++)for(int k=head[id[i][j]];k!=-1;k=edge[k].next)if(edge[k].to<lim)
			for(int t=0;t<edge[k].val;t++)printf("%d %d\n",++od[edge[k].to],rt[i^j^edge[k].to]);
		exit(0);
	}
	for(int i=0;i<lim;i++)arr[pos]=i,dfs(pos+1);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%s",s),x=strlen(s);
		scanf("%s",s),y=strlen(s);
		if(x>y)swap(x,y);
		g[x-1][y-1]++;
	}
	for(int i=1;i<=n;i++){
		int s=-1;
		for(int j=i;j;j/=10)s++;
		num[s]++,lim=max(lim,s+1);
	}
//	printf("%d\n",lim);
	tot=lim;
	for(int i=0;i<lim;i++)for(int j=i;j<lim;j++)id[i][j]=tot++;
	S=tot++,T=tot++;
	dfs(0),puts("-1");
	return 0;
}