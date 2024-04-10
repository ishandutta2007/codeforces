#include <bits/stdc++.h>

using namespace std;
#define link alflak
#define fpos ladla
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

#define int int64_t
const int mod = 998244353;

const int maxn = 1e5 + 42;

vector<int> g[maxn];
int p[maxn];
int h[maxn];

void dfs(int v = 0) {
    for(auto u: g[v]) {
        if(u != p[v]) {
            p[u] = v;
            h[u] = h[v] + 1;
            dfs(u);
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    int mx = 0;
    for(int i = 1; i < n; i++) {
        if(h[i] > h[mx]) {
            mx = i;
        }
    }
    memset(p, 0, sizeof(p));
    memset(h, 0, sizeof(h));
    p[mx] = mx;
    dfs(mx);
    int mx2 = 0;
    for(int i = 0; i < n; i++) {
        if(h[i] > h[mx2]) {
            mx2 = i;
        }
    }
    vector<int> path;
    while(mx2 != mx) {
        path.push_back(mx2);
        mx2 = p[mx2];
    }
    path.push_back(mx2);
    if(path.size() % 2 == 0) {
        cout << "No" << endl;
    } else {
        int order = path.size() / 2;
        int root = path[path.size() / 2];
        memset(p, 0, sizeof(p));
        memset(h, 0, sizeof(h));
        p[root] = root;
        dfs(root);
        bool hedgehog = k == order;
        for(int i = 0; i < n; i++) {
            if(i == root) {
                hedgehog &= g[i].size() >= 3;
            } else if(g[i].size() == 1) {
                hedgehog &= h[i] == order;
            } else {
                hedgehog &= g[i].size() >= 4;
            }
        }
        if(hedgehog) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}