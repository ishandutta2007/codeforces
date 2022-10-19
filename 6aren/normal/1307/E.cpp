#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 5005;
const int MOD = 1000000007;

int s[N];
int cnt1[N][N], cnt2[N][N];
vector<int> c[N];
int check[N];
int ans[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n + 1; j++) {
            cnt1[i][j] = cnt1[i][j - 1] + (s[j] == i);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 0; j--) {
            cnt2[i][j] = cnt2[i][j + 1] + (s[j] == i);
        }
    }
    int mx = 0;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        c[u].pb(v);
    }
    for (int i = 1; i <= n; i++) {
        sort(all(c[i]));
    }
    for (int i = 0; i <= n; i++) {
        int tmp = 0;
        if (i == 0) {
            for (int j = 1; j <= n; j++) {
                if (c[j].empty()) continue;
                if (cnt2[j][1] >= c[j][0]) tmp++;
            }
            mx = max(mx, tmp);
            check[i] = tmp;
            continue;
        }
        int foo = cnt1[s[i]][i];
        int k = lower_bound(all(c[s[i]]), foo) - c[s[i]].begin();
        if (k == (int) c[s[i]].size()) continue;
        if (c[s[i]][k] != foo) continue;
        for (int j = 1; j <= n; j++) {
            if (c[j].empty()) continue;
            int baz = cnt1[j][i];
            int bar = cnt2[j][i + 1];
            if (baz > bar) swap(baz, bar);
            if (bar >= c[j][0]) tmp++;
            if (baz >= c[j][0] && c[j].size() > 1 && bar >= c[j][1]) tmp++;
        }
        check[i] = tmp;
        mx = max(mx, tmp);
    }
    cout << mx << ' ';
    for (int i = 0; i <= n; i++) {
        if (check[i] != mx) continue;
        int tmp = 1;
        if (i == 0) {
            for (int j = 1; j <= n; j++) {
                int foo = cnt2[j][1];
                int cnt = upper_bound(all(c[j]), foo) - c[j].begin();
                if (cnt == 0) continue;
                tmp = 1LL * tmp * cnt % MOD;
            }
            ans[i] = tmp;
            continue;
        }
        int pivot = s[i];
        int baz = cnt2[pivot][i + 1];
        int cnt = upper_bound(all(c[pivot]), baz) - c[pivot].begin();
        if (cnt1[pivot][i] <= baz) cnt--;
        if (cnt) tmp = cnt;
        for (int j = 1; j <= n; j++) {
            if (c[j].empty()) continue;
            if (j == pivot) continue;
            baz = cnt1[j][i];
            int bar = cnt2[j][i + 1];
            int mxh = 0;
            if (bar < baz) swap(bar, baz);
            if (bar >= c[j][0]) mxh++;
            if (baz >= c[j][0] && c[j].size() > 1 && bar >= c[j][1]) mxh++;
            baz = cnt1[j][i];
            bar = cnt2[j][i + 1];
            int cur = 0;
            for (int e : c[j]) {
                if (mxh == 1) {
                    if (e <= min(bar, baz)) cur++;
                    if (e <= max(bar, baz)) cur++;
                    continue;
                }
                if (e > baz) continue;
                cnt = upper_bound(all(c[j]), bar) - c[j].begin();
                if (e <= bar) cnt--;
                cur += cnt;
            }
            if (cur) tmp = 1LL * tmp * cur % MOD;
        }
        ans[i] = tmp;
    }
    int res = 0;
    for (int i = 0; i <= n; i++) {
        res = (res + ans[i]) % MOD;
        //cout << ans[i] << endl;
    }
    if (mx == 0) cout << 1;
    else cout << res;
    return 0;
}