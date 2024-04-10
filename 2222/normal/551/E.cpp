#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define long int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

const int N = 500000;
const int STEP = 1000;
const int BLOCKS = (N - 1) / STEP + 1;
const int V = 1000000001;

int a[BLOCKS][STEP], b[BLOCKS][STEP], d[BLOCKS];

void rebuild(int i) {
    auto ai = a[i];
    auto bi = b[i];
    copy(ai, ai + STEP, bi);
    sort(bi, bi + STEP);
}

int getLeft(int y) {
    REP (i, BLOCKS) {
        int need = y - d[i];
        if (need > 0 && binary_search(b[i], b[i] + STEP, need))
            return i * STEP + (find(a[i], a[i] + STEP, need) - a[i]);
    }
    return N;
}

int getRight(int y) {
    for (int i = BLOCKS; i --> 0; ) {
        int need = y - d[i];
        if (need > 0 && binary_search(b[i], b[i] + STEP, need)) {
            for (int j = STEP; ; ) {
                if (a[i][--j] == need)
                    return i * STEP + j;
            }
        }
    }
    return -1;
}

void add(int i, int l, int r, int x) {
    int k = i * STEP;
    FOR (j, max(l - k, 0), min(r - k + 1, STEP))
        a[i][j] = min(a[i][j] + x, V);
    rebuild(i);
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    REP (i, n) scanf("%d", a[0] + i);
    REP (i, BLOCKS) rebuild(i);
    for (; q > 0; --q) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            --l, --r;
            int i = l / STEP, j = r / STEP;
            add(i, l, r, x);
            if (i < j) {
                add(j, l, r, x);
                for (; ++i < j; )
                    d[i] = min(d[i] + x, V);
            }
        }
        if (t == 2) {
            int i, j = 0, y;
            scanf("%d", &y);
            i = getLeft(y);
            if (i < N) j = getRight(y);
            printf("%d\n", max(j - i, -1));
        }
    }
    return 0;
}