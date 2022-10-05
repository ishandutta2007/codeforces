#include<bits/stdc++.h>
using namespace std;
const int N=8e5+5;
struct L{
	int a[33],w,t;
	void ins(int x){
		if(x)for(int i=30;~i;--i)if(x&(1<<i)){
			if(!a[i]){a[i]=x;return;}
			x^=a[i];
		}
	}
};L o;
L mg(L p,L q){
	L r=o;
	for(int i=30;~i;--i)r.ins(p.a[i]),r.ins(q.a[i]);
	r.ins(p.w^q.w),r.w=q.w;
	return r;
}
int u,v,w;
L s[800009],x;
void build(int k,int l,int r){
	if(l==r)return scanf("%d",&s[k].w),void();
	int m=l+r>>1,a=k<<1,b=a|1;
	build(a,l,m),build(b,m+1,r),s[k]=mg(s[a],s[b]);
}
void psd(int k,int a,int b){
	if(s[k].t)s[a].w^=s[k].t,s[b].w^=s[k].t,s[a].t^=s[k].t,s[b].t^=s[k].t,s[k].t=0;
}
void upd(int k,int l,int r){
	if(u<=l&&r<=v)return s[k].w^=w,s[k].t^=w,void();
	int m=l+r>>1,a=k<<1,b=a|1;
	psd(k,a,b);
	if(u<=m)upd(a,l,m);
	if(m<v)upd(b,m+1,r);
	s[k]=mg(s[a],s[b]);
}
void qry(int k,int l,int r){
	if(u<=l&&r<=v)return x=mg(x,s[k]),void();
	int m=l+r>>1,a=k<<1,b=a|1;
	psd(k,a,b);
	if(u<=m)qry(a,l,m);
	if(m<v)qry(b,m+1,r);
}
int main(){
	int n,q,i,t;
	scanf("%d%d",&n,&q);
	build(1,1,n);
	while(q--){
		scanf("%d%d%d",&i,&u,&v);
		if(i==1)scanf("%d",&w),upd(1,1,n);
		else{
			x=s[0],qry(1,1,n),t=0;
			for(i=30;~i;--i)if(x.a[i])++t;
			printf("%d\n",1<<t);
		}
	}
	return 0;
}