#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

vector<vector<int>> g;
vector<int> usd;

void dfs(int v, vector<int> &comp) {
    usd[v] = 1;
    comp.pb(v);
    for (auto &to : g[v]) {
        if (usd[to]) continue;
        dfs(to, comp);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<vector<int>> a(2, vector<int>(n));
        vector<int> cnt(n);
        vector<vector<int>> c(n);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j]; a[i][j]--;
                cnt[a[i][j]]++;
                c[a[i][j]].pb(j);
            }
        }
        bool ok = true;
        for (auto &c : cnt) {
            if (c != 2) {
                ok = false;
            }
        }
        if (!ok) {
            cout << -1 << "\n";
            continue;
        }
        g.clear();
        g.resize(n);
        usd.assign(n, 0);
        for (int i = 0; i < n; i++) {
            g[c[i][0]].pb(c[i][1]);
            g[c[i][1]].pb(c[i][0]);
        }
        int ans = 0;
        vector<int> lol;
        for (int i = 0; i < n; i++) {
            if (usd[i]) continue;
            vector<int> comp;
            dfs(i, comp);
            vector<int> cnt(2);
            cnt[0]++;
            int cur = 0;
            vector<vector<int>> kek(2);
            kek[0].pb(comp[0]);
            for (int j = 1; j < (int)comp.size(); j++) {
                if (a[0][comp[j - 1]] == a[0][comp[j]] || a[1][comp[j - 1]] == a[1][comp[j]]) cur ^= 1;
                cnt[cur]++;
                kek[cur].pb(comp[j]);
            }
            ans += min(cnt[0], cnt[1]);
            if (cnt[0] <= cnt[1]) {
                for (auto &c : kek[0]) lol.pb(c);
            } else {
                for (auto &c : kek[1]) lol.pb(c);
            }
        }
        cout << ans << "\n";
        for (auto &c : lol) cout << c + 1 << " ";
        cout << "\n";
    }
    return 0;
}