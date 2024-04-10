#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int n,K,q;
int son[N],fa[N],dfn[N],top[N],bot[N],sz[N],dep[N],lit[N],tot;
vector<int>v[N];
void dfs1(int x){
	sz[x]=1,dep[x]=dep[fa[x]]+1;
	for(auto y:v[x])if(y!=fa[x]){
		fa[y]=x,dfs1(y),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
namespace DSG{
int rt[N],cnt,bin[N*40],tp;
#define lson seg[x].ch[0]
#define rson seg[x].ch[1]
#define mid (l+r-(l+r<0))/2
struct SegTree{int ch[2],num;}seg[N*40];
int newnode(){return tp?bin[tp--]:++cnt;}
void delnode(int&x){bin[++tp]=x,seg[x].num=0,x=0;}
void modify(int&x,int l,int r,int P,int dlt){
//	printf("MODIFY:%d[%d,%d]%d:%d\n",x,l,r,P,dlt);
	if(!x)x=newnode();seg[x].num+=dlt;
	if(l!=r)P<=mid?modify(lson,l,mid,P,dlt):modify(rson,mid+1,r,P,dlt);
	if(!seg[x].num)delnode(x);
}
int retrieve(int x,int l,int r,int sum){
	if(l==r)return l;
	if(seg[rson].num-seg[lson].num+sum>=mid)
		return retrieve(rson,mid+1,r,sum-seg[lson].num);
	else return retrieve(lson,l,mid,sum+seg[rson].num);
}
int retrieve(int x,int l,int r,int P,int sum){
//	printf("RETRI:%d[%d,%d](%d):%d\n",x,l,r,P,sum);
	if(l==r)return l;
	if(seg[rson].num-seg[lson].num+sum+(P<=mid?-1:1)>=mid)
		return retrieve(rson,mid+1,r,P,sum-seg[lson].num);
	else return retrieve(lson,l,mid,P,sum+seg[rson].num);
}
#undef lson
#undef rson
#undef mid
void modify(int x,int P,int dlt){modify(rt[x],-n-4,n+4,P,dlt);}
int retrieve(int x){return retrieve(rt[x],-n-4,n+4,0);}
int retrieve(int x,int P){return retrieve(rt[x],-n-4,n+4,P,0);}
}
using DSG::modify;
using DSG::retrieve;
namespace TSG{
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
struct Trans{
int a[5];
Trans(){for(int i=0;i<5;i++)a[i]=i-2;}
int&operator[](const int&x){return a[x+2];}
friend Trans operator*(Trans u,Trans v){Trans w;for(int i=-2;i<=2;i++)w[i]=v[u[i]];return w;}
void print()const{putchar('[');for(int i=0;i<5;i++)printf("%d%c",a[i],i==4?']':',');}
}seg[400100];
Trans query(int x,int l,int r,int L,int R){
//	printf("QUERY:%d[%d,%d][%d,%d]\n",x,l,r,L,R);
	if(l>R||r<L)return Trans();
	if(L<=l&&r<=R)return seg[x];
	return query(rson,mid+1,r,L,R)*query(lson,l,mid,L,R);
}
void endow(int x,int l,int r,int P,Trans V){
//	printf("ENDOW:%d[%d,%d]%d",x,l,r,P);V.print(),puts("");
	if(l==r)seg[x]=V;
	else P<=mid?endow(lson,l,mid,P,V):endow(rson,mid+1,r,P,V),seg[x]=seg[rson]*seg[lson];
}
#undef lson
#undef rson
#undef mid
int DP(int x){return query(1,1,n,dfn[x],dfn[bot[top[x]]])[0]+lit[x];}
void reendow(int x){
//	printf("REENDOW:%d\n",x);
	Trans V;
	if(son[x])for(int i=-2,f=lit[son[x]];i<=2;i++)V[i]=retrieve(x,f+i)-lit[x];
	else for(int i=-2;i<=2;i++)V[i]=i;
//	V.print(),puts("");
	endow(1,1,n,dfn[x],V);
}
}
using TSG::DP;
using TSG::reendow;
using TSG::Trans;
void dfs2(int x){
//	printf("%d\n",x);
	dfn[x]=++tot;if(!top[x])top[x]=x;bot[top[x]]=x;
	if(son[x])top[son[x]]=top[x],dfs2(son[x]);
	for(auto y:v[x])if(y!=fa[x]&&y!=son[x])dfs2(y),modify(x,DP(y),1);
	if(son[x])lit[x]=retrieve(x);
	reendow(x);
}
void reset(int x,int y){
	static int f[N];
	for(int i=x;fa[top[i]];i=fa[top[i]])f[i]=DP(top[i]);
	lit[x]=(y?n+1:-n-1);
	while(fa[top[x]])
		reendow(fa[x]),
		modify(fa[top[x]],f[x],-1),modify(fa[top[x]],DP(top[x]),1),
		lit[fa[top[x]]]=retrieve(fa[top[x]]),
		x=fa[top[x]];
	if(fa[x])reendow(fa[x]);
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),lit[i]=(x==1?n+1:(x==0?-n-1:0));
	dfs1(1),dfs2(1),scanf("%d",&q);
//	for(int i=1;i<=n;i++)printf("%d ",top[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d ",lit[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d ",DP(i));puts("");
	for(int i=1,tp,x,y;i<=q;i++){
		scanf("%d%d",&tp,&x);
		if(tp==1)printf("%d\n",K<DP(x));
		if(tp==2)scanf("%d",&y),reset(x,y);
		if(tp==3)K=x;
	}
//	for(int i=1;i<=n;i++)printf("%d ",DP(i));puts("");
	return 0;
} 
/*
10 0
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
-1 -1 -1 -1 -1 -1 -1 -1 -1 0
1
2 10 1
*/