#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(), (x).end()

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<vector<pair<int, char>>> gist(k);
        vector<int> suf_ones(n + 1);
        for (int i = n - 1; i >= 0; i--) suf_ones[i] = suf_ones[i + 1] + (s[i] == '1');
        for (int i = 0; i < n; i++) gist[i % k].pb(i, s[i]);
        vector<vector<int>> pr(k);
        vector<vector<int>> suf(k);
        vector<int> pos(k);
        for (int i = 0; i < k; i++) {
            pr[i].resize(gist[i].size());
            pr[i][0] = (gist[i][0].se == '0' ? 1 : -1);
            for (int j = 1; j < (int)pr[i].size(); j++) {
                pr[i][j] = pr[i][j - 1] + (gist[i][j].se == '0' ? 1 : -1);
            }
            suf[i].resize(pr[i].size() + 1);
            suf[i].back() = INF;
            for (int j = (int)pr[i].size() - 1; j >= 0; j--) {
                suf[i][j] = min(suf[i][j + 1], pr[i][j]);
            }
        }
        int ans = suf_ones[0];
        int pr_ans = 0;
        for (int i = 0; i < n; i++) {
            int cur_ans = pr_ans + (s[i] == '0' ? 1 : 0);
            while (pos[i % k] < (int)pr[i % k].size() && gist[i % k][pos[i % k]].fi <= i) pos[i % k]++;
            ans = min(ans, cur_ans + min(0, suf[i % k][pos[i % k]] - pr[i % k][pos[i % k] - 1]) + suf_ones[i + 1]);
            pr_ans += (s[i] == '0' ? 0 : 1);
        }
        cout << ans << "\n";
    }
    return 0;
}