#include <bits/stdc++.h>
using namespace std;

int n,pa[200001],l[200001],r[200001];
int ll[200001],rr[200001];
int f(int cur){return cur==pa[cur] ? cur : pa[cur]=f(pa[cur]);}
void merge(int u,int v) {
    u=f(u); v=f(v);
    r[rr[u]] = ll[v];
    l[ll[v]] = rr[u];
    pa[v]=u;
    rr[u]=rr[v];
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) pa[i]=ll[i]=rr[i]=i;
    for(int i=1,x,y;i<n;i++) {
        scanf("%d%d",&x,&y);
        merge(x,y);
    }
    int cur=0;
    for(int i=1;i<=n;i++) if(!l[i]) {
        cur=i;
        break;
    }
    for(int i=0;i<n;i++) {
        printf("%d ",cur); cur = r[cur];
    }
    return 0;
}