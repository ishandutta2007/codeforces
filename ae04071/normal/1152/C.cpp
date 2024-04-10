#include <bits/stdc++.h>
using namespace std;
using lli=long long;

lli a,b;
lli __lcm(lli a,lli b) {return a/__gcd(a,b)*b;}
int main() {
    scanf("%lld%lld",&a,&b);
    if(a==b) {
        puts("0");
        return 0;
    }
    
    if(b<a) swap(a,b);
    lli dif=b-a,mx=1000000000000000001ll,k=0;
    for(lli i=1;i*i<=dif;i++) if(dif%i==0) {
        lli ad = a%i;
        if(ad!=0) ad=i-ad;

        lli v=__lcm(a+ad,b+ad);
        if(v < mx) {
            mx=v; k=ad;
        }

        ad = a%(dif/i);
        if(ad!=0) ad=(dif/i)-ad;
        v=__lcm(a+ad,b+ad);
        if(v < mx) {
            mx=v; k=ad;
        }
    }
    printf("%lld\n",k);
    
    return 0;
}