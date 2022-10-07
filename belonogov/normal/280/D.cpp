#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
const int T = 20;

struct R {
    int a[2][2][T + 1];
    R() {
        memset(a, 0, sizeof(a));
        for (int t1 = 0; t1 < 2; t1++)
            for (int t2 = 0; t2 < 2; t2++)
                for (int i = 0; i <= T; i++)
                    a[t1][t2][i] = -INF;
    }
};

void relax(R & res) {
    for (int i = 0; i <= T; i++) {
        res.a[0][1][i] = max(res.a[0][1][i], res.a[1][1][i]);
        res.a[1][0][i] = max(res.a[1][0][i], res.a[1][1][i]);
        res.a[0][0][i] = max(res.a[0][0][i], res.a[0][1][i]);
        res.a[0][0][i] = max(res.a[0][0][i], res.a[1][0][i]);
    }
}

R merge(const R & l, const R & r) {
    R res;

    for (int t1 = 0; t1 < 2; t1++)
        for (int t2 = 0; t2 < 2; t2++) {
            int curL = 0;
            int curR = 0;
            int sum = l.a[t1][0][curL] + r.a[0][t2][curR];
            for (int i = 0; i <= T; i++) {
                res.a[t1][t2][i] = max(res.a[t1][t2][i], sum);
                if (i == T) break;
                int dl = (l.a[t1][0][curL + 1] - l.a[t1][0][curL]);
                int dr = (r.a[0][t2][curR + 1] - r.a[0][t2][curR]);
                if (dl > dr) {
                    sum += dl;
                    curL++;
                }
                else {
                    sum += dr;
                    curR++;
                }
            }
        }

    for (int t1 = 0; t1 < 2; t1++)
        for (int t2 = 0; t2 < 2; t2++) {
            int curL = 1;
            int curR = 1;
            int sum = l.a[t1][1][curL] + r.a[1][t2][curR];
            for (int i = 1; i <= T; i++) {
                res.a[t1][t2][i] = max(res.a[t1][t2][i], sum);
                if (i == T) break;
                int dl = (l.a[t1][1][curL + 1] - l.a[t1][1][curL]);
                int dr = (r.a[1][t2][curR + 1] - r.a[1][t2][curR]);
                if (dl > dr) {
                    sum += dl;
                    curL++;
                }
                else {
                    sum += dr;
                    curR++;
                }
            }
        }
    relax(res);
    return res;
}

int n, m;
int a[N];
R tree[N * 4];

void init(int v, int val) {
    for (int i = 0; i <= T; i++) {
        tree[v].a[0][1][i] = -INF;
        tree[v].a[1][0][i] = -INF;
        tree[v].a[0][0][i] = 0;
        tree[v].a[1][1][i] = val;
    }
    tree[v].a[1][1][0] = -INF;
    relax(tree[v]);
}

void build(int v, int ll, int rr) {
    if (ll + 1 == rr) {
        init(v, a[ll]);
        return;
    }
    build(v * 2 + 1, ll, (ll + rr) / 2);
    build(v * 2 + 2, (ll + rr) / 2, rr);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}


void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void add(int v, int ll, int rr, int pos, int val) {
    if (pos < ll || rr <= pos) return;
    if (ll + 1 == rr) {
        init(v, val);
        return;
    }
    add(v * 2 + 1, ll, (ll + rr) / 2, pos, val);
    add(v * 2 + 2, (ll + rr) / 2, rr, pos, val);

    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}

R get(int v, int ll, int rr, int l, int r) {
    if (l >= rr || ll >= r) {
        R res;
        for (int i = 0; i <= T; i++)
            res.a[0][0][i] = 0;
        return res;
    }
    if (l <= ll && rr <= r) return tree[v];
    return merge(get(v * 2 + 1, ll, (ll + rr) / 2, l, r),
                 get(v * 2 + 2, (ll + rr) / 2, rr, l, r));
}

void solve() {
    build(0, 0, n);

    //db(tree[0].a[1][1][1]);
    //db(tree[2].a[1][0][1]);
    //db(tree[5].a[0][0][0]);
    //db(tree[6].a[1][1][1]);

    scanf("%d", &m);
    for (int t = 0; t < m; t++) {
        //if (t % 1000 == 0) 
            //db(t);
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k); l--;
            auto tmp = get(0, 0, n, l, r);
            int res = 0;
            for (int i = 0; i <= k; i++)
                for (int t1 = 0; t1 < 2; t1++)
                    for (int t2 = 0; t2 < 2; t2++)
                        res = max(tmp.a[t1][t2][i], res);

            printf("%d\n", res);
        }
        else if (type == 0) {
            int pos, val;
            scanf("%d%d", &pos, &val); pos--;
            add(0, 0, n, pos, val);
        }
        else
            assert(false);
    }
    cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("test.txt", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }


    else {
        stress();
    }

    return 0;
}