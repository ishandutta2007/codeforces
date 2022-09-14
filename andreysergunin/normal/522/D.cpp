#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <utility>

const int N = 500000;
const int M = 500000;
const int N2 = 1<<20;
const int INF = 2e9;

int segtree[N2]; int nn;
int tget(int l, int r) {
    l+=nn; r+=nn;
    int m = INF;
    for (; l<=r; l/=2, r/=2) {
        if (l%2==1) { m=std::min(m,segtree[l]); l++; }
        if (r%2==0) { m=std::min(m,segtree[r]); r--; }
    }
    return (m==INF)?-1:m;
}
void tset(int v, int x) {
    x+=nn; segtree[x]=v;
    for (x/=2; x>0; x/=2)
        segtree[x] = std::min(segtree[x*2],segtree[x*2+1]);
}

struct query {
    int l,r,i;
};
bool operator<(const query &a, const query &b) {
    return a.l<b.l;
}

std::unordered_map<int,int> beg;
int ends[N];
query queries[M];
int ans[M];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (nn=1; nn<n; nn*=2) ;
    for (int i=0; i<N2; i++) segtree[i] = INF;
    for (int i=0; i<n; i++) {
        int v; scanf("%d",&v);
        if (beg[v]!=0) {
            tset(i+1-beg[v],i);
            ends[beg[v]-1]=i+1;
        }
        beg[v] = i+1;
    }
    for (int i=0; i<m; i++) {
        scanf("%d%d",&(queries[i].l),&(queries[i].r));
        queries[i].l--; queries[i].r--; queries[i].i=i;
    }
    std::sort(queries,queries+m);
    int l = 0;
    for (int i=0; i<m; i++) {
        for (; l<queries[i].l; l++) if (ends[l]!=0) tset(INF,ends[l]-1);
        ans[queries[i].i] = tget(queries[i].l,queries[i].r);
    }
    for (int i=0; i<m; i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}