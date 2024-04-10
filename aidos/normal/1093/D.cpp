#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)998244353;
const int inf = (1<<30) - 1;
int n, m;
vector<int> g[maxn];
int u[maxn];
int col[maxn];
ll c[3];
int good;
void dfs(int v, int cur) {
    c[cur] = (c[cur] * 2) % mod;
    u[v] = 1;
    col[v] = cur;
    for(const int &to: g[v]) {
        if(!u[to])dfs(to, 1-cur);
        else if(col[to] == col[v]) good = 0;
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n;i++) {
        g[i].clear();
        u[i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        if(u[i]) continue;
        c[0] = c[1] = 1;
        good = 1;
        dfs(i, 0);
        ans = (ans * (c[0] + c[1]) * good) % mod;
    }
    cout << ans << "\n";
}


int main() {
    int t = 1;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}