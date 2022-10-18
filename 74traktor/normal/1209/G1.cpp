#include <bits/stdc++.h>

using namespace std;

int a[200005];
int last[200005];
map < int, int > cnt;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, ans = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) last[a[i]] = i;
    int righ = 1, lef = 1;
    multiset < int > Q;
    for (int i = 1; i <= n; ++i) {
        righ = max(righ, last[a[i]]);
        if (cnt[a[i]] == 0) Q.insert(1), cnt[a[i]] = 1;
        else {
            Q.erase(Q.find(cnt[a[i]]));
            cnt[a[i]]++;
            Q.insert(cnt[a[i]]);
        }
        if (i == righ) {
            ans += (righ - lef + 1 - (*Q.rbegin()));
            Q = {};
            cnt.clear();
            lef = i + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}