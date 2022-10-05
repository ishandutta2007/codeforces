#include<bits/stdc++.h>
using namespace std;
#define I int k=1,int l=1,int r=99999
#define _ s[k],s[k*2],s[k*2+1]
#define M int m=(l+r)>>1;
#define L k*2,l,m
#define R k*2+1,m+1,r
using ll=long long;
struct O{int a,a2,c;};
struct T{
	ll s;
	O o[2];
	T(){o[0].a=o[1].a=2e9;}
}s[262149];
int u,v,w;
bool b;
auto dn=[](T&k,T&a,T&b){
	if(k.o[0].a<a.o[0].a)a.s+=(k.o[0].a-a.o[0].a)*1ll*a.o[0].c,a.o[0].a=k.o[0].a;
	if(k.o[0].a<b.o[0].a)b.s+=(k.o[0].a-b.o[0].a)*1ll*b.o[0].c,b.o[0].a=k.o[0].a;
	if(k.o[1].a<a.o[1].a)a.s+=(k.o[1].a-a.o[1].a)*1ll*a.o[1].c,a.o[1].a=k.o[1].a;
	if(k.o[1].a<b.o[1].a)b.s+=(k.o[1].a-b.o[1].a)*1ll*b.o[1].c,b.o[1].a=k.o[1].a;
};
auto pu=[](O&k,O&a,O&b){
	if(a.a>b.a)k.a=a.a,k.a2=max(a.a2,b.a),k.c=a.c;
	else if(a.a<b.a)k.a=b.a,k.a2=max(a.a,b.a2),k.c=b.c;
	else k.a=a.a,k.a2=max(a.a2,b.a2),k.c=a.c+b.c;
};
auto up=[](T&k,T&a,T&b){k.s=a.s+b.s,pu(k.o[0],a.o[0],b.o[0]),pu(k.o[1],a.o[1],b.o[1]);};
void upd(I){
	if(s[k].o[b].a<=w)return;
	if(u<=l&&r<=v&&s[k].o[b].a2<w){
		if(s[k].o[b].a<2e9){s[k].s+=(w-s[k].o[b].a)*1ll*s[k].o[b].c,s[k].o[b].a=w;return;}
		if(l==r){
			if(s[k].o[b].a=w,s[k].o[0].a<2e9&&s[k].o[1].a<2e9)
			s[k].s=s[k].o[0].a+s[k].o[1].a,s[k].o[0].c=s[k].o[1].c=1;
			return;
		}
	}
	M if(dn(_),u<=m)upd(L);if(m<v)upd(R);up(_);
}
ll qry(I){
	if(u<=l&&r<=v)return s[k].s;
	M return dn(_),u<=m?(m<v?qry(L)+qry(R):qry(L)):qry(R);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int q,i;
	for(cin>>q;q--;)if(cin>>i>>u>>v,--v,i==1){
		if(cin>>w,w<0)w=-w,b=1;else b=0;
		upd();
	}else cout<<qry()<<'\n';
}