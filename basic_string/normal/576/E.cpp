#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=N<<1,P=M<<1;
int n,x[N],y[N],p[P],q[P],r[P],t,f[51][M],d[51][M],g[N],u,v,o,b[N],c[N],h[N];
int gf(int c,int x){return f[c][x]==x?x:gf(c,f[c][x]);}
inline void mg(int c,int x,int y){
	if(x==y)return;
	if(d[c][x]>d[c][y])swap(x,y);
	p[++t]=x,q[t]=d[c][y],r[t]=c,f[c][x]=y,d[c][y]+=d[c][x]==d[c][y];
}
vector<int>a[P];
void upd(int k,int l,int r){
	if(u<=l&&r<=v){a[k].push_back(o);return;}
	int m=l+r>>1,a=k<<1,b=a|1;
	if(u<=m)upd(a,l,m);
	if(m<v)upd(b,m+1,r);
}
void dfs(int k,int l,int r){
	int j=a[k].size(),i=0,u,v,w,o=t;
	for(;i<j;++i){
		u=a[k][i],v=b[u],w=c[u];
		if(w)mg(w,gf(w,x[v]),gf(w,y[v]+n)),mg(w,gf(w,x[v]+n),gf(w,y[v]));
	}
	if(l==r){
		if(v=b[l],gf(c[l],x[v])==gf(c[l],y[v]))puts("NO"),c[l]=h[v];
		else puts("YES"),h[v]=c[l];
	}else{
		int m=l+r>>1,a=k<<1,b=a|1;
		dfs(a,l,m),dfs(b,m+1,r);
	}
	for(;t>o;--t)w=::r[t],u=p[t],d[w][f[w][u]]=q[t],f[w][u]=u;
}
int main(){
	int m,q,k,i,j;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(i=1;i<=m;++i)scanf("%d%d",x+i,y+i),g[i]=q+1;
	for(i=1;i<=k;++i)for(j=1;j<=n;++j)f[i][j]=j,f[i][j+n]=j+n;
	for(i=1;i<=q;++i)scanf("%d%d",b+i,c+i);
	for(i=q;i;--i){
		o=i,u=i+1,v=g[b[i]]-1,g[b[i]]=i;
		if(u<=v)upd(1,1,q);
	}
	dfs(1,1,q);
	return 0;
}