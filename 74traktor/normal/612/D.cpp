#include <bits/stdc++.h>

using namespace std;

pair < int, int > a[1000005];
int inf = 1e9;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, l, r;
    cin >> n >> k;
    vector < pair < int, int > > Q;
    vector < pair < int, int > > T;
    for (int i = 1; i <= n; ++i) {
        cin >> l >> r;
        a[i] = {l, r};
        Q.push_back({l, 0});
        Q.push_back({r, 1});
        T.push_back({l, r});
    }
    sort(Q.begin(), Q.end());
    int bal = 0, last_l;
    vector < pair < int, int > > ans;
    for (auto key : Q) {
        if (key.second == 0) {
            bal++;
            if (bal == k) last_l = key.first;
        }
        else {
            if (bal == k) ans.push_back({last_l, key.first});
            bal--;
        }
    }
    cout << ans.size() << '\n';
    for (auto key : ans) cout << key.first << " " << key.second << '\n';
    return 0;
}