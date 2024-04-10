#include <cstdio>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef pair <int, int> pii;

const int MAXN = 300005;
const int offset = 1 << 19;

struct node {
    ld pref, suff, prod;
    node(ld pref, ld suff, ld prod) : pref(pref), suff(suff), prod(prod) {}
    node() : pref(2), suff(2), prod(1) {}
};

int N;
pii p[MAXN];
node t[2 * offset];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
}

node merge(node L, node R) {
    return node(L.pref + L.prod * (R.pref - 1), R.suff + R.prod * (L.suff - 1), L.prod * R.prod);
}

void update(int x) {
    x += offset;
    t[x].prod = 0.5;
    t[x].pref = t[x].suff = 1.5;
    for (x /= 2; x; x /= 2)
        t[x] = merge(t[2 * x], t[2 * x + 1]);
}

node query(int x, int lo, int hi, int from, int to) {
    if (lo >= to || hi <= from) return node(1.0, 1.0, 1.0);
    if (lo >= from && hi <= to) return t[x];
    int mid = (lo + hi) / 2;
    return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

node query(int from, int to) {
    return query(1, 0, offset, from, to);
}

ld solve() {
    for (int i = offset - 1; i >= 0; i--)
        t[i] = merge(t[2 * i], t[2 * i + 1]);
        
    sort(p, p + N);
    ld sol = 0;
    for (int i = N - 1; i >= 0; i--) {
        sol += (ld)p[i].first * 0.5 * query(0, p[i].second).suff * query(p[i].second + 1, N).pref;
        update(p[i].second);
    }
    return sol / ((ld)N * N);
}

int main() {
    load();
    printf("%.15lf\n", (double)solve());
    return 0;
}