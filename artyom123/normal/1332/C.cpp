#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

vector <vector<int>> g;
vector <int> usd;

void dfs(int v, vector<int>&comp) {
    usd[v] = 1;
    comp.pb(v);
    for (auto &to : g[v]) {
        if (!usd[to]) {
            dfs(to, comp);
        }
    }
}

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
        g.clear();
        usd.clear();
        g.resize(s.size());
        usd.resize(s.size());
        for (int i = 0; i < n; i++) {
            if (i + k < n) {
                g[i].push_back(i + k);
                g[i + k].push_back(i);
            }
        }
        for (int i = 0; i < n; i++) {
            int j = n - 1 - i;
            g[i].push_back(j);
            g[j].push_back(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (usd[i]) {
                continue;
            }
            vector <int> comp;
            dfs(i, comp);
            vector <int> cnt(26);
            int MX = 0;
            for (auto &c : comp) {
                cnt[s[c] - 'a']++;
                MX = max(MX, cnt[s[c] - 'a']);
            }
            ans += (comp.size() - MX);
        }
        cout << ans << "\n";
    }
    return 0;
}