#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

struct AhoCorasick {

    int fail[N];
    int to[N][26];
    int ending[N];
    int sz;
    
    AhoCorasick() {
        sz = 1;
    }

    int add(const string &s) {
        int node = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (!to[node][s[i] - 'a']) {
                to[node][s[i] - 'a'] = ++sz;
            }
            node = to[node][s[i] - 'a'];
        }
        ending[node] = true;
        return node;
    }

    void push() {
        queue<int> Q;
        Q.push(1);
        fail[1] = 1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = 0; i < 26; ++i) {
                int &v = to[u][i];
                if (!v) {
                    v = u == 1 ? 1 : to[fail[u]][i];
                } else {
                    fail[v] = u == 1 ? 1 : to[fail[u]][i];
                    Q.push(v);
                }
            }
        }
    }
} aho;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        pos[i] = aho.add(s);
    }    

    aho.push();

    vector<vector<int>> g(aho.sz + 1);
    for (int i = 2; i <= aho.sz; i++) {
        g[aho.fail[i]].push_back(i);
    }

    vector<int> links(aho.sz + 1);

    function<void(int, int, int)> dfs = [&](int u, int p, int link) {
        links[u] = link;
        if (aho.ending[u] == true) link = u;
        for (int e : g[u]) {
            if (e == p) continue;
            dfs(e, u, link);
        }
    };
    
    dfs(1, -1, -1);

    vector<set<pair<int, int>>> vals(aho.sz + 1);
    vector<int> val(n + 1);

    for (int i = 1; i <= n; i++) {
        vals[pos[i]].insert(make_pair(val[i], i));
    }

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, x;
            cin >> i >> x;
            vals[pos[i]].erase(make_pair(val[i], i));
            val[i] = x;
            vals[pos[i]].insert(make_pair(val[i], i));
        } else {
            string q;
            cin >> q;
            int cur = 1;
            int res = -1;
            for (char ch : q) {
                cur = aho.to[cur][ch - 'a'];
                int u = cur;
                if (aho.ending[u]) res = max(res, vals[u].rbegin()->first);
                while (links[u] != -1) {
                    u = links[u];
                    res = max(res, vals[u].rbegin()->first);
                }
            }
            cout << res << '\n';
        }
    }


    return 0;
}