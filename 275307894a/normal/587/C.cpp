#include<cstdio>
#include<vector>
#define beg int cur=s.h[x]
#define end cur
#define go cur=tmp.z
#define l(x) f[x].l
#define r(x) f[x].r
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,top[100039],d[100039],fa[100039],siz[100039],son[100039],q,lcas,cnt,root[100039];
struct yyy{int to,z;};
struct ljb{
	int head,h[100039];
	yyy f[200039];
	inline void add(int x,int y){
		f[++head]=(yyy){y,h[x]};
		h[x]=head;
	}
}s;
inline void dfs1(int x,int last){
	fa[x]=last;d[x]=d[last]+1;siz[x]=1;yyy tmp;
	for(beg;end;go){
		tmp=s.f[cur];
		if(tmp.to!=last){
			dfs1(tmp.to,x);
			siz[x]+=siz[tmp.to];
			if(siz[son[x]]<siz[tmp.to]) son[x]=tmp.to;
		}
	}
}
inline void dfs2(int x,int last){
	top[x]=last;yyy tmp;
	if(!son[x]) return;
	dfs2(son[x],last);
	for(beg;end;go){
		tmp=s.f[cur];
		if(tmp.to!=fa[x]&&tmp.to!=son[x]) dfs2(tmp.to,tmp.to);
	}
}
inline void swap(int &x,int &y){x^=y^=x^=y;}
inline int lca(int x,int y){
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return d[x]<d[y]?x:y;
}
struct tree{int l,r,f;}f[30000039];
vector<int> g[100039];
inline void xj(int &now){f[++cnt]=f[now];now=cnt;}
inline void get(int x,int l,int r,int &now){
	xj(now);f[now].f++;
	if(l==r)return;
	int m=l+r>>1;
	if(x<=m) get(x,l,m,l(now));
	else get(x,m+1,r,r(now));
}
inline void dfs(int x,int last){
	yyy tmp;root[x]=root[last];
	for(int i=0;i<g[x].size();i++) get(g[x][i],1,m,root[x]);
	for(beg;end;go){
		tmp=s.f[cur];
		if(tmp.to!=last) dfs(tmp.to,x);
	}
}
inline int find(int now1,int now2,int now3,int now4,int z){
	int l=1,r=m,mid;
	while(l!=r){
		mid=(l+r)>>1;
		if(f[l(now1)].f+f[l(now2)].f-f[l(now3)].f-f[l(now4)].f>=z) {
			r=mid;
			now1=l(now1);now2=l(now2);now3=l(now3);now4=l(now4);
		}
		else{
			l=mid+1;
			z-=f[l(now1)].f+f[l(now2)].f-f[l(now3)].f-f[l(now4)].f;
			now1=r(now1);now2=r(now2);now3=r(now3);now4=r(now4);
		}
	}
	return l;
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);
	for(i=1;i<=m;i++)scanf("%d",&x),g[x].push_back(i);
	dfs(1,0);dfs1(1,0);dfs2(1,1);
	while(q--){
		scanf("%d%d%d",&x,&y,&z);
		lcas=lca(x,y);
		z=min(z,f[root[x]].f+f[root[y]].f-f[root[lcas]].f-f[root[fa[lcas]]].f);
		printf("%d ",z);
		for(i=1;i<=z;i++)printf("%d ",find(root[x],root[y],root[lcas],root[fa[lcas]],i));
		printf("\n");
	}
}