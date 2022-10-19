#include<bits/stdc++.h>
using namespace std;
int n,m,q,c,val[200100];
namespace SCT{//square circle tree?
	int dfn[200100],rev[200100],son[200100],sz[200100],fa[200100],top[200100],dep[200100],tot,mn[800100];
	vector<int>v[200100];
	void ae(int x,int y){
		v[x].push_back(y),v[y].push_back(x);
	}
	multiset<int>s[100100];
	void dfs1(int x,int Fa){
		fa[x]=Fa,dep[x]=dep[Fa]+1,sz[x]=1;
		for(auto y:v[x]){
			if(y==Fa)continue;
			dfs1(y,x);
			if(x>n)s[x-n].insert(val[y]);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]])son[x]=y;
		}
		if(x>n)val[x]=*s[x-n].begin();
	}
	void dfs2(int x){
		dfn[x]=++tot,rev[tot]=x;
		if(son[x])top[son[x]]=top[x],dfs2(son[x]);
		for(auto y:v[x])if(y!=fa[x]&&y!=son[x])top[y]=y,dfs2(y);
	}
	#define lson x<<1
	#define rson x<<1|1
	#define mid ((l+r)>>1)
	void pushup(int x){mn[x]=min(mn[lson],mn[rson]);}
	void build(int x,int l,int r){
		if(l==r){mn[x]=val[rev[l]];return;}
		build(lson,l,mid),build(rson,mid+1,r),pushup(x);
	}
	int query(int x,int l,int r,int L,int R){
		if(l>R||r<L)return 0x3f3f3f3f;
		if(L<=l&&r<=R)return mn[x];
		return min(query(lson,l,mid,L,R),query(rson,mid+1,r,L,R));
	}
	void update(int x,int l,int r,int P){
		if(l>P||r<P)return;
		if(l==r){mn[x]=val[rev[P]];return;}
		update(lson,l,mid,P),update(rson,mid+1,r,P),pushup(x);
	}
	#undef lson
	#undef rson
	#undef mid
	void prepare(){
		dfs1(1,0),top[1]=1,dfs2(1);
//		for(int x=1;x<=c;x++)printf("%d::FA:%d SN:%d SZ:%d DP:%d TP:%d DN:%d RV:%d\n",x,fa[x],son[x],sz[x],dep[x],top[x],dfn[x],rev[x]);
		build(1,1,c);
	}
	int ask(int x,int y){
		int res=0x3f3f3f3f;
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			res=min(res,query(1,1,c,dfn[top[x]],dfn[x])),x=fa[top[x]];
		}
		if(dep[x]>dep[y])swap(x,y);
		res=min(res,query(1,1,c,dfn[x],dfn[y]));
		if(x>n)res=min(res,val[fa[x]]);
//		printf("LCA:%d\n",x);
		return res;
	}
	void modify(int x,int y){
		if(fa[x])s[fa[x]-n].erase(s[fa[x]-n].find(val[x]));
		val[x]=y;
		if(fa[x])s[fa[x]-n].insert(val[x]),val[fa[x]]=*s[fa[x]-n].begin(),update(1,1,c,dfn[fa[x]]);
		update(1,1,c,dfn[x]);
//		for(int i=1;i<=c;i++)printf("%d:%d ",i,val[i]);puts("");
	}
}
namespace Graph{
	vector<int>v[100100];
	int dfn[100100],low[100100],tot;
	stack<int>s;
	void Tarjan(int x){
		dfn[x]=low[x]=++tot,s.push(x);
		for(auto y:v[x]){
			if(!dfn[y]){
				Tarjan(y);
				low[x]=min(low[x],low[y]);
				if(low[y]>=dfn[x]){
					c++;
					while(s.top()!=y)SCT::ae(c,s.top()),s.pop();
					SCT::ae(c,s.top()),s.pop();
					SCT::ae(c,x);
				}
			}else low[x]=min(low[x],dfn[y]);
		}
	}
}
char s[10];
int main(){
	scanf("%d%d%d",&n,&m,&q),c=n;
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),Graph::v[x].push_back(y),Graph::v[y].push_back(x);
	Graph::Tarjan(1);
	SCT::prepare();
	for(int i=1,x,y;i<=q;i++){
		scanf("%s%d%d",s,&x,&y);
		if(s[0]=='C')SCT::modify(x,y);
		else printf("%d\n",SCT::ask(x,y));
	}
	return 0;
}
/*
9 12 12
143171545
629420297
228288417
529363375
635420451
749686836
939343781
970697126
468856358
2 1
3 1
3 2
2 4
5 2
5 4
6 5
7 5
7 6
7 8
7 9
8 9
C 9 227315421
C 9 29228306
A 8 4
C 2 328781042
C 5 656724208
A 4 7
A 4 4
C 4 176212145
C 9 69177357
C 4 867393574
C 8 541752763
A 6 7
*/