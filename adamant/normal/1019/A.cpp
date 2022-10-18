#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
#define fpos alfladla

const int maxn = 2e5 + 42;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int p[n], c[n];
    vector<int> votes[m];
    for(int i = 0; i < n; i++) {
        cin >> p[i] >> c[i];
        votes[p[i] - 1].push_back(c[i]);
    }
    for(int i = 0; i < m; i++) {
        sort(all(votes[i]));
    }
    int ans = 1e14;
    for(int i = votes[0].empty(); i <= n - votes[0].size(); i++) {
        int cnt = votes[0].size() + i;
        int cur = 0;
        int cnn = 0;
        vector<int> on_hold;
        for(int j = 1; j < m; j++) {
            for(int k = 0; k < int(votes[j].size()) - cnt + 1; k++) {
                cur += votes[j][k];
                cnn++;
            }
            for(int k = max<int>(0, int(votes[j].size()) - cnt + 1); k < votes[j].size(); k++) {
                on_hold.push_back(votes[j][k]);
            }
        }
        if(i > cnn) {
            nth_element(begin(on_hold), begin(on_hold) + (i - cnn), end(on_hold));
            for(int j = 0; j < i - cnn; j++) {
                cur += on_hold[j];
            }
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}