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

int n, pre[MN], suf[MN];
pii a[MN];

bool check(int lim) { //possible to get at least lim ppl?
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].f >= (lim - cnt - 1) && a[i].s >= cnt) cnt++;
    }
    return cnt >= lim;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].f >> a[i].s;
            a[i].f = min(a[i].f, n - i);
            a[i].s = min(a[i].s, i - 1);
        }
        int lo = 0, hi = n, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (check(mid)) lo = mid;
            else hi = mid - 1;
        }
        printf("%lld\n", lo);
    }

    return 0;
}