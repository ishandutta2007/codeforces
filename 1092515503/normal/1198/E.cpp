#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n,m;
struct node{
	int x1,x2,y1,y2;
}rec[110];
vector<int>u,v;
bool occ[210][210];
namespace MaxFlow{
	const int N=1000,M=2000000;
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
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++)scanf("%d%d%d%d",&rec[i].x1,&rec[i].y1,&rec[i].x2,&rec[i].y2),rec[i].x2++,rec[i].y2++,u.push_back(rec[i].x1),u.push_back(rec[i].x2),v.push_back(rec[i].y1),v.push_back(rec[i].y2);
	sort(u.begin(),u.end()),u.resize(unique(u.begin(),u.end())-u.begin());
	sort(v.begin(),v.end()),v.resize(unique(v.begin(),v.end())-v.begin());
	S=u.size()+v.size()+1,T=u.size()+v.size()+2;
	for(int i=1;i<=m;i++){
		rec[i].x1=lower_bound(u.begin(),u.end(),rec[i].x1)-u.begin()+1;
		rec[i].x2=lower_bound(u.begin(),u.end(),rec[i].x2)-u.begin()+1;
		rec[i].y1=lower_bound(v.begin(),v.end(),rec[i].y1)-v.begin()+1;
		rec[i].y2=lower_bound(v.begin(),v.end(),rec[i].y2)-v.begin()+1;
		for(int j=rec[i].x1;j<rec[i].x2;j++)for(int k=rec[i].y1;k<rec[i].y2;k++)occ[j][k]=true;
	}
	for(int i=1;i<u.size();i++)ae(S,i,u[i]-u[i-1]);
	for(int i=1;i<v.size();i++)ae(i+u.size(),T,v[i]-v[i-1]);
	for(int i=1;i<u.size();i++)for(int j=1;j<v.size();j++)if(occ[i][j])ae(i,j+u.size(),0x3f3f3f3f);
	Dinic();
	printf("%d\n",res);
	return 0;
}