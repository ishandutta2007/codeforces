#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,lg[100039],ans[100039],fa[100039][23],d[100039],fi[100039],fj[100039];
struct yyy{int to,w,z;};
struct ljb{
	int head,h[100039];
	yyy s[200039];
	inline void add(int x,int y){
		s[++head]=(yyy){y,0,h[x]};
		h[x]=head;
	}
}l;
inline void dfs(int x,int last){
	fa[x][0]=last;
	d[x]=d[last]+1;
	for(int k=1;k<=lg[d[x]];k++) fa[x][k]=fa[fa[x][k-1]][k-1];
	int cur=l.h[x];
	yyy tmp;
	while(cur!=-1){
		tmp=l.s[cur];
		if(tmp.to!=last) dfs(tmp.to,x);
		cur=tmp.z;
	}
}
inline void swap(int &x,int &y){x^=y,y^=x,x^=y;}
inline int lca(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	while(d[x]>d[y]) x=fa[x][lg[d[x]-d[y]]-1];
	if(x==y)return x;
	for(int k=lg[d[x]]-1;k>=0;k--) if(fa[x][k]!=fa[y][k]) x=fa[x][k],y=fa[y][k];
	return fa[x][0];
}
inline int dfs2(int x,int last){
	int cur=l.h[x];
	yyy tmp;
	l.s[last].w=fj[x]+fi[x];
	while(cur!=-1){
		tmp=l.s[cur];
		if(tmp.to!=fa[x][0]) l.s[last].w+=dfs2(tmp.to,cur);
		cur=tmp.z;
	}
	return l.s[last].w;
}
int main(){
	memset(l.h,-1,sizeof(l.h));
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	for(i=1;i<n;i++) scanf("%d%d",&x,&y),l.add(x,y),l.add(y,x);
	dfs(1,1);
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		fi[lca(x,y)]-=2;
		fj[x]++;fj[y]++;
	}
	dfs2(1,0);
	for(i=1;i<=2*n-2;i+=2) printf("%d ",max(l.s[i].w,l.s[i+1].w));
}