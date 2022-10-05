#include<bits/stdc++.h>
using namespace std;
struct M{
	int s,m,l,r,lm,rm,lp,rp;
	void in(int x,int p){s=m=lm=rm=x,l=r=lp=rp=p;}
};
void up(M&k,const M&a,const M&b){
	k.s=a.s+b.s;
	if(a.lm>a.s+b.lm)k.lm=a.lm,k.lp=a.lp;else k.lm=a.s+b.lm,k.lp=b.lp;
	if(b.rm>b.s+a.rm)k.rm=b.rm,k.rp=b.rp;else k.rm=b.s+a.rm,k.rp=a.rp;
	if(a.m>b.m)k.m=a.m,k.l=a.l,k.r=a.r;else k.m=b.m,k.l=b.l,k.r=b.r;
	if(a.rm+b.lm>k.m)k.m=a.rm+b.lm,k.l=a.rp,k.r=b.lp;
}
struct T{
	M a,b;
	bool t;
	void rev(){swap(a,b),t^=1;}
}s[262149];
int n,a[100009],u,v,ll[23],rr[23];
void up(T&k,T&a,T&b){up(k.a,a.a,b.a),up(k.b,a.b,b.b);}
void dn(T&k,T&a,T&b){if(k.t)a.rev(),b.rev(),k.t=0;}
void bd(int k,int l,int r){
	if(l==r){s[k].a.in(a[l],l),s[k].b.in(-a[l],l);return;}
	int m=(l+r)>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r),up(s[k],s[k*2],s[k*2+1]);
}
void upd(int k,int l,int r){
	if(l==r){s[k].a.in(v,l),s[k].b.in(-v,l);return;}
	int m=(l+r)>>1;
	dn(s[k],s[k*2],s[k*2+1]),u>m?upd(k*2+1,m+1,r):upd(k*2,l,m),up(s[k],s[k*2],s[k*2+1]);
}
M qry(int k,int l,int r){
	if(u<=l&&r<=v)return s[k].a;
	int m=(l+r)>>1;
	if(dn(s[k],s[k*2],s[k*2+1]),u<=m&&m<v){M w;up(w,qry(k*2,l,m),qry(k*2+1,m+1,r));return w;}
	return m<v?qry(k*2+1,m+1,r):qry(k*2,l,m);
}
void mdf(int k,int l,int r){
	if(u<=l&&r<=v)return s[k].rev();
	int m=(l+r)>>1;
	if(dn(s[k],s[k*2],s[k*2+1]),u<=m)mdf(k*2,l,m);
	if(m<v)mdf(k*2+1,m+1,r);
	up(s[k],s[k*2],s[k*2+1]);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int q,i,l,r,k,w;
	for(cin>>n,i=1;i<=n;++i)cin>>a[i];
	for(bd(1,1,n),cin>>q;q--;)if(cin>>i>>l>>r,i){
		cin>>k,w=0;
		for(i=1;i<=k;++i){
			u=l,v=r;
			auto o=qry(1,1,n);
			if(o.m<=0)break;
			w+=o.m,ll[i]=u=o.l,rr[i]=v=o.r,mdf(1,1,n);
		}
		for(cout<<w<<'\n';--i;)u=ll[i],v=rr[i],mdf(1,1,n);
	}else u=l,v=r,upd(1,1,n);
}