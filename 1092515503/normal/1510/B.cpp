#include<bits/stdc++.h>
using namespace std;
int n,m,a[2010],res,nex[2010],las[2010];
char s[20];
namespace MCMF{
	const int N=3000,M=2000000;
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
		memset(dis,0x3f,sizeof(dis)),dis[S]=0,q.push(S),in[S]=true;
		while(!q.empty()){
			int x=q.front();q.pop(),in[x]=false;
	//		printf("%d\n",x);
			for(int i=head[x];i!=-1;i=edge[i].next){
				if(!edge[i].val)continue;
				if(dis[edge[i].to]>dis[x]+edge[i].cost){
					dis[edge[i].to]=dis[x]+edge[i].cost,fr[edge[i].to]=x,id[edge[i].to]=i;
					if(!in[edge[i].to])in[edge[i].to]=true,q.push(edge[i].to);
				}
			}
		}
		if(dis[T]==dis[0])return false;
		int x=T,mn=0x3f3f3f3f;
		while(x!=S)mn=min(mn,edge[id[x]].val),x=fr[x];
		cost+=dis[T]*mn,x=T;
		while(x!=S)edge[id[x]].val-=mn,edge[id[x]^1].val+=mn,x=fr[x];
		return true;
	}
}
using namespace MCMF;
vector<int>v;
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head)),S=2*m+1,T=2*m+2;
	for(int i=1;i<=m;i++){
		scanf("%s",s);
		for(int j=0;j<n;j++)if(s[j]=='1')a[i]+=(1<<j),res++;
		ae(S,i,1,__builtin_popcount(a[i])),ae(i+m,T,1,0),ae(i,T,1,1);
	}
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++){
		if(i==j)continue;
		if((a[i]&a[j])==a[j])ae(j,m+i,1,-__builtin_popcount(a[j]));
	}
	while(SPFA());
	for(int i=1;i<=m;i++)for(int j=head[i];j!=-1;j=edge[j].next)if(!edge[j].val&&edge[j].to!=S&&edge[j].to!=T)nex[i]=edge[j].to-m,las[edge[j].to-m]=i;
	for(int i=1;i<=m;i++){
//		printf("%d %d\n",nex[i],las[i]);
		if(las[i])continue;
		for(int j=i;j;j=nex[j])for(int k=0;k<n;k++)if((a[j]^a[las[j]])&(1<<k))v.push_back(k);
		v.push_back(-1);
	}
	printf("%d\n",cost-1);
	v.pop_back();
	for(auto i:v)putchar(i>=0?'0'+i:'R'),putchar(' ');putchar('\n');
	return 0;
}