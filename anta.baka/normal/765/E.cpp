#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5 + 7;

int n;
vector<int> g[N];
int root;
bool found = false;
int len[N];

void dfs1(int v, int prev = -1) {
    if(g[v].size() == 1)
        return;
    vector<int> p;
    for(int to : g[v])
        if(to != prev) {
            dfs1(to, v);
            if(found)
                return;
            p.push_back(len[to] + 1);
        }
    sort(p.begin(), p.end());
    int sz = unique(p.begin(), p.end()) - p.begin();
    if(sz > 2) {
        cout << -1;
        exit(0);
    }
    if(sz == 2) {
        root = v;
        found = true;
    } else
        len[v] = p[0];
}

vector<int> proot;

void dfs2(int v, int prev = -1) {
    if(g[v].size() == 1)
        return;
    vector<int> p;
    for(int to : g[v])
        if(to != prev) {
            dfs2(to, v);
            p.push_back(len[to] + 1);
        }
    sort(p.begin(), p.end());
    int sz = unique(p.begin(), p.end()) - p.begin();
    if(v == root) {
        for(int i = 0; i < sz; i++)
            proot.push_back(p[i]);
        return;
    }
    if(sz > 1) {
        cout << -1;
        exit(0);
    }
    len[v] = p[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    if(n == 2)
        return cout << 1, 0;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; i++)
        if(g[i].size() > 1) {
            root = i;
            break;
        }
    memset(len, 0, sizeof len);
    dfs1(root);
    memset(len, 0, sizeof len);
    dfs2(root);
    int sz = proot.size();
    if(sz > 2)
        return cout << -1, 0;
    int len = proot[0];
    if(sz > 1)
        len += proot[1];
    while(len % 2 == 0)
        len /= 2;
    cout << len;
}