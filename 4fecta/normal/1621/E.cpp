#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

struct grp {
    int sum, sz, id;
};

bool cmp(grp p, grp q) {
    return p.sum * q.sz < q.sum * p.sz;
}

const int MN = 200005;

int t, n, m, a[MN], k, u, poss[MN], sum[MN], ok[MN], okr[MN], okl[MN];
vector<pii> b[MN];
grp g[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        int id = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= m; i++) {
            cin >> k;
            for (int j = 1; j <= k; j++) {
                cin >> u;
                b[i].push_back({u, ++id});
                sum[i] += u;
            }
            sort(b[i].begin(), b[i].end());
            g[i] = {sum[i], k, i};
        }
        sort(g + 1, g + m + 1, cmp);
        for (int i = 1; i <= m; i++) {
            int lo = 1, hi = n + 1, mid;
            while (lo < hi) {
                mid = (lo + hi) >> 1;
                if (g[i].sum <= a[mid] * g[i].sz) hi = mid; //first id where this is true
                else lo = mid + 1;
            }
            int cnt = n + 1 - lo;
            int cor = m - i + 1;
            if (cnt >= cor) ok[i] = 1; //ok if no move
            if (cnt >= cor + 1) okl[i] = 1; //ok if shifted left
            if (cnt >= cor - 1) okr[i] = 1; //ok if shifted right
        }
        for (int i = 1; i <= m; i++) {
            ok[i] += ok[i - 1];
            okl[i] += okl[i - 1];
            okr[i] += okr[i - 1];
        }
        for (int i = 1; i <= m; i++) {
            for (pii p : b[g[i].id]) {
                grp tmp = {g[i].sum - p.f, g[i].sz - 1, i};
                if (p.f * g[i].sz >= g[i].sum) { //moves left
                    int lo = 1, hi = i, mid; //first one that is geq to new val
                    while (lo < hi) {
                        mid = (lo + hi) >> 1;
                        if (tmp.sum * g[mid].sz <= g[mid].sum * tmp.sz) hi = mid;
                        else lo = mid + 1;
                    }
                    int cor = m - lo + 1;
                    //if (p.f == 1) printf("lo1: %d\n", lo);
                    int nid = lo;
                    lo = 1, hi = n + 1;
                    while (lo < hi) {
                        mid = (lo + hi) >> 1;
                        if (tmp.sum <= a[mid] * tmp.sz) hi = mid; //first id where this is true
                        else lo = mid + 1;
                    }
                    int cnt = n + 1 - lo;
                    if (cnt >= cor && ok[m] - ok[i] + okr[i - 1] - okr[nid - 1] + ok[nid - 1] == m - 1) poss[p.s] = 1;
                } else {
                    int lo = i, hi = m, mid; //last one that is leq to new val
                    while (lo < hi) {
                        mid = (lo + hi + 1) >> 1;
                        if (tmp.sum * g[mid].sz >= g[mid].sum * tmp.sz) lo = mid;
                        else hi = mid - 1;
                    }
                    int cor = m - lo + 1;
                    //if (p.f == 1) printf("lo: %d\n", lo);
                    int nid = lo;
                    lo = 1, hi = n + 1;
                    while (lo < hi) {
                        mid = (lo + hi) >> 1;
                        if (tmp.sum <= a[mid] * tmp.sz) hi = mid; //first id where this is true
                        else lo = mid + 1;
                    }
                    int cnt = n + 1 - lo;
                    if (cnt >= cor && ok[m] - ok[nid] + okl[nid] - okl[i] + ok[i - 1] == m - 1) poss[p.s] = 1;
                }
            }
        }
        for (int i = 1; i <= id; i++) printf("%lld", poss[i]), poss[i] = 0;
        printf("\n");
        for (int i = 1; i <= n; i++) {
            sum[i] = 0;
            ok[i] = okl[i] = okr[i] = 0;
            b[i].clear();
            g[i] = {0, 0, 0};
        }
    }

    return 0;
}