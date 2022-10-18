#include <cstdio>
#include <algorithm>
#include <cstdlib>

#define int long long

const int N=2e5;
long long a[N+10],n,k;

int check(int x) {
    int len=(1+n)/2,f=0;
    for(int i=len;i<=n;i++) {
        if(a[i]<x)f+=(x-a[i]);
        else break;
    }
    return f<=k;
}

signed main() {
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(n==1)return !printf("%lld\n",a[n]+k);
    std::sort(a+1,a+1+n);
    int l=a[1],r=a[n]+k,ans=0;
    while(l<=r) {
        int mid=(l+r)/2+rand()%5;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}