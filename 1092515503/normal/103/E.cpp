/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x0101010101010101;
int n,a[310];
namespace MaxFlow{
	const int N=610,M=1000000;
	int head[N],cur[N],dep[N],cnt,S,T;
	ll res;
	struct node{int to,next;ll val;}edge[M];
	void ae(int u,int v,ll w){
		// printf("%d %d %lld\n",u,v,w);
		edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
		edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	queue<int>q;
	inline bool bfs(){
		memset(dep,0,sizeof(dep)),q.push(S),dep[S]=1;
		while(!q.empty()){
			register int x=q.front();q.pop();
			for(register int i=cur[x]=head[x];i!=-1;i=edge[i].next)if(edge[i].val&&!dep[edge[i].to])
				dep[edge[i].to]=dep[x]+1,q.push(edge[i].to);
		}
		return dep[T]>0;
	}
	bool reach;
	inline ll dfs(int x,ll flow){
		if(x==T){res+=flow,reach=true;return flow;}
		ll used=0;
		for(register int &i=cur[x];i!=-1;i=edge[i].next){
			if(!edge[i].val||dep[edge[i].to]!=dep[x]+1)continue;
			register ll ff=dfs(edge[i].to,min(edge[i].val,flow-used));
			if(ff){edge[i].val-=ff,edge[i^1].val+=ff,used+=ff;if(used==flow)break;}
		}
		return used;
	}
	inline void Dinic(){while(bfs()){reach=true;while(reach)reach=false,dfs(S,0x3f3f3f3f3f3f3f3f);}}
}using namespace MaxFlow;
ll sum;
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head)),S=n<<1|1,T=(n+1)<<1;
	for(int i=1,x,j;i<=n;i++){scanf("%d",&x);while(x--)scanf("%d",&j),ae(i,j+n,inf);}
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		ll val=inf-x;
		sum+=val,ae(S,i,val);
		ae(i+n,T,inf);
	}
	Dinic();
	printf("%lld\n",res-sum);
	return 0;
}