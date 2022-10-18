#include <bits/stdc++.h>

using namespace std;

int const maxn = 3e5 + 5;
int a[maxn];
int lef[maxn];
int righ[maxn];
int go[maxn];

void solve() {
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    set < int > bb;
    for (int i = 1; i <= n; ++i) {
        bb.insert(a[i]);
    }
    vector < int > b;
    for (auto key : bb) b.push_back(key);
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        lef[i] = n + 1;
        righ[i] = -1;
    }
    for (int i = 1; i <= n; ++i) lef[a[i]] = min(lef[a[i]], i), righ[a[i]] = max(righ[a[i]], i);
    n = (int)b.size();
    go[n + 1] = -1;
    for (int i = n; i >= 1; --i) {
        if (go[i + 1] == -1) go[i] = i;
        else {
            int l1 = lef[i], r1 = righ[i], l2 = lef[i + 1], r2 = righ[i + 1];
            if (r1 < l2) go[i] = go[i + 1];
            else go[i] = i;
        }
        ans = min(ans, n - (go[i] - i + 1));
    }
    cout << ans << '\n';
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}