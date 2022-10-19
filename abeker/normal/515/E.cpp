#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const int offset = 1 << 18;

int N, M;
ll d[MAXN], h[MAXN];

struct node {
    ll maks, pref, suff, sum;
    node() : maks(0), pref(0), suff(0), sum(0) {}
    node(ll maks, ll pref, ll suff, ll sum) :
        maks(maks), pref(pref), suff(suff), sum(sum) {}
};

struct tournament {
    node t[2 * offset];
    
    node merge(node l, node r) {
        node res;
        res.maks = max(l.suff + r.pref, max(l.maks, r.maks));
        res.pref = max(l.pref, l.sum + r.pref);
        res.suff = max(r.suff, r.sum + l.suff);
        res.sum = l.sum + r.sum;
        return res;
    }
    
    void init() {
        for (int i = 0; i < offset; i++)        
            t[i + offset] = node(d[i % N] + 2 * (h[i % N] + h[(i + 1) % N]),    
                                 d[i % N] + 2 * h[(i + 1) % N],
                                 d[i % N] + 2 * h[i % N],
                                 d[i % N]);
        for (int i = offset - 1; i >= 0; i--)
            t[i] = merge(t[2 * i], t[2 * i + 1]);
    }
    
    node query(int x, int lo, int hi, int from, int to) {
        if (lo >= to || hi <= from) return node();
        if (lo >= from && hi <= to) return t[x];
        int mid = (lo + hi) / 2;
        return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
    }
} T;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) 
        scanf("%I64d", d + i);
    for (int i = 0; i < N; i++)
        scanf("%I64d", h + i);
}

void solve() {
    T.init();
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b); a--; b--;
        printf("%I64d\n", T.query(1, 0, offset, b + 1, a - 1 + (a <= b) * N).maks);
    }
}

int main() {
    load();
    solve();
    return 0;
}