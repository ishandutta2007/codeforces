#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int maxn = 1e5 + 42;

int s[maxn];
int a[maxn];

void fail() {
    cout << -1 << endl;
    exit(0);
}

vector<int> g[maxn];

void dfs(int v = 0, int p = 0, int h = 1) {
    if(h % 2 == 1 && s[v] == -1) {
        fail();
    } else if(h % 2 == 0 && s[v] != -1) {
        fail();
    }
    if(v == 0) {
        a[v] = s[v];
    } else if(h % 2 == 0) {
        a[v] = 1e15;
        if(g[v].empty()) {
            a[v] = 0;
        }
        for(auto u: g[v]) {
            a[v] = min(a[v], s[u] - s[p]);
        }
        s[v] = s[p] + a[v];
    } else {
        a[v] = s[v] - s[p];
    }
    if(a[v] < 0) {
        fail();
    }
    for(auto u: g[v]) {
        dfs(u, v, h + 1);
    }
    
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int p[n];
    for(int i = 1; i < n; i++) {
        cin >> p[i];
        g[p[i] - 1].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    dfs();
    int ans = accumulate(a, a + n, 0LL);
    cout << ans << endl;
    return 0;
}