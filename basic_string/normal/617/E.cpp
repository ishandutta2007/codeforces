#include<cstdio>
#include<algorithm>
#include<cmath>
int n,m,k,a[100009],p[1050005];
long long ans,g[100009];
struct qry{
	int l,r,b,id;
	inline bool operator<(qry a)const{return b!=a.b?(b<a.b):((b&1)?(r<a.r):(r>a.r));}
}q[100009];
inline void add(int x){
	ans+=p[a[x]^k],++p[a[x]];
}
inline void del(int x){
	--p[a[x]],ans-=p[a[x]^k];
}
int main(){
	register int i,j,l=1,r=0;
	scanf("%d%d%d",&n,&m,&k),j=sqrt(n);
	for(i=1;i<=n;++i)scanf("%d",a+i),a[i]^=a[i-1];
	for(i=1;i<=m;++i)scanf("%d%d",&q[i].l,&q[i].r),--q[i].l,q[i].b=q[i].l/j,q[i].id=i;
	std::sort(q+1,q+m+1);
	for(i=1;i<=m;++i){
		while(l<q[i].l)del(l++);
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(r>q[i].r)del(r--);
		g[q[i].id]=ans;
	}
	for(i=1;i<=m;++i)printf("%lld\n",g[i]);
	return 0;
}