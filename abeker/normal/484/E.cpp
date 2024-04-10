#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;
const int offset = 1 << 17;

int N, M;
int h[MAXN];
pii p[MAXN];
int l[MAXN], r[MAXN], w[MAXN];
int lo[MAXN], hi[MAXN], mid[MAXN];
vector <int> V, E[MAXN];

struct node {
    int maks, pref, suff, len;
    node(int _maks = 0, int _pref = 0, int _suff = 0, int _len = 1) {
        maks = _maks; pref = _pref; suff = _suff; len = _len;
    }
};

struct tournament {
    node t[2 * offset];
    
    node merge(node A, node B) {
        node C;
        C.maks = max(max(A.maks, B.maks), A.suff + B.pref);
        C.pref = A.pref == A.len ? A.len + B.pref : A.pref;
        C.suff = B.suff == B.len ? B.len + A.suff : B.suff;
        C.len = A.len + B.len;
        return C;
    }
    
    void init() {
        for (int i = 0; i < N; i++)
            t[i + offset] = node();
        for (int i = offset - 1; i >= 0; i--) 
            t[i] = merge(t[2 * i], t[2 * i + 1]);
    }
    
    void update(int x) {
        x += offset;
        t[x] = node(1, 1, 1, 1);
        for (x /= 2; x; x /= 2)
            t[x] = merge(t[2 * x], t[2 * x + 1]); 
    }
    
    node query(int x, int lo, int hi, int from, int to) {
        if (to <= lo || from >= hi) return node(0, 0, 0, 0);
        if (lo >= from && hi <= to) return t[x];
        int mid = (lo + hi) / 2;
        return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
    }
    
    int query(int from, int to) {
        return query(1, 0, offset, from, to).maks;
    }
    
} T;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d", h + i);
}

void sweep() {
    
    for (int i = 0; i < N; i++) 
        E[i].clear();
    for (int i = 0; i < N; i++) 
        E[h[i]].push_back(i);
    for (int i = 0; i < M; i++) {
        mid[i] = (lo[i] + hi[i] + 1) / 2;
        E[mid[i]].push_back(N + i);
    }
    
    bool f = true;
    T.init();
    for (int i = N - 1; i >= 0; i--) 
        for (int j = 0; j < E[i].size(); j++) {
            int c = E[i][j];
            if (c < N) {
                T.update(c);
                continue;
            }
            c -= N;
            if (lo[c] >= hi[c]) continue;
            if (T.query(l[c], r[c]) < w[c]) hi[c] = mid[c] - 1;
            else lo[c] = mid[c];
            f = false;
        }
        
    if (!f) sweep();
}

void solve() {
    
    for (int i = 0; i < N; i++) 
        p[i] = pii(h[i], i);
    sort(p, p + N);
    
    for (int i = 0; i < N; i++) {
        if (!i || p[i].first != p[i - 1].first)
            V.push_back(p[i].first);
        h[p[i].second] = (int)V.size() - 1;
    }
    
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", l + i, r + i, w + i);
        l[i]--; hi[i] = (int)V.size() - 1;
    }
    
    sweep();
    
    for (int i = 0; i < M; i++) 
        printf("%d\n", V[lo[i]]);
      
}

int main() {
    load();
    solve();
    return 0;
}