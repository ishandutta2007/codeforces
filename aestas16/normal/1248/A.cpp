#include <cstdio>
 
#define ll long long
 
template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<ll>()
 
int main() {
    ll t=R();
    while(t--) {
        ll n=R(),m,ne=0,no=0,me=0,mo=0;
        for(ll i=1;i<=n;i++) {
            ll x=R();
            if(x%2)ne++;
            else no++;
        }
        fr(m);
        for(ll i=1;i<=m;i++) {
            ll x=R();
            if(x%2)me++;
            else mo++;
        }
        printf("%lld\n",ne*me+no*mo);
    }
    return 0;
}