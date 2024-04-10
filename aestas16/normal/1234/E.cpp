//Naive_Cat
#include <cstdio>

#define reg register
#define ll long long
#define inf 0x3f3f3f3f
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define swap(a,b) ((a)^=(b)^=(a)^=(b))
#define For(i,l,r) for(reg int i=(l);i<=(r);i++)
#define Forr(i,l,r) for(reg int i=(l);i>=(r);i--)
#define inline __inline__ __attribute__((always_inline))
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug(s) debug("In line %d,Function %s(): \
%s\n",__LINE__,__FUNCTION__,s)

namespace FastIO {
    char B[1<<21],*S=B,*T=B,D[1<<25],*A=D-1,F=0;
    template<class T>inline void fr(reg T &a) {
    #ifdef ONLINE_JUDGE
        !F?fread(B,1,1<<21,stdin),F=1:0;
        reg char *c=S,f=0;a=0;
        for(;*c<48;c++) *c=='-'?f=1:0;
        for(;*c>47;c++) a=10*a+(*c^48);
        S=++c;f?a=-a:0;
    #else
        reg char c=getchar(),f=0;a=0;
        for(;c<48;c=getchar()) c=='-'?f=1:0;
        for(;c>47;c=getchar()) a=10*a+(c^48);
        f?a=-a:0;
    #endif
    }
    template<class T>inline T fr() {T a;fr(a);return a;}
    #define R() fr<int>()
    inline void Putc(reg char c) {*++A=c;}
    template<class T>inline void fw(reg T x) {
        static char C[20];static int f;
        x<0?*++A='-',x=-x:0;
        while(C[++f]=48+x%10,x/=10);
        while(*++A=C[f],--f);
        *++A=' ';
    }
    inline int flush() {fwrite(D,1,A-D,stdout);return 0;}
}
using namespace FastIO;

#define N 200000

int x[N+10];
ll ans[N+10];

int main() {
    int n=R(),m=R();fr(x[1]);
    for(int i=2;i<=m;i++) {
        fr(x[i]);
        int a=x[i-1],b=x[i];
        if(a>b)swap(a,b);
        if(a==b)continue;
        ans[1]+=b-a,ans[a+1]-=a;
        ans[a]=ans[a]+a-1,ans[b]=ans[b]-b+a+a+1;
        ans[b+1]=ans[b+1]-a-a+b;
    }
    for(int i=1;i<=n;i++) ans[i]+=ans[i-1],fw(ans[i]);
    return flush();
}