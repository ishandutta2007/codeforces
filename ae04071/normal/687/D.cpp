#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,w,i;
    bool operator<(const edge &rhs)const {
        return w<rhs.w;
    }
}arr[500100];
int n,m,q;
vector<edge> adj[1001];

int pa[1001],lz[1001],c[1001];

int find(int cur) {
    int p=pa[cur];
    while(p!=pa[p]) {
        c[cur] ^= lz[p];
        lz[cur] ^= lz[p];
        p = pa[p];
    }
    pa[cur] = p;
    return p;
}
bool merge(int u,int v) {
    int pu = find(u), pv = find(v);
    if(pu==pv) {
        return c[u]!=c[v];
    } else {
        if(c[u] == c[v]) {
            lz[pv] ^= 1, c[pv] ^= 1;
        } 
        pa[pv] = pu;
        return true;
    }
}

int l,r,mw;
int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<m;i++) {
        scanf("%d%d%d",&arr[i].u,&arr[i].v,&arr[i].w),arr[i].i = i+1;
    }
    sort(arr,arr+m);

    while(q--) {
        int l,r;
        scanf("%d%d",&l,&r);
        
        for(int i=1;i<=n;i++) pa[i] = i, c[i] = 0, lz[i] = 0;
        int j=m-1;
        for(;j>=0;j--) if(arr[j].i>=l && arr[j].i<=r){
            if(!merge(arr[j].u,arr[j].v)) break;
        }
        if(j==-1) puts("-1");
        else printf("%d\n",arr[j].w);
    }
    
    return 0;
}