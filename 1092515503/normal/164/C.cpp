#include<bits/stdc++.h>
using namespace std;
int n,m,s[1010],t[1010],c[1010],ord[1010];
vector<int>v;
namespace MCMF{
	const int N=10000,M=2000000;
	int head[N],cnt,dis[N],fr[N],id[N],S,T,cost;
	struct node{
		int to,next,val,cost;
	}edge[M];
	void ae(int u,int v,int w,int c){
		edge[cnt].cost=c,edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
		edge[cnt].cost=-c,edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	queue<int>q;
	bool in[N];
	bool SPFA(){
		memset(dis,0x80,sizeof(dis)),dis[S]=0,q.push(S),in[S]=true;
		while(!q.empty()){
			int x=q.front();q.pop(),in[x]=false;
	//		printf("%d\n",x);
			for(int i=head[x];i!=-1;i=edge[i].next){
				if(!edge[i].val)continue;
				if(dis[edge[i].to]<dis[x]+edge[i].cost){
					dis[edge[i].to]=dis[x]+edge[i].cost,fr[edge[i].to]=x,id[edge[i].to]=i;
					if(!in[edge[i].to])in[edge[i].to]=true,q.push(edge[i].to);
				}
			}
		}
		if(dis[T]==0x80808080)return false;
		int x=T,mn=0x3f3f3f3f;
		while(x!=S)mn=min(mn,edge[id[x]].val),x=fr[x];
		cost+=dis[T]*mn,x=T;
		while(x!=S)edge[id[x]].val-=mn,edge[id[x]^1].val+=mn,x=fr[x];
		return true;
	}
}
using namespace MCMF;
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%d%d%d",&s[i],&t[i],&c[i]),t[i]+=s[i],v.push_back(s[i]),v.push_back(t[i]);
	sort(v.begin(),v.end()),v.resize(unique(v.begin(),v.end())-v.begin()),S=0,T=v.size()+1;
	for(int i=1;i<=n;i++)s[i]=lower_bound(v.begin(),v.end(),s[i])-v.begin()+1,t[i]=lower_bound(v.begin(),v.end(),t[i])-v.begin()+1;
	for(int i=1;i<=n;i++)ord[i]=cnt,ae(s[i],t[i],1,c[i]);
	for(int i=0;i<T;i++)ae(i,i+1,m,0);
	while(SPFA());
	for(int i=1;i<=n;i++)printf("%d ",!edge[ord[i]].val);
	return 0;
}