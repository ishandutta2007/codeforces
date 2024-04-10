#include<bits/stdc++.h>
using namespace std;
const int BBB=316;
int n,m,ccc[100100],col[100100],head[100100],cnt,occ[100100],sta[100100],sum[400],dfn[100100],sz[100100],BLK[100100],lp[400],tot,res[100100];
struct node{
	int to,next;
}edge[200100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
}
void dfs(int x,int fa){
	dfn[x]=++tot,col[tot]=ccc[x],sz[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa)dfs(edge[i].to,x),sz[x]+=sz[edge[i].to];
}
struct query{
	int l,r,k,id;
	query(int a=0,int b=0,int c=0,int d=0){
		l=a,r=b,k=c,id=d;
	}
	friend bool operator <(const query &x,const query &y){
		if(BLK[x.l]!=BLK[y.l])return BLK[x.l]<BLK[y.l];
		return BLK[x.l]&1?x.r<y.r:x.r>y.r;
	}
}q[100100];
void Push(int pos){
	sta[occ[col[pos]]]--,sum[BLK[occ[col[pos]]]]--;
	occ[col[pos]]++;
	sta[occ[col[pos]]]++,sum[BLK[occ[col[pos]]]]++;
}
void Pop(int pos){
	sta[occ[col[pos]]]--,sum[BLK[occ[col[pos]]]]--;
	occ[col[pos]]--;
	sta[occ[col[pos]]]++,sum[BLK[occ[col[pos]]]]++;
}
int calc(int k){
	int ans=0;
	for(int i=BLK[k]+1;i<=BLK[n-1];i++)ans+=sum[i];
	for(int i=k;i<lp[BLK[k]+1];i++)ans+=sta[i];
	return ans;
}
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=0;i<n;i++)scanf("%d",&ccc[i]);
	for(int i=0;i<=n;i++)BLK[i]=i/BBB;
	for(int i=0;i<=BLK[n];i++)lp[i]=i*BBB;
	lp[BLK[n]+1]=n+1,sta[0]=n;
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),ae(--x,--y);
	dfs(0,-1);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),x--,q[i]=query(dfn[x],dfn[x]+sz[x]-1,y,i);
	sort(q+1,q+m+1);
	Push(1);
	for(int i=1,L=1,R=1;i<=m;i++){
		while(L>q[i].l)Push(--L);
		while(R<q[i].r)Push(++R);
		while(L<q[i].l)Pop(L++);
		while(R>q[i].r)Pop(R--);
		res[q[i].id]=calc(q[i].k);
	}
	for(int i=1;i<=m;i++)printf("%d\n",res[i]);
	return 0;
}