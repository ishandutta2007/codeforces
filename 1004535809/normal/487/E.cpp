#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=1e5;
int n,m,qu,w[MAXN*2+5],cnt;
namespace segtree{
	struct node{int l,r,val;} s[MAXN*8+5];
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;s[k].val=0x3f3f3f3f;if(l==r) return;
		int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	}
	void modify(int k,int x,int v){
		if(s[k].l==s[k].r){s[k].val=v;return;}
		int mid=(s[k].l+s[k].r)>>1;
		if(x<=mid) modify(k<<1,x,v);
		else modify(k<<1|1,x,v);
		s[k].val=min(s[k<<1].val,s[k<<1|1].val);
	}
	int query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r) return s[k].val;
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid) return query(k<<1,l,r);
		else if(l>mid) return query(k<<1|1,l,r);
		else return min(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
	}
}
namespace tree{
	int hd[MAXN*4+5],nxt[MAXN*4+5],to[MAXN*4+5],ec=0;
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
	int siz[MAXN*2+5],fa[MAXN*2+5],wson[MAXN*2+5],dep[MAXN*2+5];
	int top[MAXN*2+5],dfn[MAXN*2+5],tim=0;
	void dfs1(int x,int f){
		fa[x]=f;siz[x]=1;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;
			dep[y]=dep[x]+1;dfs1(y,x);siz[x]+=siz[y];
			if(siz[y]>siz[wson[x]]) wson[x]=y;
		}
	}
	void dfs2(int x,int tp){
		dfn[x]=++tim;top[x]=tp;
		if(wson[x]) dfs2(wson[x],tp);
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==fa[x]||y==wson[x]) continue;
			dfs2(y,y);
		}
	}
	multiset<int> st[MAXN+5];
	void prework(){
		dfs1(1,0);dfs2(1,1);segtree::build(1,1,cnt);
		for(int i=2;i<=n;i++) w[fa[i]]=min(w[fa[i]],w[i]),st[fa[i]-n].insert(w[i]);
		for(int i=1;i<=n-cnt;i++) st[i].insert(0x3f3f3f3f);
//		for(int i=1;i<=cnt;i++) printf("%d %d %d %d %d %d\n",fa[i],siz[i],dep[i],wson[i],top[i],dfn[i]);
		for(int i=1;i<=cnt;i++) segtree::modify(1,dfn[i],w[i]);
	}
	void change(int x,int v){
		if(x!=1){
			st[fa[x]-n].erase(st[fa[x]-n].find(w[x]));st[fa[x]-n].insert(v);
			w[fa[x]]=*st[fa[x]-n].begin();segtree::modify(1,dfn[fa[x]],w[fa[x]]);
		} w[x]=v;segtree::modify(1,dfn[x],w[x]);
	}
	int query(int x,int y){
		if(dep[x]<dep[y]) swap(x,y);
		int ret=0x3f3f3f3f;
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			chkmin(ret,segtree::query(1,dfn[top[x]],dfn[x]));
			x=fa[top[x]];
		}
		if(dep[x]<dep[y]) swap(x,y);
		chkmin(ret,segtree::query(1,dfn[y],dfn[x]));
//		printf("%d\n",y);
		if(y>n) chkmin(ret,w[fa[y]]);
		return ret;
	}
}
namespace graph{
	int hd[MAXN*2+5],nxt[MAXN*2+5],to[MAXN*2+5],ec=0;
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
	int dfn[MAXN+5],low[MAXN+5],stk[MAXN+5],top=0,tim=0;
	void tarjan(int x){
		dfn[x]=low[x]=++tim;stk[++top]=x;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(!dfn[y]){
				tarjan(y);low[x]=min(low[x],low[y]);
				if(low[y]>=dfn[x]){
					cnt++;w[cnt]=0x3f3f3f3f;int z;
					do {
						//printf("%d ",stk[top]);
						z=stk[top];tree::adde(cnt,z);tree::adde(z,cnt);top--;
					} while(z!=y);
					tree::adde(cnt,x);tree::adde(x,cnt);//printf("%d\n",x);
				}
			} else low[x]=min(low[x],dfn[y]);
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&qu);cnt=n;
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		graph::adde(u,v);graph::adde(v,u);
	} graph::tarjan(1);tree::prework();
	while(qu--){
		char opt[3];int x,y;scanf("%s%d%d",opt+1,&x,&y);
		if(opt[1]=='C') tree::change(x,y);
		else printf("%d\n",tree::query(x,y));
	}
	return 0;
}
/*
9 9 1
2
4
8
7
7
6
7
8
10
2 1
1 7
3 2
4 3
5 4
5 6
6 7
4 8
2 9
A 4 3
*/