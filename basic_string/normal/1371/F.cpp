#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
char c[N];
int u,v,n,q;
struct P{int o,l,r,s,ls,rs;};
struct T{P u,v;bool t;}s[N*4];
P mg(const P&a,const P&b){return{a.o+b.o,a.l<a.o?a.l:a.l+b.l,b.r<b.o?b.r:b.r+a.r,max(a.s,max(b.s,max(a.r+b.ls,a.rs+b.l))),a.r==a.o?a.r+b.ls:(a.s==a.o?a.s+b.l:a.ls),b.l==b.o?b.l+a.rs:(b.s==b.o?b.s+a.r:b.rs)};}
T mg(const T&a,const T&b){return{mg(a.u,b.u),mg(a.v,b.v)};}
void bd(int k,int l,int r){
	if(l==r){
		s[k].u.r=s[k].v.l=c[l]=='>',s[k].u.l=s[k].v.r=c[l]=='<';
		s[k].u.ls=s[k].u.rs=s[k].u.s=s[k].v.ls=s[k].v.rs=s[k].v.s=s[k].u.o=s[k].v.o=1;
		return;
	}
	int m=l+r>>1;
	bd(k*2,l,m),bd(k*2+1,m+1,r),s[k]=mg(s[k*2],s[k*2+1]);
}
void rev(T&x){swap(x.u,x.v),x.t^=1;}
P qry(int k,int l,int r){
	if(u<=l&&r<=v)return rev(s[k]),s[k].u;
	int m=l+r>>1;
	if(s[k].t)s[k].t=0,rev(s[k*2]),rev(s[k*2+1]);
	P o=u<=m?(m<v?mg(qry(k*2,l,m),qry(k*2+1,m+1,r)):qry(k*2,l,m)):qry(k*2+1,m+1,r);
	return s[k]=mg(s[k*2],s[k*2+1]),o;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q>>(c+1),bd(1,1,n);
	while(q--)cin>>u>>v,cout<<qry(1,1,n).s<<'\n';
	return 0;
}