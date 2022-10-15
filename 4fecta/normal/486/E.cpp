#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;

int n, a[MN], st[3 * MN][2], ans[MN], lis = 0, cnt[MN], pre[MN];
stack<int> previ[MN];

void upd(int l, int r, int x, int val, int idx, int t) {
    if (l == r) {
        st[idx][t] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) upd(l, mid, x, val, idx * 2, t);
    else upd(mid + 1, r, x, val, idx * 2 + 1, t);
    st[idx][t] = max(st[idx * 2][t], st[idx * 2 + 1][t]);
}

int qry(int l, int r, int x, int y, int idx, int t) {
    if (r < x || l > y) return 0;
    if (r <= y && l >= x) return st[idx][t];
    int mid = (l + r) >> 1;
    return max(qry(l, mid, x, y, idx * 2, t), qry(mid + 1, r, x, y, idx * 2 + 1, t));
}

void upd(int x, int val, int t) {
    if (x > 100000 || x < 1) return;
    return upd(1, 100000, x, val, 1, t);
}

int qry(int l, int r, int t) {
    if (l > r || r < 1 || l > 100000) return 0;
    return qry(1, 100000, l, r, 1, t);
}

int main() {
    boost();

    for (int i = 1; i <= 100000; i++) previ[i].push(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int len = qry(1, a[i] - 1, 0) + 1;
        upd(a[i], len, 0);
        previ[a[i]].push(len);
        lis = max(lis, len);
    }
    //printf("%d\n", lis);
    for (int i = n; i > 0; i--) {
        ans[i] = 1;
        int p1 = qry(1, a[i] - 1, 0);
        int p2 = qry(a[i] + 1, 100000, 1);
        //printf("%d %d\n", p1, p2);
        if (p1 + p2 + 1 == lis) ans[i] = 2, cnt[p1]++, pre[i] = p1;
        upd(a[i], p2 + 1, 1);
        previ[a[i]].pop();
        upd(a[i], previ[a[i]].top(), 0);
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[pre[i]] == 1 && ans[i] == 2) ans[i] = 3;
        printf("%d", ans[i]);
    }

    return 0;
}