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
namespace Flow{
const int N=10100;
const int M=2001000;
int head[N],cur[N],cnt,S,T;
struct node{int to,next,val;}edge[M];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
}
int dep[N];
bool bfs(){
	static int q[N],l,r;
	l=r=0;q[r++]=S;
	memset(dep,-1,sizeof(dep)),dep[S]=0;
	while(l!=r){
		int x=q[l++];
		for(int i=cur[x]=head[x];i!=-1;i=edge[i].next)if(edge[i].val&&dep[edge[i].to]==-1)
			dep[q[r++]=edge[i].to]=dep[x]+1;
	}
	return dep[T]!=-1;
}
ll res;
bool reach;
int dfs(int x,int flow){
	if(x==T)return res+=flow,reach=true,flow;
	int used=0;
	for(int&i=cur[x];i!=-1;i=edge[i].next){
		if(!edge[i].val||dep[edge[i].to]!=dep[x]+1)continue;
		int ff=dfs(edge[i].to,min(flow-used,edge[i].val));
		if(ff){edge[i].val-=ff,edge[i^1].val+=ff,used+=ff;if(used==flow)break;}
	}
	return used;
}
ll Dinic(){while(bfs()){reach=true;while(reach)reach=false,dfs(S,0x3f3f3f3f);}}
}using namespace Flow;
int n;
map<pair<int,int>,int>mp;
int Z[1010],X[1010],Y[1010];
ll sum;
int main(){
	scanf("%d",&n),S=n<<1|1,T=(n+1)<<1,memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%d%d%d",&X[i],&Y[i],&Z[i]),mp[make_pair(X[i],Y[i])]=i,sum+=Z[i];
	for(int i=1;i<=n;i++){
		if((X[i]&1)&&!(Y[i]&1)){
			ae(S,i+n,Z[i]);
			if(mp.find(make_pair(X[i]+1,Y[i]))!=mp.end())ae(i+n,mp[make_pair(X[i]+1,Y[i])],0x3f3f3f3f);
			if(mp.find(make_pair(X[i]-1,Y[i]))!=mp.end())ae(i+n,mp[make_pair(X[i]-1,Y[i])],0x3f3f3f3f);
		}
		if(!(X[i]&1)&&!(Y[i]&1)){
			ae(i,i+n,Z[i]);
			if(mp.find(make_pair(X[i],Y[i]+1))!=mp.end())ae(i+n,mp[make_pair(X[i],Y[i]+1)],0x3f3f3f3f);
			if(mp.find(make_pair(X[i],Y[i]-1))!=mp.end())ae(i+n,mp[make_pair(X[i],Y[i]-1)],0x3f3f3f3f);
		}
		if(!(X[i]&1)&&(Y[i]&1)){
			ae(i,i+n,Z[i]);
			if(mp.find(make_pair(X[i]+1,Y[i]))!=mp.end())ae(i+n,mp[make_pair(X[i]+1,Y[i])],0x3f3f3f3f);
			if(mp.find(make_pair(X[i]-1,Y[i]))!=mp.end())ae(i+n,mp[make_pair(X[i]-1,Y[i])],0x3f3f3f3f);
		}
		if((X[i]&1)&&(Y[i]&1))ae(i,T,Z[i]);
	}
	Dinic();
	printf("%lld\n",sum-res);
	return 0;
}