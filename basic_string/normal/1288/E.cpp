#include<bits/stdc++.h>
using namespace std;
int s[2500009],L[300009],R[300009],a[300009],u;
void upd(int k,int l,int r){
	++s[k];
	if(l==r)return;
	register int m=l+r>>1;
	if(u<=m)upd(k<<1,l,m);else upd(k<<1|1,m+1,r);
}
void del(int k,int l,int r){
	--s[k];
	if(l==r)return;
	register int m=l+r>>1;
	if(u<=m)del(k<<1,l,m);else del(k<<1|1,m+1,r);
}
int qry(int k,int l,int r){
	if(l==r)return s[k];
	register int m=l+r>>1;
	if(u<=m)return qry(k<<1,l,m)+s[k<<1|1];
	return qry(k<<1|1,m+1,r);
}
int main(){
	register int n,m,p,g,i,j;
	scanf("%d%d",&n,&m),p=n,g=n+m;
	for(i=1;i<=n;++i)L[i]=R[i]=i,u=a[i]=n-i+1,upd(1,1,g);
	while(m--){
		scanf("%d",&i),L[i]=1;
		u=a[i],R[i]=max(R[i],qry(1,1,g));
		u=a[i],del(1,1,g);
		u=a[i]=++p,upd(1,1,g);
	}
	for(i=1;i<=n;++i)u=a[i],R[i]=max(R[i],qry(1,1,g));
	for(i=1;i<=n;++i)printf("%d %d\n",L[i],R[i]);
	return 0;
}//