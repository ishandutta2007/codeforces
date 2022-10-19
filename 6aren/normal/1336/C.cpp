#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int MOD = 998244353;
const int N = 3005;

vector<pair<ii, int>> dp[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s; t = " " + t;
    for (int i = 1; i <= m; i++) {
        if (s[1] == t[i]) dp[1].pb({{i, i}, 1});
    }
    dp[1].pb({{m + 1, m + 1}, 1});
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        vector<pair<ii, int>> temp;
        for (auto it : dp[i - 1]) {
            int l = it.x.x;
            int r = it.x.y;
            int cnt = it.y;
            if (s[i] == t[l - 1]) {
                temp.pb({{l - 1, r}, cnt});
            }
            if (r == m || r == m + 1) {
                temp.pb({{l, m + 1}, cnt});
            } else if (s[i] == t[r + 1]) temp.pb({{l, r + 1}, cnt});
            if (l == m + 1 && r == m + 1) temp.pb({{l, r}, cnt});
        }
        sort(all(temp));
        auto cur = temp[0];
        for (int j = 1; j < temp.size(); j++) {
            if (cur.x == temp[j].x) {
                cur.y = (cur.y + temp[j].y) % MOD;
            } else {
                dp[i].pb(cur);
                cur = temp[j];
            }
        }
        dp[i].pb(cur);
    }
    for (int i = 1; i <= n; i++) {
        for (auto it : dp[i]) {
            if (it.x.x == 1 && it.x.y >= m) ans = (ans + 2 * it.y) % MOD;
        }
    }
    cout << ans;
    return 0;
}