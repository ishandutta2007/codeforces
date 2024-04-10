#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int pref[maxn], used[maxn];
map < int, vector < int > > pos;
vector < int > g[maxn];
map < int, int > lst_val;

void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (!used[u]) dfs(u);
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        string s;
        cin >> s;
        pos.clear();
        lst_val.clear();
        n = 2 * n;
        for (int i = 1; i <= n; i++) {
            used[i] = 0, g[i] = {};
            pref[i] = pref[i - 1];
            if (s[i - 1] == '(') pref[i]++;
            else pref[i]--;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            lst_val[pref[i - 1]] = i - 1;
            pos[pref[i - 1]].push_back(i);
            for (int j = 0; j < min(2, (int)pos[pref[i]].size()); j++) {
                if (lst_val.find(pref[i] - 1) == lst_val.end() || lst_val[pref[i] - 1] < pos[pref[i]][pos[pref[i]].size() - j - 1]) {
                    g[i].push_back(pos[pref[i]][pos[pref[i]].size() - j - 1]);
                    g[pos[pref[i]][pos[pref[i]].size() - j - 1]].push_back(i);
                    //cout << i << " " << pos[pref[i]][pos[pref[i]].size() - j - 1] << endl;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                ans++;
                dfs(i);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}