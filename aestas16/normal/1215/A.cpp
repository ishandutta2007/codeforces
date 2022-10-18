#include <cstdio>
 
#define reg register
#define inline __inline__ __attribute__((always_inline))
 
namespace FastIO {
    #define Fread fread(B,1,1<<20,stdin)
    char B[1<<20],*S=B,*T=B,D[1<<25],*A=D-1;
    // inline char getc() {
        // return (S==T&&(T=(S=B)+Fread,S==T)?0:*S++);
    // }
    // #ifndef ONLINE_JUDGE
    #define getc getchar
    // #endif
    template<class T>inline void fr(reg T &a) {
        reg T s=0,w=1;reg char c=getc();
        while(c<'0'||c>'9') {if(c=='-')w=-1;c=getc();}
        while(c>='0'&&c<='9') s=s*10+c-'0',c=getc();
        a=w*s;
    }
    template<class T>inline T fr() {T a;fr(a);return a;}
    #define R() fr<int>()
    inline void putc(reg char x) {*++A=x;}
    template<class T>inline void fw(reg T x) {
        static char C[20];static int F;
        if(x<0)putc('-'),x=-x;
        while(C[++F]=48+x%10,x/=10);
        while(*++A=C[F],--F);
        *++A=' ';
    }
    inline int flush() {fwrite(D,1,A-D,stdout);return 0;}
};
using namespace FastIO;
 
int main() {
    int a1=R(),a2=R(),k1=R(),k2=R(),n=R(),ans1=0,ans2=0;
    if(k1<k2) {
        int f=n/k1,n1=n;
        if(f>a1) {
            ans2+=a1;
            n-=a1*k1;
            ans2+=n/k2;
        } else ans2+=f;
        if(n1<=(k1-1)*a1+(k2-1)*a2)ans1=0;
        else {
            n1-=(k1-1)*a1+(k2-1)*a2;
            ans1+=n1;
        }
    }
    else {
        int f=n/k2,n1=n;
        if(f>=a2) {
            ans2+=a2;
            n-=a2*k2;
            ans2+=n/k1;
        } else ans2+=f;
        if(n1<=(k1-1)*a1+(k2-1)*a2)ans1=0;
        else {
            n1-=(k1-1)*a1+(k2-1)*a2;
            ans1+=n1;
        }
    }
    return fw(ans1),fw(ans2),flush();
}