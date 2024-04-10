#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 500005;
const int MAXB = 715;
const int INF = (int)1e9;

int N, Q;
int a[MAXN];
int bucket[MAXB];
set < pii > S[MAXB];
int M;

void load() {
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

void add(int &x, int y) {
    if (x <= INF) x += y;
}

void inc(int lo, int hi, int val) {
    for (int i = lo; i <= hi; i++) {
        S[i / MAXB].erase(pii(a[i], i));
        add(a[i], val);
        S[i / MAXB].insert(pii(a[i], i));
    }
}

void update(int lo, int hi, int val) {
    int idx_lo = lo / MAXB;
    int idx_hi = hi / MAXB;
    if (idx_lo < idx_hi) {
        inc(lo, (idx_lo + 1) * MAXB - 1, val);
        inc(idx_hi * MAXB, hi, val);
        for (int i = idx_lo + 1; i < idx_hi; i++)
            add(bucket[i], val);
        return;
    }
    inc(lo, hi, val);
}

int query(int val) {
    int mini = N, maks = -1;
    for (int i = 0; i < M; i++) {
        set < pii > :: iterator l = S[i].lower_bound(pii(val - bucket[i], -1));
        if (l == S[i].end() || l -> first != val - bucket[i]) continue;
        set < pii > :: iterator r = S[i].upper_bound(pii(val - bucket[i], N));
        if (r == S[i].begin() || (--r) -> first != val - bucket[i]) continue;
        mini = min(mini, l -> second);
        maks = max(maks, r -> second);
    }
    return maks == -1 ? -1 : maks - mini; 
}

void solve() {
    M = (N - 1) / MAXB + 1;
    for (int i = 0; i < N; i++)
        S[i / MAXB].insert(pii(a[i], i));
    while (Q--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            update(--l, --r, x);
            continue;
        }
        int y;
        scanf("%d", &y);
        printf("%d\n", query(y));
    }
}

int main() {
    load();
    solve();
    return 0;
}