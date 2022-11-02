#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e5 + 9;
vector<int> g1[maxn];
vector<int> g2[maxn];
int n, m;
int ans[maxn];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        g1[i].resize(x);
        for (int e = 0; e < x; e++) {
            cin >> g1[i][e];
            g1[i][e]--;
            g2[g1[i][e]].pb(i);
        }
    }
    int opt1 = -1;
    for (int i = 0; i < n; i++) {
        if (g2[i].size() > (m + 1) / 2) {
            if (opt1 == -1)
                opt1 = i;
        }
    }
    if (opt1 == -1) {
        cout << "YES\n";
        for (int i = 0; i < m; i++)
            cout << g1[i][0] + 1 << " ";
        cout << "\n";
    } else {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if ((int)g1[i].size() == 1 && g1[i][0] == opt1)
                cnt++;
        }
        if (cnt > (m + 1) / 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int u = (m + 1) / 2;
            for (int i = 0; i < m; i++) {
//                bool fl = 0;
//                for (int to : g1[i]) {
//                    if (to == opt1)
//                        fl = 1;
//                }
                if ((int)g1[i].size() == 1 && g1[i][0] == opt1) {
                    u--;
                    ans[i] = opt1;
                } else {
                    ans[i] = -1;
                }
            }
            for (int i = 0; i < m; i++) {
                if (ans[i] != -1) {
                    cout << ans[i] + 1 << " ";
                    continue;
                }
                bool fl = 0;
                for (int to : g1[i]) {
                    if (to == opt1)
                        fl = 1;
                }
                if (fl && u) {
                    cout << opt1 + 1 << " ";
                    u--;
                } else if (g1[i][0] != opt1) {
                    cout << g1[i][0] + 1 << " ";
                } else {
                    cout << g1[i][1] + 1 << " ";
                }
            }
            cout << "\n";
        }
    }
    for (int i = 0; i < max(n, m); i++) {
        g1[i].clear();
        g2[i].clear();
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}