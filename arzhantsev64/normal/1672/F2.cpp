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

vector<vector<int>> G;
vector<int> was;

bool dfs(int v) {
    was[v] = 1;
    for (auto to : G[v]) {
        if (was[to] == 1)
            return true;
        else if (was[to] == -1 && dfs(to))
            return true;
    }
    was[v] = 0;
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
        cnt[x] += 1;
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<pair<int, int>> v;
    for (auto p : cnt)
        v.push_back({p.second, p.first});
    sort(v.begin(), v.end());

    unordered_map<int, int> num;
    for (int i = 0; i < v.size(); ++i) {
        if (i + 1 != v.size()) {
            num[v[i].second] = i;
        } else {
            num[v[i].second] = -1;
        }
    }

    G = vector<vector<int>> ((int)num.size() - 1);

    for (int i = 0; i < n; ++i) {
        if (num[a[i]] == -1 || num[b[i]] == -1)
            continue;
        G[num[a[i]]].push_back(num[b[i]]);
    }

    was = vector<int> ((int)num.size() - 1, -1);
    for (int i = 0; i < G.size(); ++i)
        if (was[i] == -1 && dfs(i)) {
            cout << "WA" << endl;
            return;
        }
    cout << "AC" << endl;
    return;
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