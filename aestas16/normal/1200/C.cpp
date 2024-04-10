// luogu-judger-enable-o2
#include <cstdio>
 
#define ll long long
 
template<class T>void fr(T &a) {
    T s=0,w=1;a=0;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T in() {T a;fr(a);return a;}
 
ll gcd(ll a,ll b) {return a%b?gcd(b,a%b):b;}
 
int main() {
	ll n=in<ll>(),m=in<ll>(),q=in<ll>(),blon,blom,GCD;
	GCD=gcd(n,m);blon=n/GCD,blom=m/GCD;
	while(q--) {
		ll sx=in<ll>(),sy=in<ll>(),ex=in<ll>(),ey=in<ll>();
		sy--,ey--;
		if(sx==1)sy/=blon;
		else sy/=blom;
		if(ex==1)ey/=blon;
		else ey/=blom;
		puts(sy==ey?"YES":"NO");
	}
	return 0;
}