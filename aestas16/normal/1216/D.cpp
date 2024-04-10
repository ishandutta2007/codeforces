#include <cstdio>

#define max(a,b) ((a)>(b)?(a):(b))

template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<long long>()

long long gcd(long long a,long long b) {
    if(!b)return a;
    return gcd(b,a%b);
}

long long a[200010];

int main() {
    long long n=R(),maxn=0,ans1=0,ans2,f=0;
    for(int i=1;i<=n;i++) fr(a[i]),maxn=max(a[i],maxn);
    for(int i=1;i<=n;i++) {
        if(maxn-a[i]&&!f)ans2=maxn-a[i],f=1;
        else if(maxn-a[i])ans2=gcd(ans2,maxn-a[i]);
    }
    for(int i=1;i<=n;i++) ans1+=(maxn-a[i]);
    return !printf("%lld %lld\n",ans1/ans2,ans2);
}