#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,s,t,X[1010],Y[1010],Z[1010],dis[50][50][50][50],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char g[50][50];
queue<pair<int,int> >q;
void bfs(int xx,int yy){
	dis[xx][yy][xx][yy]=0,q.push(make_pair(xx,yy));
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;q.pop();
		for(int i=0;i<4;i++){
			if(x+dx[i]>n||y+dy[i]>m||x+dx[i]<1||y+dy[i]<1||g[x+dx[i]][y+dy[i]]=='#'||dis[xx][yy][x+dx[i]][y+dy[i]]!=-1)continue;
			dis[xx][yy][x+dx[i]][y+dy[i]]=dis[xx][yy][x][y]+1,q.push(make_pair(x+dx[i],y+dy[i]));
		}
	}
}
namespace MaxFlow{
	const int N=2010,M=2001000;
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
using namespace MaxFlow;
bool che(ll ip){
	memset(head,-1,sizeof(head)),cnt=res=0;
	for(int x=1;x<=n;x++)for(int y=1;y<=m;y++){
		for(int i=1;i<=s;i++){
			if(dis[X[i]][Y[i]][x][y]==-1)continue;
			if(1ll*dis[X[i]][Y[i]][x][y]*Z[i]>ip)continue;
			ae(2*n*m+i,(x-1)*m+y,1); 
		}
		for(int j=1;j<=t;j++){
			if(dis[X[s+j]][Y[s+j]][x][y]==-1)continue;
			if(1ll*dis[X[s+j]][Y[s+j]][x][y]*Z[s+j]>ip)continue;
			ae(n*m+(x-1)*m+y,2*n*m+s+j,1);			
		}
	}
	for(int i=1;i<=s;i++)ae(S,2*n*m+i,1);
	for(int i=1;i<=t;i++)ae(2*n*m+s+i,T,1);
	for(int x=1;x<=n;x++)for(int y=1;y<=m;y++)if(g[x][y]!='#')ae((x-1)*m+y,n*m+(x-1)*m+y,1);
	Dinic();
	return res==s;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t),memset(dis,-1,sizeof(dis));
	for(int i=1;i<=n;i++)scanf("%s",g[i]+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(g[i][j]!='#')bfs(i,j);
	if(abs(s-t)!=1){puts("-1");return 0;}
	if(s<t)scanf("%d%d%d",&X[s+1],&Y[s+1],&Z[s+1]);
	else scanf("%d%d%d",&X[s+t+1],&Y[s+t+1],&Z[s+t+1]);
	for(int i=1;i<=s;i++)scanf("%d%d%d",&X[i],&Y[i],&Z[i]);if(s<=t)s++;
	for(int i=1;i<=t;i++)scanf("%d%d%d",&X[s+i],&Y[s+i],&Z[s+i]);if(t<=s)t++;
	S=2*n*m+s+t+1,T=2*n*m+s+t+2;
	ll l=0,r=1e12;
	while(l<r){
		ll mid=(l+r)>>1;
		if(che(mid))r=mid;
		else l=mid+1;
	}
	if(!che(r))puts("-1");
	else printf("%lld\n",r);
	return 0;
}