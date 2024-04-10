
#include <cstdio>
#include <algorithm>
 
#define ll long long
 
template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<ll>()
 
ll a[100010];
 
int main() {
    ll n=R(),f=n/2,s1=0,s2=0,s3=0,s4=0;
    for(ll i=1;i<=n;i++) fr(a[i]);
    std::sort(a+1,a+1+n);
    for(ll i=1;i<=f;i++) s1+=a[i];
    for(ll i=f+1;i<=n;i++) s2+=a[i];
    if(2*f!=n) {
        f++;
        for(ll i=1;i<=f;i++) s3+=a[i];
        for(ll i=f+1;i<=n;i++) s4+=a[i];
    }
    printf("%lld\n",std::max(s1*s1+s2*s2,s3*s3+s4*s4));
    return 0;
}