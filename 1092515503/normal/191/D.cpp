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
const int N=101000;
int n,m,head[N],dfn[N],low[N],tot,stk[N],col[N],tp,c,deg[N],ged[N],res;
struct node{int to,next;}edge[610000];
void ae(int u,int v){
	static int cnt;
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
}
bool sp[N];
void Tarjan(int x,int fi){
	dfn[x]=low[x]=++tot,stk[++tp]=x;
	for(int i=head[x],y;i!=-1;i=edge[i].next)if((i^fi)!=1){
		if(!dfn[y=edge[i].to])Tarjan(y,i),low[x]=min(low[x],low[y]);
		else low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]!=low[x])return;
	sp[++c]=(stk[tp]!=x);int y;do col[y=stk[tp--]]=c;while(y!=x);
}
namespace IO {
	inline char nc(){
		static char buf[500001],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,500000,stdin),p1==p2)?EOF:*p1++;
	}
	char out[500001],*pout=out,*eout=out+500000;
	template<typename T> inline T read(){
		char ch=nc(); T sum=0; bool f=false;
		for(;ch<'0'||ch>'9';ch=nc()) if(ch=='-') f=1;
		while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
		return f ? -sum : sum;
	}
}
#define read IO::read<int>
int main(){
	n=read(),m=read(),memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<=m;i++)x=read(),y=read(),ae(x,y);
	Tarjan(1,-1);
	res=c-1;
	for(int x=1;x<=n;x++){
		int num=0;
		for(int i=head[x];i!=-1;i=edge[i].next)if(col[edge[i].to]!=col[x])num++;
		ged[col[x]]+=!!num;
		res-=num>>1,num&=1;
		deg[col[x]]+=num;
	}
	for(int i=1;i<=c;i++)if(ged[i]<=1&&sp[i])res++;
	printf("%d %d\n",res,m);
	return 0;
}
/*
5 5
1 2
2 3
3 1
2 4
2 5

6 7
1 2
2 3
3 1
4 5
5 6
6 4
1 4

6 6
1 2
2 3
3 1
1 4
1 5
2 6

6 6
1 2
2 3
3 1
1 4
3 5
2 6
*/