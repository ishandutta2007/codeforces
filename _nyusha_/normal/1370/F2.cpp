#include<bits/stdc++.h>

using namespace std;

vector < int > g[1005];
vector < int > h[1005];
int lst[1005];

pair < int, int > ask(vector < int > a) {
    cout << "? ";
    cout << a.size() << " ";
    for (auto key : a) cout << key << " ";
    cout << endl;
    int u, s;
    cin >> u >> s;
    return {u, s};
}

void dfs(int v, int p, int H) {
    lst[v] = p;
    h[H].push_back(v);
    for (auto u : g[v]) if (u != p) dfs(u, v, H + 1);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, u, v;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i <= n; ++i) g[i] = {}, h[i] = {};
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector < int > a = {};
        for (int i = 1; i <= n; ++i) a.push_back(i);
        pair < int, int > cur = ask(a);
        int root = cur.first, s = cur.second;
        dfs(root, -1, 0);
        int mx = 0;
        for (int i = 0; i <= n; ++i) if ((int)h[i].size() > 0) mx = i;
        int lef = max(-1, s / 2 - 2), righ = min(mx + 1, s + 2);
        int answer = -1;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            cur = ask(h[mid]);
            if (cur.second == s) answer = cur.first, lef = mid;
            else righ = mid;
        }
        assert(answer != -1);
        int two = s - lef;
        vector < int > q;
        set < int > bad;
        int node = answer;
        while (node != -1) {
            bad.insert(node);
            node = lst[node];
        }
        for (auto key : h[two]) {
            if (bad.find(key) == bad.end() || key == root) q.push_back(key);
        }
        cur = ask(q);
        assert(cur.second == s);
        cout << "! " << answer << " " << cur.first << endl;
        string S;
        cin >> S;
    }
    return 0;
}