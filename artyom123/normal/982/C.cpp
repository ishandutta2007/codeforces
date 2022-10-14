#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

vector <vector<int>> g;
vector <int> p;
int ans = 0;
int dfs(int v, vector <bool> &usd) {
    usd[v] = true;
    int sum = 0;
    for (auto &to : g[v]) {
        if (!usd[to]) {
            sum += dfs(to, usd);
            if (p[to] % 2 == 0) {
                ans++;
            }
        }
    }
    p[v] = sum + 1;
    return p[v];
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << -1;
        return 0;
    }
    g.resize(n);
    p.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    vector <bool> usd(n);
    for (int i = 0; i < n; i++) {
        if (!usd[i]) {
            int now = dfs(i, usd);
        }
    }
    cout << ans;
    return 0;
}