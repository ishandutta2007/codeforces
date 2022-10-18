#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
set < int > g[maxn];
set < pair < int, int > > Q;
int cnt[maxn];

void dels(int u) {
    assert((int)g[u].size() <= 1);
    Q.erase({cnt[u], u});
    for (auto elem : g[u]) {
        g[elem].erase(u);
    }
    g[u] = {};
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
    while (t--) {
        int n, k, ans = 0, u, v;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) g[i] = {};
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            g[u].insert(v);
            g[v].insert(u);
        }
        Q = {};
        for (int i = 1; i <= n; ++i) {
            int ok = 0;
            for (auto t : g[i]) {
                if ((int)g[t].size() == 1) ok++;
            }
            cnt[i] = ok;
            Q.insert({ok, i});
        }
        while ((int)Q.size() > 0) {
            auto p = (*Q.rbegin());
            if (p.first < k) break;
            ans += (p.first / k);
            int good = p.first / k * k;
            vector < int > del;
            for (auto elem : g[p.second]) {
                if (good > 0 && (int)g[elem].size() == 1) del.push_back(elem), good--;
            }
            assert(good == 0);
            for (auto key : del) {
                dels(key);
            }
            Q.erase(p);
            Q.insert({p.first % k, p.second});
            cnt[p.second] = p.first % k;
            if ((int)g[p.second].size() <= 1) {
                for (auto elem : g[p.second]) {
                    Q.erase({cnt[elem], elem});
                    cnt[elem]++;
                    Q.insert({cnt[elem], elem});
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}