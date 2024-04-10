#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const lli INF=1e18;

lli add(lli a,lli b) {
    if(a+b>=INF) return INF;
    else if(a+b<=-INF) return -INF;
    else return a+b;
}
lli mul(lli a,lli b) {
    if(a==0 || b==0) return 0;
    if( (a>0 && b>0) || (a<0 || b<0)) {
        if(abs(a)>=INF || abs(b)>=INF || INF/abs(a)<=abs(b)) return INF;
        else return a*b;
    } else {
        if(abs(a)>=INF || abs(b)>=INF || INF/abs(a)<=abs(b)) return -INF;
        else return a*b;
    }
}

int n,k;
lli a[200011],b[200011],ss[200011];
int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<=n;i++) scanf("%lld",a+i);
    for(int i=n;i>=0;i--) ss[i] = add(mul(ss[i+1],2),a[i]);
    

    int ans=0;
    for(int i=0;i<=n;i++) {
        if(abs(add(b[i],mul(ss[i+1],2)))<=k) {
            if(i!=n || b[i]!=0) ans++;
        }
        if(add(b[i],a[i])&1) break;
        b[i+1] = add(b[i],a[i])/2;
    }
    printf("%d\n",ans);

    return 0;
}