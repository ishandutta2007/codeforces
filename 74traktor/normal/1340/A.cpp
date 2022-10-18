#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int p[maxn], cnt[maxn], pos[maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    multiset < int > Q;
    set < int > oks;
    for (int i = 1; i <= n; ++i) {
        cnt[i] = 1;
        Q.insert(1);
        pos[p[i]] = i;
        oks.insert(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt[pos[i]] != (*Q.rbegin())) {
            cout << "No" << '\n';
            return;
        }
        Q.erase(Q.find(cnt[pos[i]]));
        oks.erase(pos[i]);
        auto it = oks.upper_bound(pos[i]);
        if (it != oks.end()) {
            Q.erase(Q.find(cnt[(*it)]));
            cnt[(*it)] += cnt[pos[i]];
            Q.insert(cnt[(*it)]);
        }
    }
    cout << "Yes" << '\n';
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}