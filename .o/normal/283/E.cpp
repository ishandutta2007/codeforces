#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 100500;
int N, K;
int S[N_];

vector<pii> events[N_];

struct node {
    int len;
    int sum;
    int tag;
    node (int len = 0, int sum = 0, int tag = 0): len(len), sum(sum), tag(tag) { }
    void flip() { tag ^= 1; sum = len - sum; }
};

node merge (node p, node q) {
    return node(p.len + q.len, p.sum + q.sum, 0);
}

const int LEAF = 131072;
class SegmentTree {
    node tree[LEAF + LEAF];

    void push (int idx) {
        if(idx < LEAF && tree[idx].tag == 1) {
            for(int ch = idx*2; ch <= 2*idx+1; ch++) tree[ch].flip();
        }
        tree[idx].tag = 0;
    }

    void merge (int idx) {
        tree[idx] = ::merge(tree[idx*2], tree[idx*2+1]);
    }

    void init (int idx, int nl, int nr) {
        if(nl > nr) return;
        if(nl == nr) {
            tree[idx] = node(1, 0, 0);
            return;
        }
        int nm = (nl + nr) >> 1;
        init(idx*2, nl, nm);
        init(idx*2+1, nm+1, nr);
        merge(idx);
    }

    void flip (int idx, int nl, int nr, int l, int r) {
        push(idx);

        if(l <= nl && nr <= r) {
            tree[idx].flip();
            return;
        }

        int nm = (nl + nr) >> 1;
        if(l <= nm)
            flip(idx*2, nl, nm, l, min(r, nm));
        if(r >= nm+1)
            flip(idx*2+1, nm+1, nr, max(l, nm+1), r);

        merge(idx);
    }

    int count (int idx, int nl, int nr, int l, int r) {
        push(idx);

        if(l <= nl && nr <= r) {
            return tree[idx].sum;
        }

        int ret = 0;
        int nm = (nl + nr) >> 1;

        if(l <= nm)
            ret += count(idx*2, nl, nm, l, min(r, nm));
        if(r >= nm+1)
            ret += count(idx*2+1, nm+1, nr, max(l, nm+1), r);

        return ret;
    }

public:
    SegmentTree() { }
    void init() {
        init(1, 1, N);
    }

    void flip (int l, int r) {
        assert(1 <= l && l <= r && r <= N);
        flip (1, 1, N, l, r);
    }

    int count (int l, int r) {
        if(l > r) return 0;
        return count(1, 1, N, l, r);
    }
} seg;

int main() {
    scanf("%d%d", &N, &K);
    for(int i = 1; i <= N; i++) scanf("%d", S+i);
    sort(S+1, S+N+1);
    for(int i = 1; i <= K; i++) {
        int a, b; scanf("%d%d", &a, &b);
        int p = lower_bound(S+1, S+N+1, a) - S;
        int q = upper_bound(S+1, S+N+1, b)-1 - S;
        if(p <= q) {
            events[p].push_back(pii(p, q));
            events[q+1].push_back(pii(p, q));
        }
    }

    seg.init();

    ll ans = (ll)N * (N - 1) * (N - 2) / 6;
    for(int i = 1; i <= N; i++) {
        for(auto e : events[i]) seg.flip(e.first, e.second);
        ll c = seg.count(i+1, N) + ((i-1) - seg.count(1, i-1));
        ans -= c * (c - 1) / 2;
    }

    printf("%lld\n", ans);
    return 0;
}