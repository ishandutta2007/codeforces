#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int n,m,des[N];
//------------------------Chain Decompotision---------------
int dfn[N],rev[N],fa[N],dep[N],son[N],top[N],sz[N],head[N],cnt,tot;
struct node{
	int to,next;
}edge[200100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
}
void dfs1(int x,int Fa){
	fa[x]=Fa,dep[x]=dep[Fa]+1,sz[x]=1;
	for(int i=head[x],y;i!=-1;i=edge[i].next){
		if((y=edge[i].to)==fa[x])continue;
		dfs1(y,x),sz[x]+=sz[y];
		if(sz[son[x]]<sz[y])son[x]=y;
	}
}
void dfs2(int x){
	if(son[x])top[son[x]]=top[x],dfn[son[x]]=++tot,rev[tot]=son[x],dfs2(son[x]);
	for(int i=head[x],y;i!=-1;i=edge[i].next){
		y=edge[i].to;
		if(y==fa[x]||y==son[x])continue;
		top[y]=y,dfn[y]=++tot,rev[tot]=y,dfs2(y);
	}
}
//--------------Persistent Segment Tree--------------------
#define mid ((l+r)>>1)
int rt[N],newid;
struct SegTree{
	int lson,rson,sum;
}seg[20001000];
void build(int &x,int l,int r){
	x=++newid;
	if(l!=r)build(seg[x].lson,l,mid),build(seg[x].rson,mid+1,r);
}
void modify(int &x,int y,int l,int r,int P){
	if(l>P||r<P)return;
	seg[x=++newid]=seg[y],seg[x].sum++;
	if(l!=r)modify(seg[x].lson,seg[y].lson,l,mid,P),modify(seg[x].rson,seg[y].rson,mid+1,r,P);
}
int asksize(int x,int l,int r,int L,int R){
	if(l>R||r<L)return 0;
	if(L<=l&&r<=R)return seg[x].sum;
	return asksize(seg[x].lson,l,mid,L,R)+asksize(seg[x].rson,mid+1,r,L,R);
}
int rangeask(int x,int y,int l,int r,int k){
	if(l==r)return rev[l];
	if((mid-l+1)-(seg[seg[y].lson].sum-seg[seg[x].lson].sum)>=k)return rangeask(seg[x].lson,seg[y].lson,l,mid,k);
	else return rangeask(seg[x].rson,seg[y].rson,mid+1,r,k-((mid-l+1)-(seg[seg[y].lson].sum-seg[seg[x].lson].sum)));
}
int askkth(int x,int y,int l,int r,int L,int R,int &k,bool &findans){
	if(l>R||r<L)return 0;
	if(L<=l&&r<=R){
		if((r-l+1)-(seg[y].sum-seg[x].sum)>=k){findans=true;return rangeask(x,y,l,r,k);}
		else{k-=(r-l+1)-(seg[y].sum-seg[x].sum);return 0;};
	}
	int tmp=askkth(seg[x].lson,seg[y].lson,l,mid,L,R,k,findans);
	if(findans)return tmp;
	return askkth(seg[x].rson,seg[y].rson,mid+1,r,L,R,k,findans);
}
#define AS(A,B,L,R) (R-L+1)-(asksize(rt[B],1,n,L,R)-asksize(rt[A],1,n,L,R))
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head));
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(x)ae(x,i);
	}
	dfs1(1,0),top[1]=dfn[1]=rev[1]=tot=1,dfs2(1);
	build(rt[0],1,n);
	scanf("%d",&m);
	for(int i=1,a,b,c,d,tp,res;i<=m;i++){
		scanf("%d",&tp);
		if(tp==1)scanf("%d",&a),des[a]=i,modify(rt[i],rt[i-1],1,n,dfn[a]);
		else{
			rt[i]=rt[i-1],res=0;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(des[a]<=d)c++;
			int x=a,y=b,len=0;
			while(top[x]!=top[y]){
				if(dep[top[x]]<dep[top[y]])swap(x,y);
				len+=AS(d,i,dfn[top[x]],dfn[x]),x=fa[top[x]];
			}
			if(dep[x]>dep[y])swap(x,y);
			len+=AS(d,i,dfn[x],dfn[y]);
			len-=(des[b]<=d);
			if(len<c){puts("-1");continue;}
//---------------------getpath&LCA-------------------------			
			int LCA=x;
			x=a;
			bool getans=false;
			while(dep[x]>=dep[LCA]){
				int anc=(dep[top[x]]<dep[LCA]?LCA:top[x]);
				int tmp=AS(d,i,dfn[anc],dfn[x]);
				if(c>tmp)c-=tmp,len-=tmp;
				else{c=tmp-c+1;res=askkth(rt[d],rt[i],1,n,dfn[anc],dfn[x],c,getans);break;}
				x=fa[top[x]];
			}
			if(getans){printf("%d\n",res);continue;}
//--------------------check A-----------------------------
			y=b;
			c=len-c+1;
			if(des[b]<=d)c++;
			while(true){
				int dfntop=dfn[top[y]];
				if(dep[top[y]]<=dep[LCA])dfntop=dfn[LCA]+1;
				int tmp=AS(d,i,dfntop,dfn[y]);
				if(c>tmp)c-=tmp;
				else{c=tmp-c+1;res=askkth(rt[d],rt[i],1,n,dfntop,dfn[y],c,getans);break;}
				y=fa[top[y]];
			}
			printf("%d\n",res);
		}
	}
	return 0;
} 
/*
10
0 1 1 2 2 5 6 6 4 6 
1
2 7 4 1 1
*/