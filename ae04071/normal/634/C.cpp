#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,k,a,b,m;
struct seg_tr{
    lli tr[200001];
    int val[200001],b;
    void upd(int cur,int v) {
        v = min(v,b-val[cur]);
        val[cur]+=v;
        while(cur<=n) tr[cur]+=v,cur+=cur&-cur;
    }
    lli sum(int cur) {
        lli ret=0;
        while(cur) ret+=tr[cur],cur-=cur&-cur;
        return ret;
    }
    lli get(int l,int r) {
        return sum(r)-sum(l-1);
    }
}sa,sb;

int main() {
    scanf("%d%d%d%d%d",&n,&k,&a,&b,&m);
    sa.b=a;
    sb.b=b;
    while(m--) {
        int t,d,v;
        scanf("%d",&t);
        if(t==1) {
            scanf("%d%d",&d,&v);
            sa.upd(d,v);
            sb.upd(d,v);
        } else {
            scanf("%d",&v);
            printf("%lld\n",sb.get(1,v-1) + sa.get(v+k,n));
        }
    }
    return 0;
}