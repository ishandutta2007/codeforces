#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,M=N*4;
#define ll long long
ll s[M],mn[M],a[N],tg[M];
void build(int k,int l,int r){
	if(l==r){
		s[k]=mn[k]=a[l];
		return;
	}
	int m=l+r>>1;
	build(k*2,l,m),build(k*2+1,m+1,r);
	s[k]=s[k*2]+s[k*2+1],mn[k]=mn[k*2+1]; 
}
int u,uu,o;
ll v,w,z;
void dn(int k,int a,int b,int l,int m,int r){
	if(tg[k]){
		tg[a]=tg[b]=mn[a]=mn[b]=tg[k];
		s[a]=(m-l+1)*tg[k],s[b]=(r-m)*tg[k];
		tg[k]=0;
	}
}
void upd(int k,int l,int r){
	if(u<=l&&r<=o){
		s[k]=(r-l+1)*v,mn[k]=tg[k]=v;
		return;
	}
	int m=l+r>>1;
	dn(k,k*2,k*2+1,l,m,r);
	if(u<=m)upd(k*2,l,m);
	if(m<o)upd(k*2+1,m+1,r);
	s[k]=s[k*2]+s[k*2+1],mn[k]=mn[k*2+1]; 
}
void qmn(int k,int l,int r){
	if(l==r){
		if(mn[k]>w)o=l+1;
		else o=l;
		return;
	}
	int m=l+r>>1;
	dn(k,k*2,k*2+1,l,m,r);
	if(mn[k*2]>w)qmn(k*2+1,m+1,r);
	else qmn(k*2,l,m);
}
void qs(int k,int l,int r){
	if(l==r){
		if(z+s[k]<=w)o=l;
		else o=l-1;
		return;
	}
	int m=l+r>>1;
	dn(k,k*2,k*2+1,l,m,r);
	if(z+s[k*2]<=w)z+=s[k*2],qs(k*2+1,m+1,r);
	else qs(k*2,l,m);
}
ll qry(int k,int l,int r){
	if(r<=u)return s[k];
	int m=l+r>>1;
	dn(k,k*2,k*2+1,l,m,r);
	if(m<u)return s[k*2]+qry(k*2+1,m+1,r);
	return qry(k*2,l,m);
}
int main(){
	int n,q,i;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)scanf("%lld",a+i);
	build(1,1,n);
	while(q--){
		scanf("%d%d%lld",&i,&u,&v);
		if(i==1){
			w=v,qmn(1,1,n);
			if(o<=u)swap(o,u),upd(1,1,n);
		}else{
			i=0;
			while(1){
				w=v,qmn(1,1,n),o=max(o,u);
				if(o>n)break;
				u=o-1;
				if(u==0)w=v;
				else w=v+qry(1,1,n);
				z=0,qs(1,1,n);
				i+=o-u,u=o,v=w-qry(1,1,n),++u;
			}
			printf("%d\n",i);
		}
	}
	return 0;
}