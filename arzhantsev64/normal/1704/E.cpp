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

vector<int> v;
vector<int> cnt;
vector<vector<int>> G;
vector<vector<int>> rG;

void dfs(int i) {
    int ans = v[i];
    for (int to : rG[i]) {
        if (cnt[to] == -1)
            dfs(to);
        ans = (ans + cnt[to]) % mod;
    }
    cnt[i] = ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    v = vector<int> (n);
    cnt = vector<int> (n, -1);
    G = vector<vector<int>> (n);
    rG = vector<vector<int>> (n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    vector<int> ins(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        ins[u]++;
        G[u].push_back(v);
        rG[v].push_back(u);
    }

    int T = 10000;

    for (int _ = 0; _ < T; ++_) {
        vector<int> S;
        for (int i = 0; i < n; ++i)
            if (v[i] > 0)
                S.push_back(i);
        if (S.size() == 0) {
            cout << _ << '\n';
            return;
        }

        for (int i : S) {
            v[i]--;
            for (int to : G[i])
                v[to]++;
        }
    }

    int start = 0;
    for (int i = 0; i < n; ++i)
        if (ins[i] == 0)
            start = i;
    dfs(start);
    cout << (T + cnt[start]) % mod << endl;
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

/*

7 4 8 1 6 10 3 5 2 9
*/