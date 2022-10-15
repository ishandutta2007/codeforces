#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<ld, ld>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;

pii a[MN]; int n;

ld check(ld pos) {
    ld ret = 0;
    for (int i = 1; i <= n; i++) {
        ld y = ((pos * pos) - (2 * pos * a[i].f) + (a[i].f * a[i].f) + (a[i].s * a[i].s)) / (2 * a[i].s);
        ret = max(ret, y);
    }
    return ret;
}

int main() {
    boost();

    cin >> n;
    bool pos = 0, neg = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].f >> a[i].s;
        if (a[i].s > 0) pos = 1;
        else neg = 1;
        a[i].s = abs(a[i].s);
    }
    if (pos && neg) return 0 * printf("-1\n");
    ld lo = -1e8, hi = 1e8, mid;
    while (1) {
        mid = (lo + hi) / 2;
        ld p1 = check(mid - 1e-7), p2 = check(mid), p3 = check(mid + 1e-7);
        if (p1 < p2 && p2 < p3) hi = mid;
        else if (p1 > p2 && p2 > p3) lo = mid;
        else break;
    }
    printf("%.7Lf\n", check(mid));

    return 0;
}