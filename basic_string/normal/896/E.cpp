#include<bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef int big __attribute((vector_size(16)));
big a[29999];
char _[999999],*U,*V;
#define I (U==V&&(V=(U=_)+fread(_,1,999991,stdin),U==V)?0:*U++)
template<class T>bool in(T&x){char c=I;bool f=0;for(x=0;c<48||c>57;c=I)if(c==45)f=1;else if(!c)return 0;for(;c>47&&c<58;c=I)x=x*10+c-48;if(f)x=-x;return 1;}
char O_[999999],*OU=O_,*OV=OU+999991,OS[21],*OT=OS;
#define F fwrite(O_,1,OU-O_,stdout)
#define O(x) (*(OU=(OU==OV?(F,O_):OU))++=(x))
template<class T>void out(T x){if(x<0)O(45),x=-x;for(;*OT++=x%10+48,x/=10;);for(;OT!=OS;O(*--OT));O(10);}
int main(){
	int n,m,i,j,l,r,x,o;
	in(n),in(m);
	for(i=1;i<=n;++i)in(a[i>>2][i&3]);
	for(;m--;)if(in(i),in(l),in(r),in(x),i==1){
		if(r-l<4){
			for(i=l;i<=r;++i)a[i>>2][i&3]-=((a[i>>2][i&3]>x)*x);
		}else{
			for(i=l/4+1,j=r/4;i!=j;++i)a[i]-=((a[i]>x)&x);
			for(i=(l&3);i<4;++i)a[l>>2][i]-=((a[l>>2][i]>x)*x);
			for(i=0;i<=(r&3);++i)a[r>>2][i]-=((a[r>>2][i]>x)*x);
		}
	}else{
		big w{};
		if(o=0,r-l<4){
			for(i=l;i<=r;++i)o+=(a[i>>2][i&3]==x);
		}else{
			for(i=l/4+1,j=r/4;i!=j;++i)w+=(a[i]==x);
			for(i=(l&3);i<4;++i)o+=(a[l>>2][i]==x);
			for(i=0;i<=(r&3);++i)o+=(a[r>>2][i]==x);
			for(i=0;i<4;++i)o-=w[i];
		}
		out(o);
	}F;
}