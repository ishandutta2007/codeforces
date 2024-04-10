#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;

int n, m, k, a[MN][10], ans[10], st[MN * 3][10], mx[10];

void build(int l, int r, int idx, int t) {
    if (l == r) {
        st[idx][t] = a[l][t];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx * 2, t);
    build(mid + 1, r, idx * 2 + 1, t);
    st[idx][t] = max(st[idx * 2][t], st[idx * 2 + 1][t]);
}

int qry(int l, int r, int x, int y, int idx, int t) {
    if (r < x || l > y) return INT_MIN;
    if (r <= y && l >= x) return st[idx][t];
    int mid = (l + r) >> 1;
    return max(qry(l, mid, x, y, idx * 2, t), qry(mid + 1, r, x, y, idx * 2 + 1, t));
}

bool check(int len) {
    if (len < 1) {memset(ans, 0, sizeof(ans)); return true;}
    for (int l = 1; l + len - 1 <= n; l++) {
        int r = l + len - 1;
        int sum = 0;
        for (int i = 1; i <= m; i++) {
            mx[i] = qry(1, n, l, r, 1, i);
            sum += mx[i];
        }
        if (sum <= k) {
            memcpy(ans, mx, sizeof(mx));
            return true;
        }
    }
    return false;
}

int main() {
    boost();

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) build(1, n, 1, i);
    int lo = 0, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        mid += (lo + hi) & 1;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    for (int i = 1; i <= m; i++) printf("%d ", ans[i]);

    return 0;
}