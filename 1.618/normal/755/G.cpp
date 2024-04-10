#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 65540
#define ll long long
#define reg register
#define p 998244353
using namespace std;

struct Z{
    int v;
    inline Z(const int _v=0):v(_v){}
};

inline Z operator + (const Z& lhs,const Z& rhs){ return lhs.v+rhs.v<p ? lhs.v+rhs.v : lhs.v+rhs.v-p; }
inline Z operator - (const Z& lhs,const Z& rhs){ return lhs.v<rhs.v ? lhs.v-rhs.v+p : lhs.v-rhs.v; }
inline Z operator - (const Z& x){ return x.v?p-x:0; }
inline Z operator * (const Z& lhs,const Z& rhs){ return (ll)lhs.v*rhs.v%p; }
inline Z& operator += (Z& lhs,const Z& rhs){ lhs.v = lhs.v+rhs.v<p ? lhs.v+rhs.v : lhs.v+rhs.v-p; return lhs; }
inline Z& operator -= (Z& lhs,const Z& rhs){ lhs.v = lhs.v<rhs.v ? lhs.v-rhs.v+p : lhs.v-rhs.v; return lhs; }
inline Z& operator *= (Z& lhs,const Z& rhs){ lhs.v = (ll)lhs.v*rhs.v%p; return lhs; }

inline Z power(Z a,int t){
    Z res = 1;
    while(t){
        if(t&1) res *= a;
        a *= a;
        t >>= 1;
    }
    return res;
}

Z rt[N],inv[N];
int rev[N];
int siz;

inline int getlen(int n){ return 1<<(32-__builtin_clz(n)); }

void init(int n){
    int lim = 1;
    while(lim<=n) lim <<= 1,++siz;
    for(reg int i=1;i!=lim;++i) rev[i] = (rev[i>>1]>>1)|((i&1)<<(siz-1));
    Z w = power(3,(p-1)>>siz);
    rt[lim>>1] = inv[1] = 1;
    for(reg int i=lim>>1|1;i!=lim;++i) rt[i] = rt[i-1]*w;
    for(reg int i=(lim>>1)-1;i;--i) rt[i] = rt[i<<1];
    for(reg int i=2;i<=n;++i) inv[i] = (p-p/i)*inv[p%i];
}

inline void dft(Z *f,int lim){
    static unsigned long long a[N];
    reg int x,shift = siz-__builtin_ctz(lim);
    for(reg int i=0;i!=lim;++i) a[rev[i]>>shift] = f[i].v;
    for(reg int mid=1;mid!=lim;mid<<=1)
    for(reg int j=0;j!=lim;j+=(mid<<1))
    for(reg int k=0;k!=mid;++k){
        x = a[j|k|mid]*rt[mid|k].v%p;
        a[j|k|mid] = a[j|k]+p-x;
        a[j|k] += x;
    }
    for(reg int i=0;i!=lim;++i) f[i] = a[i]%p;
}

inline void idft(Z *f,int lim){
    reverse(f+1,f+lim);
    dft(f,lim);
    reg int x = p-((p-1)>>__builtin_ctz(lim));
    for(reg int i=0;i!=lim;++i) f[i] *= x;
}

inline void inverse(const Z *f,int n,Z *R){
    static Z g[N],h[N];
    int st[30],lim = getlen(n<<1),top = 0;
    for(reg int i=0;i!=lim;++i) g[i] = 0;
    while(n){
        st[++top] = n;
        n >>= 1;
    }
    g[0] = power(f[0],p-2),lim = 1;
    while(top--){
        n = st[top+1];
        while(lim<=(n<<1)) lim <<= 1;
        for(reg int i=0;i<=n;++i) h[i] = f[i];
        for(reg int i=n+1;i!=lim;++i) h[i] = 0;
        dft(g,lim),dft(h,lim);
        for(reg int i=0;i!=lim;++i) g[i] *= 2-g[i]*h[i];
        idft(g,lim);
        for(reg int i=n+1;i!=lim;++i) g[i] = 0;
    }
    for(reg int i=0;i<=n;++i) R[i] = g[i];
}

inline void log(Z *f,int n){
    static Z g[N];
    int lim = getlen(n<<1);
    inverse(f,n,g);
    for(reg int i=0;i<=n;++i) f[i] = f[i+1]*(i+1);
    for(reg int i=n+1;i!=lim;++i) g[i] = 0;
    dft(f,lim),dft(g,lim);
    for(reg int i=0;i!=lim;++i) f[i] *= g[i];
    idft(f,lim);
    for(reg int i=n;i;--i) f[i] = f[i-1]*inv[i];
    for(reg int i=n+1;i!=lim;++i) f[i] = 0;
    f[0] = 0;
}

void exp(const Z *f,int n,Z *R){
    static Z g[N],h[N];
    int st[30],lim = getlen(n<<1),top = 0;
    for(reg int i=0;i!=lim;++i) g[i] = 0;
    while(n){
        st[++top] = n;
        n >>= 1;
    }
    g[0] = lim = 1;
    while(top--){
        n = st[top+1];
        while(lim<=(n<<1)) lim <<= 1;
        for(reg int i=0;i<=n;++i) h[i] = g[i];
        log(g,n);
        for(reg int i=0;i<=n;++i) g[i] = f[i]-g[i];
        g[0] += 1;
        for(reg int i=n+1;i!=lim;++i) h[i] = 0;
        dft(g,lim),dft(h,lim);
        for(reg int i=0;i!=lim;++i) g[i] *= h[i];
        idft(g,lim);
        for(reg int i=n+1;i!=lim;++i) g[i] = 0;
    }
    for(reg int i=0;i<=n;++i) R[i] = g[i];
}

void power(const Z *f,int n,int k,Z *R){
    static Z g[N];
    for(reg int i=0;i<=n;++i) g[i] = f[i];
    log(g,n);
    for(reg int i=1;i<=n;++i) g[i] *= k;
    exp(g,n,R);
}

inline void getpow(const Z *f,int n,int k,Z *g){
    g[0] = 1;
    for(reg int i=0;i!=n;++i){
        Z tmp = 0;
        for(reg int j=0;j<=min(i,1);++j) tmp += f[j+1]*g[i-j]*(j+1);
        tmp *= k;
        for(reg int j=max(0,i-2);j!=i;++j) tmp -= g[j+1]*f[i-j]*(j+1);
        g[i+1] = tmp*inv[i+1];
    }
}

int n,k,t;
Z a[N],z1[N],c[N];

int main(){
    scanf("%d%d",&n,&t);
    k = min(n,t);
    init(k<<1);
    a[0] = a[2] = 1,a[1] = 6;
    getpow(a,k,499122177,z1);
    getpow(a,k,499122176,c);
    z1[0] += 1,z1[1] += 1;
    for(reg int i=0;i<=k;++i) z1[i] *= 499122177;
    power(z1,k,n+1,z1);
    int lim = getlen(k<<1);
    dft(z1,lim),dft(c,lim);
    for(reg int i=0;i!=lim;++i) z1[i] *= c[i];
    idft(z1,lim);
    for(reg int i=1;i<=k;++i) printf("%d ",z1[i].v);
    for(reg int i=k+1;i<=t;++i) printf("0 ");
    return 0;   
}