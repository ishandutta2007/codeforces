#include<bits/stdc++.h>
using namespace std;
int n,num[3010],s;
namespace MCMF{
	const int N=15000,M=2000000;
	int head[N],cnt,dis[N],fr[N],id[N],S,T,cost;
	struct node{
		int to,next,val,cost;
	}edge[M];
	void ae(int u,int v,int w,int c){
//		printf("%d %d (%d,%d)\n",u,v,w,c);
		edge[cnt].cost=c,edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
		edge[cnt].cost=-c,edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	queue<int>q;
	bool in[N];
	bool SPFA(){
		memset(dis,-1,sizeof(dis)),dis[S]=0,q.push(S),in[S]=true;
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
		if(dis[T]==-1)return false;
		int x=T,mn=0x3f3f3f3f;
		while(x!=S)mn=min(mn,edge[id[x]].val),x=fr[x];
		cost+=dis[T]*mn,x=T;
		while(x!=S)edge[id[x]].val-=mn,edge[id[x]^1].val+=mn,x=fr[x];
		return true;
	}
}
using namespace MCMF;
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head)),S=4*n+1,T=4*n+2,s=4*n+3,ae(S,s,4,0);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	for(int i=1;i<=n;i++){
//0:of the same reminder  1:of the same value  2,3: assistive nodes for a particular position
		ae(s,i+2*n,0x3f3f3f3f,0);
		ae(i+0*n,i+2*n,0x3f3f3f3f,0);
		ae(i+1*n,i+2*n,0x3f3f3f3f,0);
		ae(i+2*n,i+3*n,1,1);
		ae(i+3*n,T,0x3f3f3f3f,0);
		
		for(int j=i+1;j<=n;j++)if(num[i]-num[j]==1){ae(i+3*n,j+1*n,0x3f3f3f3f,0);break;}
		for(int j=i+1;j<=n;j++)if(num[j]-num[i]==1){ae(i+3*n,j+1*n,0x3f3f3f3f,0);break;}
		for(int j=i+1;j<=n;j++)if(num[i]%7==num[j]%7){ae(i+3*n,j+0*n,0x3f3f3f3f,0);break;}
		
		for(int j=i+1;j<=n;j++)if(num[i]%7==num[j]%7){ae(i+0*n,j+0*n,0x3f3f3f3f,0);break;}
		for(int j=i+1;j<=n;j++)if(num[i]==num[j]){ae(i+1*n,j+1*n,0x3f3f3f3f,0);break;}
	}
	while(SPFA());
	printf("%d\n",cost);
	return 0;
}