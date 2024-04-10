#include<bits/stdc++.h>
using namespace std;
using ll=__int128;
char _[999999],*U,*V;
#define I (U==V&&(V=(U=_)+fread(_,1,999991,stdin),U==V)?0:*U++)
template<class T>bool in(T&x){char c=I;bool f=0;for(x=0;c<48||c>57;c=I)if(c==45)f=1;else if(!c)return 0;for(;c>47&&c<58;c=I)x=x*10+c-48;if(f)x=-x;return 1;}
char O_[999999],*OU=O_,*OV=OU+999991,OS[21],*OT=OS;
#define F fwrite(O_,1,OU-O_,stdout)
#define O(x) (*(OU=(OU==OV?(F,O_):OU))++=(x))
template<class T>void out(T x){if(x<0)O(45),x=-x;for(;*OT++=x%10+48,x/=10;);for(;OT!=OS;O(*--OT));O(32);}
enum{N=1009,M=2053};
ll a[N],b[N],w;
int u;
struct T{
	ll s[M];
	void bd(int k,int l,int r){
		if(l==r){s[k]=w/__gcd(w,u?a[l]:b[l]);return;}
		int m=l+r>>1;
		bd(k*2,l,m),bd(k*2+1,m+1,r),s[k]=__gcd(s[k*2],s[k*2+1]);
	}
	void upd(int k,int l,int r){
		if(l==r){s[k]=0;return;}
		int m=l+r>>1;
		if(u<=m)upd(k*2,l,m);else upd(k*2+1,m+1,r);
		s[k]=__gcd(s[k*2],s[k*2+1]);
	}
}p[N],q[N];
int main(){//ios::sync_with_stdio(0),cin.tie(0);
	int T,n,m,i,j;
	for(in(T);T--;){
		in(n),in(m);
		for(i=1;i<=n;++i)in(a[i]);
		for(i=1;i<=m;++i)in(b[i]);
		for(i=1,u=0;i<=n;++i)w=a[i],p[i].bd(1,1,m);
		for(i=u=1;i<=m;++i)w=b[i],q[i].bd(1,1,n);
		while(1){
			for(i=1;i<=n;++i)if(p[i].s[1]>1){
				p[u=i].s[1]=0;
				for(j=1;j<=m;++j)if(q[j].s[1])q[j].upd(1,1,n);
				goto gg;
			}
			for(i=1;i<=m;++i)if(q[i].s[1]>1){
				q[u=i].s[1]=0;
				for(j=1;j<=n;++j)if(p[j].s[1])p[j].upd(1,1,m);
				goto gg;
			}
			break;
			gg:;
		}
		j=0;
		for(i=1;i<=n;++i)if(p[i].s[1])j|=1;
		for(i=1;i<=m;++i)if(q[i].s[1])j|=2;
		if(j<3)O('N'),O('O'),O('\n');
		else{
			O('Y'),O('E'),O('S'),O('\n');
			for(i=1,j=0;i<=n;++i)if(p[i].s[1])++j;out(j);O('\n');
			for(i=1,j=0;i<=m;++i)if(q[i].s[1])++j;out(j);O('\n');
			for(i=1;i<=n;++i)if(p[i].s[1])out(a[i]);O('\n');
			for(i=1;i<=m;++i)if(q[i].s[1])out(b[i]);O('\n');
		}
	}F;
}