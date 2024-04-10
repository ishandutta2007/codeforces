#include<cstdio>
struct seg{
	int l,r,v;
}s[20000005];
int rt[200005],a[200005],n,u,v,id;
void upd(int&k,int l,int r){
	if(!k)k=++id;
	s[k].v+=v;
	if(l==r)return;
	register int m=l+r>>1;
	if(u<=m)upd(s[k].l,l,m);else upd(s[k].r,m+1,r);
}
int qry(int k,int l,int r){
	if(l==r)return 0;
	register int m=l+r>>1;
	if(u<=m)return qry(s[k].l,l,m);
	return s[s[k].l].v+qry(s[k].r,m+1,r);
}
void pupd(int x){
	for(;x<=n;x+=x&-x)upd(rt[x],1,n);
}
int pqry(int l,int r){
	register int i,z=0;
	for(i=l-1;i;i-=i&-i)z-=qry(rt[i],1,n);
	for(i=r;i;i-=i&-i)z+=qry(rt[i],1,n);
	return z;
}
int main(){
	register int k,i,j,l;
	register long long ans=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)u=a[i]=i,v=1,pupd(i);
	for(;k;printf("%lld\n",ans),--k){
		scanf("%d%d",&i,&j);
		if(i==j)continue;
		if(i>j)l=i,i=j,j=l;
		u=a[i],ans+=j-i-1-(pqry(i+1,j-1)<<1);
		u=a[j],ans+=(pqry(i+1,j-1)<<1)-j+i+1;
		if(a[i]>a[j])--ans;else ++ans;
		v=-1,u=a[i],pupd(i),u=a[j],pupd(j);
		v=1,u=a[i],pupd(j),u=a[j],pupd(i);
		l=a[i],a[i]=a[j],a[j]=l;
	}
	return 0;
}