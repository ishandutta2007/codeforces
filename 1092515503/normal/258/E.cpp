#include<bits/stdc++.h>
using namespace std;
int n,m,head[100100],cnt,tot,dfn[100100],sz[100100],rt[500100],res[100100];
struct SegTree{
	int lson,rson,sum;
}seg[10001000];
#define mid ((l+r)>>1)
#define pushup(x) seg[x].sum=seg[seg[x].lson].sum+seg[seg[x].rson].sum
void build(int &x,int l,int r){
	x=++cnt,seg[x].sum=0;
	if(l!=r)build(seg[x].lson,l,mid),build(seg[x].rson,mid+1,r);
}
void modify(int &x,int pre,int l,int r,int L,int R){
	if(l>R||r<L)return;
	x=pre;
	if(seg[x].sum==r-l+1)return;
	seg[x=++cnt]=seg[pre];
	if(L<=l&&r<=R){seg[x].sum=r-l+1;return;}
	modify(seg[x].lson,seg[pre].lson,l,mid,L,R),modify(seg[x].rson,seg[pre].rson,mid+1,r,L,R),pushup(x);
}
struct Edge{
	int to,next;
}edge[200100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
} 
void dfs1(int x,int fa){
	sz[x]=1,dfn[x]=++tot;
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa)dfs1(edge[i].to,x),sz[x]+=sz[edge[i].to];
}
vector<int>v[100100];
bool modi[100100];
void dfs2(int x,int fa){
	modi[x]=modi[fa];
	if(v[x].empty())rt[x]=rt[fa];
	else{
		modi[x]=true;
		modify(rt[++tot],rt[fa],1,n,dfn[x],dfn[x]+sz[x]-1);
		for(int i=0;i<v[x].size();i++)++tot,modify(rt[tot],rt[tot-1],1,n,dfn[v[x][i]],dfn[v[x][i]]+sz[v[x][i]]-1);
		rt[x]=rt[tot];
	}
	res[x]=seg[rt[x]].sum-modi[x];
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa)dfs2(edge[i].to,x);
}
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),ae(x,y);
	dfs1(1,0);
	cnt=0,tot=n;
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	build(rt[0],1,n),dfs2(1,0);
//	printf("%d %d\n",tot,cnt);
	for(int i=1;i<=n;i++)printf("%d ",res[i]);puts("");
	return 0;
}
/*
5 1
1 2
1 3
3 5
3 4

2 3


11 3
1 2
2 3
2 4
1 5
5 6
5 7
5 8
6 9
8 10
8 11

2 9
3 6
2 8
*/