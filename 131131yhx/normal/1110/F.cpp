#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long

#define M 1000010

using namespace std;

typedef long long ll;

int n, q, Head[M], Next[M], Go[M], Fa[M], Mx[M], Len[M], Ans[M], Cnt = 0;

vector <int> Son[M];

struct node {
    int l, r, id;
    node() {}
    node(int _1, int _2, int _3) {l = _1, r = _2, id = _3;}
};

vector <node> QL[M], QR[M];

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

int Tg[M * 8], Mn[M * 8];

void pd(int x) {
    if(Tg[x]) {
        Mn[x * 2] += Tg[x];//min((ll) 1e18, Mn[x * 2] + Tg[x]);
        Mn[x * 2 + 1] += Tg[x]; //min((ll) 1e18, Mn[x * 2 + 1] + Tg[x]);
        Tg[x * 2] += Tg[x];//min((ll) 1e18, Tg[x * 2] + Tg[x]);
        Tg[x * 2 + 1] += Tg[x];//min((ll) 1e18, Tg[x * 2 + 1] + Tg[x]);
        Tg[x] = 0;
    }
}

void add(int x, int L, int R, int l, int r, int v) {
    //for(int i = l; i <= r; i++) Mn[i] += v;
    int md = (L + R) / 2;
    if(L == l && R == r) {
        Tg[x] += v;//min(Tg[x] + v, (ll) 1e18);
        Mn[x] += v;//min(Mn[x] + v, (ll) 1e18);;
        return;
    }
    pd(x);
    if(l <= md) add(x * 2, L, md, l, min(md, r), v);
    if(r > md) add(x * 2 + 1, md + 1, R, max(md + 1, l), r, v);
    Mn[x] = min(Mn[x * 2], Mn[x * 2 + 1]); //!!!
}

int ask(int x, int L, int R, int l, int r) {
    /*int ans = 1e18;
     for(int i = l; i <= r; i++) ans = min(ans, Mn[i]);
     return ans;*/
    int md = (L + R) / 2;
    if(L == l && R == r) return Mn[x];
    pd(x);
    ll ans = 1e18; //!!!
    if(l <= md) ans = min(ans, ask(x * 2, L, md, l, min(md, r)));
    if(r > md) ans = min(ans, ask(x * 2 + 1, md + 1, R, max(md + 1, l), r));
    return ans;
}

int tm = 0;

void DFS1(int x) {
    tm++;
    int i = x;
    if(Son[x].size()) add(1, 1, n, i, i, 1e18); else add(1, 1, n, i, i, -Len[i]);
    for(int j = 0; j < QL[i].size(); j++) {
        node tmp = QL[i][j];
        int x = tmp.id, l = tmp.l, r = tmp.r;
        Ans[x] = min(Ans[x], ask(1, 1, n, l, r) + Len[i]);
    }
    for(int j = 0; j < Son[x].size(); j++) DFS1(Son[x][j]);
    Mx[x] = tm;
    add(1, 1, n, x, tm, 2 * (Len[i] - Len[Fa[i]]));
}

signed main() {
    scanf("%lld%lld", &n, &q);
    memset(Ans, 63, sizeof Ans);
    for(int i = 2; i <= n; i++) {
        int p, w;
        scanf("%lld%lld", &p, &w);
        //addedge(p, i);
        Son[p].push_back(i);
        Fa[i] = p;
        Len[i] = Len[p] + w;
    }
    for(int i = 1; i <= n; i++) sort(Son[i].begin(), Son[i].end());
    
    for(int i = 1; i <= q; i++) {
        int x, l, r;
        scanf("%lld%lld%lld", &x, &l, &r);
        if(l <= x) QL[x].push_back(node(l, min(r, x), i));
        if(r >= x) QR[x].push_back(node(max(l, x), r, i));
    }
    DFS1(1);
    // clear : memset
    memset(Tg, 0, sizeof Tg);
    memset(Mn, 0, sizeof Mn);
    for(int i = n; i >= 1; i--) {
        if(Son[i].size()) add(1, 1, n, i, i, 1e18); else add(1, 1, n, i, i, -Len[i]);
        for(int j = 0; j < QR[i].size(); j++) {
            node tmp = QR[i][j];
            int x = tmp.id, l = tmp.l, r = tmp.r;
            Ans[x] = min(Ans[x], ask(1, 1, n, l, r) + Len[i]);
        }
        add(1, 1, n, i, Mx[i], 2 * (Len[i] - Len[Fa[i]]));
    }
    for(int i = 1; i <= q; i++) printf("%lld\n", Ans[i]);
    return 0;
}