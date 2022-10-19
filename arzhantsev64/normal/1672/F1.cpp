#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
        cnt[x] += 1;
    }
    vector<pair<int, int>> v;
    for (auto p : cnt)
        v.push_back({p.second, p.first});
    sort(v.begin(), v.end());

    unordered_map<int, int> next;
    vector<int> to_add;
    for (int i = 0; i < v.size(); ++i) {
        // cout << v[i].scecond << ' ' << v[i].first << endl;
        if (i + 1 != v.size()) {
            next[v[i].second] = v[i + 1].second;
        } else {
            next[v[i].second] = -1;
        }
        // cout << "> " << v[i].second << ' ' << v[i].first - ((i == 0) ? (int)0 : v[i - 1].first) << endl;
        for (int _ = 0; _ < v[i].first - ((i == 0) ? (int)0 : v[i - 1].first); ++_) {
            to_add.push_back(v[i].second);
        }
    }
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (next[a[i]] != -1) {
            cout << next[a[i]] << ' ';
        } else {
            cout << to_add[j++] << ' ';
        }
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
         solve();

    return 0;
}