#include<cstdio>
#include<cmath>
#include<queue>
#define beg(x) int cur=s.h[x]
#define end cur
#define go cur=tmp.z
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,w[100039],ans,a[100039],ah,lcas,now;
int xs[100039],ys[100039];
int top[100039],d[100039],siz[100039],son[100039],fa[100039];
struct yyy{int to,z;}tmp;
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
	for(beg(x);end;go){
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
	for(beg(x);end;go){
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
queue<int> q;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j,h;
	scanf("%d%d",&n,&m);k=max(sqrt(m*1.0/log2(m))*2,1);
	for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);
	for(i=0;i<m;i++) scanf("%d%d",&xs[i],&ys[i]);
	dfs1(1,0);dfs2(1,1);
	for(i=1;i<=n;i++) w[i]=d[i]-1;
	for(i=0;i<=m/k;i++){
		ah=0;
		for(j=i*k;j<m&&j<=i*k+k-1;j++){
			if(xs[j]==2){
				ans=w[ys[j]];
				for(h=1;h<=ah;h++) lcas=lca(ys[j],a[h]),ans=min(ans,d[ys[j]]+d[a[h]]-d[lcas]*2);
				printf("%d\n",ans);
			}
			else a[++ah]=ys[j];
		}
		for(j=1;j<=ah;j++)q.push(a[j]),w[a[j]]=0;
		while(!q.empty()){
			now=q.front();q.pop();
			for(beg(now);end;go){
				tmp=s.f[cur];
				if(w[tmp.to]>w[now]+1)w[tmp.to]=w[now]+1,q.push(tmp.to);  
			}
		}
	}
}/////