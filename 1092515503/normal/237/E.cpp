#include<bits/stdc++.h>
using namespace std;
int n,SS,TT,val[110],tot[110][26],occ[26];
char s[110];
namespace MCMF{
	const int N=10000,M=2000000;
	int head[N],cnt,dis[N],fr[N],id[N],S,T,cost,flow;
	struct node{
		int to,next,val,cost;
	}edge[M];
	void ae(int u,int v,int w,int c){
//		if(w)printf("%d %d %d %d\n",u,v,w,c);
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
		if(dis[T]==dis[T+1])return false;
		int x=T,mn=0x3f3f3f3f;
		while(x!=S)mn=min(mn,edge[id[x]].val),x=fr[x];
		cost+=dis[T]*mn,x=T,flow+=mn;
		while(x!=S)edge[id[x]].val-=mn,edge[id[x]^1].val+=mn,x=fr[x];
		return true;
	}
}
using namespace MCMF;
int main(){
	scanf("%s",s),TT=strlen(s),memset(head,-1,sizeof(head));
	for(int i=0;i<TT;i++)occ[s[i]-'a']++;
	scanf("%d",&n),S=n+26,T=n+26+1;
	for(int i=0;i<n;i++){
		scanf("%s%d",s,&val[i]),SS=strlen(s),ae(S,i,val[i],i+1);
		for(int j=0;j<SS;j++)tot[i][s[j]-'a']++;
		for(int j=0;j<26;j++)ae(i,n+j,tot[i][j],0);
	}
	for(int i=0;i<26;i++)ae(n+i,T,occ[i],0);
	while(SPFA());
//	printf("%d\n",flow);
	if(flow==TT)printf("%d\n",cost);
	else puts("-1");
	return 0;
}