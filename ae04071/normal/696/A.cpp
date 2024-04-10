#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int getDepth(lli v) {
    int ret=0;
    while(v) ret++,v>>=1;
    return ret;
}
map<lli,lli> tr;
lli lca(lli u,lli v,lli w=0) {
    lli ret=0;
    if(getDepth(u) > getDepth(v)) swap(u,v);
    
    int dif = getDepth(v) - getDepth(u);
    for(int i=0;i<dif;i++) {
        if(!w) ret += tr[v];
        else tr[v] += w;
        v/=2;
    }
    while(u!=v) {
        if(!w) ret+=tr[u]+tr[v];
        else tr[u]+=w,tr[v]+=w;
        u>>=1;v>>=1;
    }
    return ret;
}

int main() {
    int n;
    scanf("%d",&n);
    while(n--) {
        int t;
        lli a,b,c;
        scanf("%d%lld%lld",&t,&a,&b);
        if(t==1) {
            scanf("%lld",&c);
            lca(a,b,c);
        } else {
            printf("%lld\n",lca(a,b));
        }
    }
    return 0;
}