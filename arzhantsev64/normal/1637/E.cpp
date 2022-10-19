#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (cnt.find(x) == cnt.end())
            cnt[x] = 0;
        cnt[x]++;
    }
    unordered_set<int> bad;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        bad.insert((u - 1) * (int)1e9 + (v - 1));
        bad.insert((v - 1) * (int)1e9 + (u - 1));
    }
    unordered_map<int, vector<int>> mp;
    for (auto p : cnt) {
        if (mp.find(p.second) == mp.end())
            mp[p.second] = {};
        mp[p.second].push_back(p.first);
    }
    vector<int> cnts;
    unordered_map<int, vector<int>> mmp;

    for (auto p : mp) {
        auto c = p.first;
        vector<int> v = p.second;
        sort(v.rbegin(), v.rend());
        mmp[c] = v;
        cnts.push_back(c);
    }
    sort(cnts.begin(), cnts.end());
    mp = mmp;

    int ans = 0;
    for (int i = 0; i < cnts.size(); ++i) {
        for (int a : mp[cnts[i]]) {
            for (int j = 0; j <= i; ++j) {
                for (int b : mp[cnts[j]]) {
                    if (!(a == b || bad.count((a - 1) * (int)1e9 + (b - 1)))) {
                        ans = max(ans, (a + b) * (cnts[i] + cnts[j]));
                        break;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();


    return 0;
}