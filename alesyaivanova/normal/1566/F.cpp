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

struct event {
    int x, t, id;

    event(int x = 0, int t = 0, int id = 0): x(x), t(t), id(id) {}

    bool operator<(const event& other) const {
        return x < other.x;
    }
};

const int maxn = 2e5 + 9;
int a[maxn];
pii s[maxn];
int n, m;
event q[2 * maxn];
bool ok[maxn];
pii seg[maxn];
int dp[maxn][2];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < m; i++) {
        cin >> s[i].ff >> s[i].ss;
        q[i * 2] = event(s[i].ff, 1, i);
        q[i * 2 + 1] = event(s[i].ss + 1, -1, i);
    }
    sort(q, q + 2 * m);
    for (int i = 0; i < m; i++) {
        ok[i] = 1;
    }
    int e = 0;
    set<int> opened;
    for (int i = 0; i < n; i++) {
        while (e < 2 * m && q[e].x <= a[i]) {
            if (q[e].t == 1) {
                opened.insert(q[e].id);
            } else {
                opened.erase(q[e].id);
            }
            e++;
        }
        for (int x : opened) {
            ok[x] = 0;
        }
    }
    e = 0;
    for (int i = 0; i < m; i++) {
        if (ok[i]) {
            seg[e] = s[i];
            e++;
        }
    }
    m = e;
    if (m == 0) {
        cout << "0\n";
    } else {
        sort(seg, seg + m);
//        for (int i = 0; i < m; i++) {
//            cout << " " << seg[i].ff << " " << seg[i].ss << "\n";
//        }
        int e = 0;
        if (seg[0].ss < a[0]) {
            int min_r = seg[0].ss;
            e++;
            while (e < m && seg[e].ss < a[0]) {
                min_r = min(min_r, seg[e].ss);
                e++;
            }
            dp[0][0] = a[0] - min_r;
            dp[0][1] = 2 * (a[0] - min_r);
        } else {
            dp[0][0] = 0;
            dp[0][1] = 0;
        }
        for (int i = 1; i < n; i++) {
            if (e < m && seg[e].ss < a[i]) {
                int j = e;
                while (j < m && seg[j].ss < a[i]) {
                    j++;
                }
                j--;
                dp[i][0] = dp[i - 1][1] + (seg[j].ff - a[i - 1]);
                dp[i][0] = min(dp[i][0], dp[i - 1][0] + 2 * (seg[j].ff - a[i - 1]));
                dp[i][1] = dp[i][0];
                int min_r = seg[j].ss;
                while (j > e) {
                    min_r = min(min_r, seg[j].ss);
                    dp[i][0] = min(dp[i][0], dp[i - 1][1] + (seg[j - 1].ff - a[i - 1]) + (a[i] - min_r));
                    dp[i][0] = min(dp[i][0], dp[i - 1][0] + 2 * (seg[j - 1].ff - a[i - 1]) + (a[i] - min_r));
                    dp[i][1] = min(dp[i][1], dp[i - 1][1] + (seg[j - 1].ff - a[i - 1]) + 2 * (a[i] - min_r));
                    dp[i][1] = min(dp[i][1], dp[i - 1][0] + 2 * (seg[j - 1].ff - a[i - 1]) + 2 * (a[i] - min_r));
                    j--;
                }
                min_r = min(min_r, seg[e].ss);
                dp[i][0] = min(dp[i][0], dp[i - 1][0] + (a[i] - min_r));
                dp[i][1] = min(dp[i][1], dp[i - 1][0] + 2 * (a[i] - min_r));
                while (e < m && seg[e].ss < a[i]) {
                    e++;
                }
            } else {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i][0];
            }
        }
        if (e == m) {
            cout << dp[n - 1][0] << "\n";
        } else {
            int ans = dp[n - 1][1] + (seg[m - 1].ff - a[n - 1]);
            ans = min(ans, dp[n - 1][0] + 2 * (seg[m - 1].ff - a[n - 1]));
            cout << ans << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}