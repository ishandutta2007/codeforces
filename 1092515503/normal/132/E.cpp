#include<bits/stdc++.h>
using namespace std;
int n,m,num[500],s,t,deg[100100];
inline void read(int &x){
	x=0;
	register char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
namespace MCMF{
	const int N=100000,M=2000000;
	int head[N],cnt,dis[N],fr[N],id[N],S,T,cost,flow;
	struct node{
		int to,next,val,cost;
	}edge[M];
	inline void ae(int u,int v,int w,int c){
//		printf("%d %d %d\n",u,v,c);
		edge[cnt].cost=c,edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
		edge[cnt].cost=-c,edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	queue<int>q;
	bool in[N];
	inline bool SPFA(){
		memset(dis,0x3f,sizeof(dis)),dis[S]=0,q.push(S),in[S]=true;
		while(!q.empty()){
			register int x=q.front();q.pop(),in[x]=false;
	//		printf("%d\n",x);
			for(register int i=head[x];i!=-1;i=edge[i].next){
				if(!edge[i].val)continue;
				if(dis[edge[i].to]>dis[x]+edge[i].cost){
					dis[edge[i].to]=dis[x]+edge[i].cost,fr[edge[i].to]=x,id[edge[i].to]=i;
					if(!in[edge[i].to])in[edge[i].to]=true,q.push(edge[i].to);
				}
			}
		}
		if(dis[T]==0x3f3f3f3f)return false;
		int x=T,mn=0x3f3f3f3f;
		while(x!=S)mn=min(mn,edge[id[x]].val),x=fr[x];
		cost+=dis[T]*mn,x=T,flow+=mn;
		while(x!=S)edge[id[x]].val-=mn,edge[id[x]^1].val+=mn,x=fr[x];
		return true;
	}
}
using namespace MCMF;
vector<pair<int,int> >res;
stack<int>bin;
map<int,int>val;
int main(){
	read(n),read(m),memset(head,-1,sizeof(head));
	for(register int i=0;i<n;i++)read(num[i]);
	s=n*3,t=n*3+1,S=n*3+2,T=n*3+3;
	for(register int i=0;i<n;i++){
		ae(i,i+n,1,__builtin_popcount(num[i]));
		deg[i+n]--,deg[i+2*n]++;
		ae(i+2*n,i==n-1?t:i+1,1,0);
		for(int j=i+1;j<n;j++)if(num[j]==num[i]){ae(i+2*n,j+n,1,0);break;}
	}
	ae(s,0,m,0),ae(n-1,t,m,0);
	for(int i=0;i<n-1;i++)ae(i,i+1,m,0);
	ae(t,s,0x3f3f3f3f,0);
	for(register int i=0;i<=t;i++){
		if(deg[i]>0)ae(S,i,deg[i],0);
		if(deg[i]<0)ae(i,T,-deg[i],0);
	}
	while(SPFA());
	for(register int i=0;i<m;i++)bin.push(i);
	for(register int i=0;i<n;i++)val[num[i]]=-1;
	for(int i=0;i<n;i++){
		for(int j=head[i];j!=-1;j=edge[j].next)if(edge[j].to==i+n&&!edge[j].val)res.push_back(make_pair(bin.top(),num[i])),val[num[i]]=bin.top(),bin.pop();
		res.push_back(make_pair(-1,val[num[i]]));
		for(int j=head[i+2*n];j!=-1;j=edge[j].next)if(edge[j].to==(i==n-1?t:i+1)&&!edge[j].val)bin.push(val[num[i]]),val[num[i]]=-1;
	}
	printf("%d %d\n",res.size(),cost);
	for(register int i=0;i<res.size();i++)if(res[i].first==-1)printf("print(%c)\n",'a'+res[i].second);else printf("%c=%d\n",'a'+res[i].first,res[i].second);
	return 0;
}