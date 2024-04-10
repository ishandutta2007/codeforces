#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

struct seg {
    int l, r, c;
};

int n;
seg a[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int lft = 0x3f3f3f3f, rit = 0, cl = 0x3f3f3f3f, cr = 0x3f3f3f3f, li, ri, ans = LLONG_MAX, good = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].l >> a[i].r >> a[i].c;
            if (a[i].l < lft) lft = a[i].l, cl = a[i].c, li = i, ans = LLONG_MAX, good = 0;
            else if (a[i].l == lft) {
                cl = min(cl, a[i].c);
                if (cl == a[i].c) li = i;
            }
            if (a[i].r > rit) rit = a[i].r, cr = a[i].c, ri = i, ans = LLONG_MAX, good = 0;
            else if (a[i].r == rit) {
                cr = min(cr, a[i].c);
                if (cr == a[i].c) ri = i;
            }
            ans = min(ans, cr + cl);
            if (a[i].l == lft && a[i].r == rit) ans = min(ans, a[i].c);
            printf("%lld\n", ans);
        }
    }

    return 0;
}