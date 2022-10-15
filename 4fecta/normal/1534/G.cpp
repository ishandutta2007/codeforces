#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 800005;

int n, ans;
pii a[MN];
priority_queue<int> lft;
priority_queue<int, vector<int>, greater<>> rit;

bool cmp(pii p, pii q) {
    return p.f + p.s < q.f + q.s;
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].f >> a[i].s;
    }
    sort(a + 1, a + n + 1, cmp);
    lft.push(0), rit.push(0);
    for (int i = 1; i <= n; i++) {
        if (a[i].f <= lft.top()) {
            ans += lft.top() - a[i].f;
            lft.push(a[i].f), lft.push(a[i].f);
            rit.push(lft.top() - a[i].f - a[i].s);
            lft.pop();
        } else if (a[i].f >= rit.top() + a[i].f + a[i].s) {
            ans += a[i].f - (rit.top() + a[i].f + a[i].s);
            rit.push(-a[i].s), rit.push(-a[i].s);
            lft.push(rit.top() + a[i].f + a[i].s);
            rit.pop();
        } else lft.push(a[i].f), rit.push(-a[i].s);
    }
    printf("%lld\n", ans);

    return 0;
}