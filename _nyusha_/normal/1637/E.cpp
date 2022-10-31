#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
int const maxn = 3e5 + 5;
int a[maxn];
vector < int > best[maxn];
map < int, int > cnt;
unordered_map < int, int > bad[maxn];
unordered_map < int, int > f;
int pref[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int tmp = 0;
    while (t--) {
        int n, m, u, v;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) best[i] = {}, bad[i] = {};
        cnt.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) f[a[i]] = i, bad[i][a[i]] = 1;
        for (int i = 1; i <= m; ++i) {
            cin >> u >> v;
            bad[f[u]][v] = 1;
            bad[f[v]][u] = 1;
        }
        vector < pair < int, int > > Q;
        for (auto key : cnt) {
            Q.push_back({key.second, key.first});
            best[key.second].push_back(key.first);
        }
        for (int i = 1; i <= n; ++i) {
            sort(best[i].rbegin(), best[i].rend());
        }
        sort(Q.begin(), Q.end());
        ll ans = 0;
        vector < int > t;
        int lst = 0;
        for (auto key : Q) {
            if (key.first != lst) t.push_back(key.first);
            lst = key.first;
        }
        m = m * 2 + n;
        for (int i = 0; i < (int)t.size(); ++i) {
            for (int j = i; j < (int)t.size(); ++j) {
                ll s = t[i] + t[j];
                if ((int)best[t[i]].size() <= (int)best[t[j]].size()) {
                    int good = 0;
                    for (auto key : best[t[i]]) {
                        int pos = f[key];
                        for (auto elem : best[t[j]]) {
                            if (bad[pos].find(elem) != bad[pos].end()) {
                                continue;
                            }
                            ans = max(ans, s * (ll)(key + elem));
                            break;
                        }
                    }
                } else {
                    for (auto key : best[t[j]]) {
                        int pos = f[key];
                        for (auto elem : best[t[i]]) {
                            if (bad[pos].find(elem) != bad[pos].end()) {
                                continue;
                            }
                            ans = max(ans, s * (ll)(key + elem));
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}