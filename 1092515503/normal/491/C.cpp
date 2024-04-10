#include<bits/stdc++.h>
using namespace std;
int n,m,g[52][52];
int HASH(char i){
	if('a'<=i&&i<='z')return i-'a';
	if('A'<=i&&i<='Z')return 26+i-'A';
}
char HASH(int i){
	if(i<26)return 'a'+i;
	if(i<52)return 'A'+i-26;
}
char s[2001000],t[2001000];
namespace MCMF{
	const int N=200,M=200000;
	int head[N],cnt,dis[N],fr[N],id[N],S,T,cost;
	struct node{
		int to,next,val,cost;
	}edge[M];
	void ae(int u,int v,int w,int c){
	//	printf("%d %d %d %d\n",u,v,w,c);
		edge[cnt].cost=c,edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
		edge[cnt].cost=-c,edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	queue<int>q;
	bool in[N];
	bool SPFA(){
		memset(dis,0xcf,sizeof(dis)),dis[S]=0,q.push(S),in[S]=true;
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
		if(dis[T]==dis[T+1])return false;
		int x=T,mn=0x3f3f3f3f;
		while(x!=S)mn=min(mn,edge[id[x]].val),x=fr[x];
		cost+=dis[T]*mn,x=T;
		while(x!=S)edge[id[x]].val-=mn,edge[id[x]^1].val+=mn,x=fr[x];
		return true;
	}
}
using namespace MCMF;
int main(){
	scanf("%d%d%s%s",&n,&m,s,t),S=2*m,T=2*m+1,memset(head,-1,sizeof(head));
	for(int i=0;i<n;i++)g[HASH(s[i])][HASH(t[i])]++;
	for(int i=0;i<m;i++)ae(S,i,1,0),ae(i+m,T,1,0);
	for(int i=0;i<m;i++)for(int j=0;j<m;j++)ae(i,j+m,1,g[i][j]);
	while(SPFA());
	printf("%d\n",cost);
	for(int i=0;i<m;i++)for(int j=head[i];j!=-1;j=edge[j].next)if(edge[j].to>=m&&edge[j].to<2*m&&!edge[j].val)putchar(HASH(edge[j].to-m));
	return 0;
}