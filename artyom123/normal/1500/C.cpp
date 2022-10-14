#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for (auto &c : a) {
        for (auto &l : c) cin >> l;
    }
    for (auto &c : b) {
        for (auto &l : c) cin >> l;
    }
    vector<pair<vector<int>, int>> sa, sb;
    for (int i = 0; i < n; i++) {
        sa.pb(a[i], i);
        sb.pb(b[i], i);
    }
    sort(all(sa));
    sort(all(sb));
    for (int i = 0; i < n; i++) {
        if (sa[i].fi != sb[i].fi) {
            cout << -1;
            return 0;
        }
        b[sb[i].se].pb(sa[i].se);
    }
    vector<int> bad(m + 1);
    for (int j = 0; j <= m; j++) {
        for (int i = 1; i < n; i++) {
            if (b[i][j] < b[i - 1][j]) bad[j]++;
        }
    }
    vector<int> cl(n);
    queue<int> q;
    vector<int> usd(m + 1);
    for (int j = 0; j <= m; j++) {
        if (bad[j] == 0) {
            usd[j] = 1;
            q.push(j);
        }
    }
    vector<int> ans;
    while (q.size()) {
        int j = q.front();
        if (j == m) {
            reverse(all(ans));
            cout << ans.size() << "\n";
            for (auto &c : ans) cout << c + 1 << " ";
            return 0;
        }
        ans.pb(j);
        q.pop();
        for (int i = 1; i < n; i++) {
            if (cl[i]) continue;
            if (b[i][j] == b[i - 1][j]) continue;
            cl[i] = 1;
            for (int j1 = 0; j1 <= m; j1++) {
                if (b[i][j1] < b[i - 1][j1]) bad[j1]--;
                if (bad[j1] == 0 && !usd[j1]) {
                    usd[j1] = 1;
                    q.push(j1);
                }
            }
        }
    }
    cout << -1;
    return 0;
}