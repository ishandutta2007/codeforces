#include<bits/stdc++.h>
using namespace std;
const int N=6e5+3,M=N*2,O=M*2;
char str[N];
int s[N],tu[N],tv[N],sa[N],t[N],rt[M],f[M],p[N],va[M],fa[M][23],o,u,v,id,n,nd,ap,as,h[N];
struct T{
	int l,r,p,s;
}a[O];
void upd(int&k,int l,int r){
	if(k=++id,a[k].p=u,a[k].s=1,l==r)return;
	int m=l+r>>1;
	u>m?upd(a[k].r,m+1,r):upd(a[k].l,l,m);
}
void mg(int&k,int u,int v,int l,int r){
	if(!u||!v)k=u|v;else if(l==r)k=++id,a[k].s=a[u].s+a[v].s,a[k].p=a[u].p;else{
		int m=l+r>>1;
		k=++id,mg(a[k].l,a[u].l,a[v].l,l,m),mg(a[k].r,a[u].r,a[v].r,m+1,r);
		if(a[a[k].l].s<a[a[k].r].s)a[k].s=a[a[k].r].s,a[k].p=a[a[k].r].p;
		else a[k].s=a[a[k].l].s,a[k].p=a[a[k].l].p;
	}
}
void qry(int k,int l,int r){
	if(!k)return;
	if(u<=l&&r<=v){
		if(a[k].s>as)as=a[k].s,ap=a[k].p;
		else if(a[k].s==as)ap=min(ap,a[k].p);
		return;
	}
	int m=l+r>>1;
	if(u<=m)qry(a[k].l,l,m);
	if(m<v)qry(a[k].r,m+1,r);
}
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void meg(int x,int y,int z){f[x]=f[y]=fa[x][0]=fa[y][0]=++nd,va[nd]=z,mg(rt[nd],rt[x],rt[y],1,o);}
int main(){
	int*rk=tu,*b=tv,i,j,k=0,m=1e5,x,y;
	for(scanf("%s%d",str+1,&o),i=0;i<=o;++i){
		if(i)scanf("%s",str+1);
		for(j=1,x=strlen(str+1);j<=x;++j)if(s[j+n]=str[j],i)u=i,upd(rt[j+n],1,o);
		s[n+=j]=i+999;
	}
	for(i=1,nd=n;i<=n;++i)++t[s[i]];
	for(i=1;i<=m;++i)t[i]+=t[i-1];
	for(i=n;i;--i)sa[t[rk[i]=s[i]]--]=i;
	for(i=1;k<n;i*=2,m=k){
		for(j=n-i+1,k=0,memset(t,0,m*4+4);j<=n;++j)b[++k]=j;
		for(j=1;j<=n;++j)if(++t[rk[j]],sa[j]>i)b[++k]=sa[j]-i;
		for(j=1;j<=m;++j)t[j]+=t[j-1];
		for(j=n;j;--j)sa[t[rk[b[j]]]--]=b[j];
		for(j=1,k=y=0,swap(rk,b);j<=n;++j,y=x)x=sa[j],rk[x]=b[x]==b[y]&&b[x+i]==b[y+i]?k:++k;
	}
	for(i=1,k=0;i<=n;h[rk[i++]]=k)if(rk[i]>1)for(j=sa[rk[i]-1],k=max(0,k-1);s[i+k]==s[j+k];++k);
	for(i=1,iota(f,f+M,0);i<=n;++i)p[i]=i,va[i]=n-i+1;
	sort(p+2,p+n+1,[](int x,int y){return h[x]>h[y];});
	for(i=2;i<=n;++i)meg(gf(sa[p[i]-1]),gf(sa[p[i]]),h[p[i]]);
	for(i=nd;i;--i)for(j=0;fa[i][j];++j)fa[i][j+1]=fa[fa[i][j]][j];
	for(scanf("%d",&m);m--;printf("%d %d\n",ap,as)){
		scanf("%d%d%d%d",&u,&v,&x,&y),k=y-x+1;
		for(i=20;~i;--i)if(va[fa[x][i]]>=k)x=fa[x][i];
		ap=u,as=0,qry(rt[x],1,o);
	}
	return 0;
}