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

int n, a[MN], st[3 * MN], ans[MN];

void build(int l, int r, int idx) {
    if (l == r) {
        st[idx] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx * 2);
    build(mid + 1, r, idx * 2 + 1);
    st[idx] = min(st[idx * 2], st[idx * 2 + 1]);
}

int qry(int l, int r, int x, int y, int idx) {
    if (r < x || l > y) return INT_MAX;
    if (l >= x && r <= y) return st[idx];
    int mid = (l + r) >> 1;
    return min(qry(l, mid, x, y, idx * 2), qry(mid + 1, r, x, y, idx * 2 + 1));
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, n, 1);
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i < n; i++) {
        int lo = i + 1, hi = n, mid;
        if (qry(1, n, lo, n, 1) >= a[i]) continue;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            mid += (lo + hi) & 1;
            if (qry(1, n, mid, n, 1) < a[i]) lo = mid;
            else hi = mid - 1;
        }
        ans[i] = lo - i - 1;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);

    return 0;
}