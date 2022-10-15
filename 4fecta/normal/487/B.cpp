#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

struct node {
    int max, min;
};

const int MN = 100005;

int n, s, l, a[MN];
node st[3 * MN][2];

node push_up(node x, node y) {
    return {max(x.max, y.max), min(x.min, y.min)};
}

void build(int l, int r, int idx) {
    st[idx][1] = {0, 0};
    if (l == r) {
        st[idx][0] = {a[l], a[l]};
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
    st[idx][0] = push_up(st[idx * 2][0], st[idx * 2 + 1][0]);
}

void upd(int l, int r, int x, int val, int idx, int t) {
    if (l == r) {
        st[idx][t] = {val, val};
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) upd(l, mid, x, val, idx * 2, t);
    else upd(mid + 1, r, x, val, idx * 2 + 1, t);
    st[idx][t] = push_up(st[idx * 2][t], st[idx * 2 + 1][t]);
}

node qry(int l, int r, int x, int y, int idx, int t) {
    if (r < x || l > y) return {-0x3f3f3f3f, 0x3f3f3f3f};
    if (r <= y && l >= x) return st[idx][t];
    int mid = (l + r) >> 1;
    return push_up(qry(l, mid, x, y, idx * 2, t), qry(mid + 1, r, x, y, idx * 2 + 1, t));
}

int main() {
    boost();

    cin >> n >> s >> l;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(0, n, 1);
    upd(0, n, 0, 0, 1, 1);
    for (int i = 1; i <= n; i++) {
        int r = i - l;
        int lo = 1, hi = i, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            node ret = qry(0, n, mid, i, 1, 0);
            if (ret.max - ret.min <= s) hi = mid;
            else lo = mid + 1;
        }
        lo--;
        //printf("%d %d\n", lo, r);
        if (lo > r) {
            upd(0, n, i, 0x3f3f3f3f, 1, 1);
            continue;
        }
        int best = qry(0, n, lo, r, 1, 1).min;
        upd(0, n, i, best + 1, 1, 1);
    }
    //for (int i = 0; i <= n; i++) printf("%d ", qry(0, n, i, i, 1, 1).min);
    printf("%d\n", qry(0, n, n, n, 1, 1).min > 1000000000 ? -1 : qry(0, n, n, n, 1, 1).min);

    return 0;
}