#include <bits/extc++.h>

using namespace std;

void fail() {
    cout << "No" << endl;
    exit(0);
}

const int maxn = 1e5 + 42;
vector<int> g[2 * maxn], gt[2 * maxn];

int nrm(int x) {
    return x < maxn ? x : -(x - maxn);
}

void add_edge(int u, int v) {
    g[u].push_back(v);
    gt[v].push_back(u);
}

int used[2 * maxn];

void dfs(int v, vector<int> *g, vector<int> &st) {
    if(used[v]) {
        return;
    }
    used[v] = 1;
    for(auto u: g[v]) {
        dfs(u, g, st);
    }
    st.push_back(v);
}

int in_comp[2 * maxn];

void try2sat(int m) {
    vector<int> topsort;
    for(int i = 1; i < 2 * maxn; i++) {
        dfs(i, g, topsort);
    }
    reverse(begin(topsort), end(topsort));
    memset(used, 0, sizeof(used));
    int cnt = 0;
    for(auto v: topsort) {
        if(used[v]) {
            continue;
        }
        cnt++;
        vector<int> comp;
        dfs(v, gt, comp);
        for(auto u: comp) {
            in_comp[u] = cnt;
        }
    }
    vector<int> ans;
    for(int i = 1; i <= m; i++) {
        if(in_comp[i] == in_comp[i + maxn]) {
            fail();
        } else if(in_comp[i] > in_comp[i + maxn]) {
            ans.push_back(i);
        }
    }
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for(auto it: ans) {
        cout << it << ' ';
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> words[n];
    
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        words[i].resize(k);
        bool mismatch = false;
        for(int j = 0; j < k; j++) {
            cin >> words[i][j];
            if(i > 0 && !mismatch && j < words[i - 1].size()) {
                if(words[i][j] != words[i - 1][j]) {
                    mismatch = true;
                    if(words[i][j] < words[i - 1][j]) {
                        add_edge(maxn + words[i - 1][j], words[i - 1][j]);
                        add_edge(words[i][j], maxn + words[i][j]);
                    } else {
                        add_edge(words[i][j], words[i - 1][j]);
                        add_edge(maxn + words[i - 1][j], maxn + words[i][j]);
                    }
                }
            }
        }
        if(i > 0 && !mismatch && words[i].size() < words[i - 1].size()) {
            fail();
        }
    }
    try2sat(m);
    return 0;
}