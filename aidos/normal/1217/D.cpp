#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 998244353;
const int inf = (1<<30) - 1;
int n, m;

vector<int>g[maxn];
int c[maxn];
int ans[maxn];
pair<int, int> e[maxn];
void dfs(int v) {
    c[v] = 1;
    for(int id: g[v]) {
        int to = e[id].second;
        if(c[to] == 0) {
            dfs(to);
            ans[id] = 1;
        } else {
            ans[id] = 3 - c[to];
        }
    }
    c[v] = 2;
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> e[i].first >> e[i].second;
        g[e[i].first].emplace_back(i);
    }

    for(int i = 1; i <= n; i++) {
        if(c[i] == 0) dfs(i);
    }
    cout << *max_element(ans, ans + m) << "\n";
    for(int i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}