#include <cstdio>

#define debug(...) fprintf(stderr,__VA_ARGS__);
#define Debug if(DEBUG)

template<class T>void fr(T &a) {
    T s=0;int w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<int>()

#define int long long

template<class T>T cswp(T &a,T &b) {T t=a; a=b,b=t;}

int DEBUG=1;

int gcd(int a,int b) {return b?gcd(b,a%b):a;}

signed main() {
    // freopen("color.in","r",stdin);
    // freopen("color.out","w",stdout);
	int T=R();
	while(T--) {
        int p1=R(),p2=R(),k=R();
        if(p1>p2) cswp(p1,p2);
        puts((p2-gcd(p1,p2)-1)/p1+1<k?"OBEY":"REBEL");
    }
	return 0;
}