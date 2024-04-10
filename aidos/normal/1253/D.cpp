#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9+7;
const int inf = (1<<30) - 1;

int n, m;
vector<int> g[maxn];
int used[maxn];
int dfs(int v) {
    int mx = v;
    used[v] = true;
    for(const int &to: g[v]) {
        if(!used[to]) mx = max(mx, dfs(to));
    }
    return mx;
}
void solve() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int l = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(used[i]) continue;
        if(l >= i) {
            ans++;
        }
        l = max(dfs(i), l);
    }
    cout << ans << "\n";
}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}