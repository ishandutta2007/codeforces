#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k,sx,sy,sz,lcas,ans,tot,f[400039],x[100039],y[100039],z,top[100039],d[100039],fa[100039],siz[100039],son[100039],id[100039],idea;
struct yyy{int to,z;};
struct ljb{
	int head,h[100039];
	yyy f[200039];
	inline void add(int x,int y){
		f[++head]=(yyy){y,h[x]};
		h[x]=head;
	}
}s;
inline void get(int x,int y,int l,int r,int now){
	if(l==r){f[now]=y;return;}
	int m=(l+r)>>1;
	if(x<=m) get(x,y,l,m,now<<1);
	else get(x,y,m+1,r,now<<1|1);
	f[now]=f[now<<1]+f[now<<1|1];
}
inline int find(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y)return f[now];
	int m=(l+r)>>1,fs=0;
	if(x<=m) fs+=find(x,y,l,m,now<<1);
	if(y>m) fs+=find(x,y,m+1,r,now<<1|1);
	return fs;
}
inline void dfs1(int x,int last){
	d[x]=d[last]+1;
	fa[x]=last;
	siz[x]=1;
	int cur=s.h[x],pus=0;
	yyy tmp;
	while(cur!=-1){
		tmp=s.f[cur];
		if(tmp.to!=last){
			dfs1(tmp.to,x);
			siz[x]+=siz[tmp.to];
			if(siz[son[x]]<siz[tmp.to]) son[x]=tmp.to;
		}
		cur=tmp.z;
	}
}
inline void dfs2(int x,int last){
	top[x]=last;
	id[x]=++idea;
	if(x!=1)get(idea,1,1,n,1);
	if(!son[x]) return;
	dfs2(son[x],last);
	int cur=s.h[x];
	yyy tmp;
	while(cur!=-1){
		tmp=s.f[cur];
		if(tmp.to!=fa[x]&&tmp.to!=son[x])dfs2(tmp.to,tmp.to);
		cur=tmp.z;
	}
}
inline void swap(int &x,int &y){x^=y^=x^=y;}
inline int finds(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]]) swap(x,y);
		ans+=find(id[top[x]],id[x],1,n,1);
		x=fa[top[x]];
	}
	if(d[x]>d[y]) swap(x,y);
	ans+=find(id[x]+1,id[y],1,n,1);
	return ans;
}
inline int lca(int x,int y){
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if(d[x]>d[y]) swap(x,y);
	return x;
}
int main(){
	memset(s.h,-1,sizeof(s.h));
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&n);
	for(i=1;i<n;i++)scanf("%d%d",&x[i],&y[i]),s.add(x[i],y[i]),s.add(y[i],x[i]);
	dfs1(1,0);dfs2(1,1);
	scanf("%d",&m);
	while(m--){
		scanf("%d",&sx);
		if(sx==1){
			scanf("%d",&sz);
			sx=x[sz];sy=y[sz];
			if(d[sx]<d[sy]) swap(sx,sy);
			get(id[sx],1,1,n,1);
		}
		else if(sx==2){
			scanf("%d",&sz);
			sx=x[sz];sy=y[sz];
			if(d[sx]<d[sy]) swap(sx,sy);
			get(id[sx],0,1,n,1);
		}
		else{
			scanf("%d%d",&sx,&sy);
			lcas=lca(sx,sy);
			ans=finds(sx,sy);
			if(ans==d[sx]+d[sy]-2*d[lcas]) printf("%d\n",ans);
			else printf("-1\n");
		}
	}
}