#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld long double
#define ll long long
#define pll pair<long long, long long>

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &c : a) cin >> c;
    vector<map<char, vector<int>>> gist(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)a[i].size(); j++) gist[i][a[i][j]].pb(j);
    }
    map<vector<int>, int> dp;
    map<vector<int>, vector<int>> pr;
    dp[vector<int>(n, -1)] = 0;
    set<vector<int>> q;
    q.insert(vector<int>(n, -1));
    while (q.size()) {
        vector<int> now = *q.begin();
        q.erase(q.begin());
        int val = dp[now];
        for (char c = 'a'; c <= 'z'; c++) {
            vector<int> nxt(n);
            bool bad = 0;
            for (int i = 0; i < n; i++) {
                int id = upper_bound(all(gist[i][c]), now[i]) - gist[i][c].begin();;
                if (id == (int)gist[i][c].size()) {
                    bad = 1;
                    continue;
                }
                nxt[i] = gist[i][c][id];
            }
            if (bad) continue;
            if (!dp.count(nxt)) q.insert(nxt);
            if (!dp.count(nxt) || dp[nxt] < val + 1) {
                dp[nxt] = val + 1;
                pr[nxt] = now;
            }
        }
        for (char c = 'A'; c <= 'Z'; c++) {
            vector<int> nxt(n);
            bool bad = 0;
            for (int i = 0; i < n; i++) {
                int id = upper_bound(all(gist[i][c]), now[i]) - gist[i][c].begin();;
                if (id == (int)gist[i][c].size()) {
                    bad = 1;
                    continue;
                }
                nxt[i] = gist[i][c][id];
            }
            if (bad) continue;
            if (!dp.count(nxt)) q.insert(nxt);
            if (!dp.count(nxt) || dp[nxt] < val + 1) {
                dp[nxt] = val + 1;
                pr[nxt] = now;
            }
        }
    }
    int ans = 0;
    vector<int> now(n, -1);
    for (auto &c : dp) {
        if (ans < c.se) {
            ans = c.se;
            now = c.fi;
        }
    }
    cout << ans << "\n";
    string s = "";
    while (now != vector<int>(n, -1)) {
        s += a[0][now[0]];
        now = pr[now];
    }
    reverse(all(s));
    cout << s << "\n";
    return;
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}