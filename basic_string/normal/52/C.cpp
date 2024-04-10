#include<bits/stdc++.h>
using namespace std;
char _[999999],*U,*V;
#define I (U==V?(V=(U=_)+fread(_,1,999991,stdin),*U++):*U++)
auto in=[](auto&x){bool f=0;char c=I;for(x=0;c<48||c>57;c=I)if(c==45)f=1;for(;c>47&&c<58;c=I)x=x*10+c-48;if(f)x=-x;return c;};
char O_[999999],*OU=O_,*OV=OU+999991,OS[21],*OT=OS;
#define F fwrite(O_,1,OU-O_,stdout)
#define O(x) (*(OU=(OU==OV?(F,O_):OU))++=(x))
auto out=[](auto x){if(x<0)O(45),x=-x;for(;*OT++=x%10+48,x/=10;);for(;OT!=OS;O(*--OT));O(10);};
using ll=long long;
ll t[524289];
int m;
void upd(int x,int y,int k){
	ll i;
	for(x+=m-1,y+=m+1;x^y^1;x>>=1,y>>=1){
		if(~x&1)t[x^1]+=k;
		if(y&1)t[y^1]+=k;
		i=min(t[x],t[x^1]),t[x]-=i,t[x^1]-=i,t[x>>1]+=i;
		i=min(t[y],t[y^1]),t[y]-=i,t[y^1]-=i,t[y>>1]+=i;
	}
	for(;x^1;x>>=1)i=min(t[x],t[x^1]),t[x]-=i,t[x^1]-=i,t[x>>1]+=i;
}
ll qry(int x,int y){
	ll u=1e16,v=u;
	for(x+=m-1,y+=m+1;u+=t[x],v+=t[y],x^y^1;x>>=1,y>>=1){
		if(~x&1)u=min(u,t[x^1]);
		if(y&1)v=min(v,t[y^1]);
	}
	for(u=min(u,v);x>>=1;)u+=t[x];
	return u;
}
int main(){
	int n,q,i,j,k;
	for(in(n),m=(2<<__lg(n+1))+1,i=0;i<n;++i)in(t[m+i]);
	for(i=m-1;i;--i)t[i]=j=min(t[i*2],t[i*2+1]),t[i*2]-=j,t[i*2+1]-=j;
	for(in(q);q--;)if(in(i),in(j)==10)out(i>j?min(qry(i,n-1),qry(0,j)):qry(i,j));
	else in(k),i>j?(upd(i,n-1,k),upd(0,j,k)):upd(i,j,k);
	return F,0;
}