#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 2e5 + 42;

int used[maxn], pre[maxn];
vector<int> g[maxn];

void add_edge(int u, int v) {
    g[2 * u].push_back(2 * v + 1);
    g[2 * u + 1].push_back(2 * v);
}

bool draw_pos = 0;

void dfs(int v) {
    used[v] = 1;
    for(auto u: g[v]) {
        if(!used[u]) {
            pre[u] = v;
            dfs(u);
        } else if(used[u] == 1) {
            draw_pos = true;
        }
    }
    used[v] = 2;
}



signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        for(int j = 0; j < c; j++) {
            int v;
            cin >> v;
            add_edge(i, v - 1);
        }
    }
    int s;
    cin >> s;
    dfs(2 * (s - 1));
    for(int i = 1; i < maxn; i += 2) {
        if(used[i] && g[i].empty()) {
            cout << "Win" << endl;
            vector<int> ans;
            int cur = i;
            while(cur != 2 * (s - 1)) {
                ans.push_back(cur / 2);
                cur = pre[cur];
            }
            ans.push_back(s - 1);
            reverse(begin(ans), end(ans));
            for(auto it: ans) {
                cout << it + 1 << ' ';
            }
            return 0;
        }
    }
    cout << (draw_pos ? "Draw" : "Lose") << endl;
    return 0;
}