#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int n, t, a[MN], d[MN], st[MN * 4];

void build(int l, int r, int idx) {
    if (l == r) {st[idx] = d[l]; return;}
    int mid = (l + r) >> 1;
    build(l, mid, idx * 2), build(mid + 1, r, idx * 2 + 1);
    st[idx] = __gcd(st[idx * 2], st[idx * 2 + 1]);
}

int qry(int l, int r, int x, int y, int idx) {
    if (r < x || l > y) return 0;
    if (r <= y && l >= x) return st[idx];
    int mid = (l + r) >> 1;
    return __gcd(qry(l, mid, x, y, idx * 2), qry(mid + 1, r, x, y, idx * 2 + 1));
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i < n; i++) {
            d[i] = abs(a[i + 1] - a[i]);
        }
        if (n > 1) build(1, n - 1, 1);
        int ans = 0;
        int l = 1;
        for (int i = 1; i < n; i++) {
            while (l <= i && qry(1, n - 1, l, i, 1) == 1) l++;
            ans = max(ans, i - l + 1);
        }
        printf("%lld\n", ans + 1);
    }

    return 0;
}