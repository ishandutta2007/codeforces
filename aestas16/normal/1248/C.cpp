#include <cstdio>

#define p 1000000007
#define N 100000
#define max(a,b) ((a)>(b)?(a):(b))

template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<int>()

int f[N+10]={2,2};

int main() {
    int n=R(),m=R();
    for(int i=1;i<=max(n,m);i++) f[i]=(f[i-1]+f[i-2])%p;
    return !printf("%d\n",(f[n]+f[m]-2)%p);
}