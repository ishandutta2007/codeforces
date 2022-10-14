#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector <int> adj[N];
int a[N];
long long tans = 0;

pair <long long, long long> dfs(int v, int pa, int bit) {
    pair <long long, long long> ans = {0, 0}, re = {0, 0};
    for (int u : adj[v]) if (u != pa) {
        pair <long long, long long> tmp = dfs(u, v, bit);
        pair <long long, long long> now = ans;
        now.first = re.first * tmp.first + re.second * tmp.second + tmp.first;
        now.second = re.first * tmp.second + re.second * tmp.first + tmp.second;
        ans.first += now.first;
        ans.second += now.second;
        re.first += tmp.first;
        re.second += tmp.second;
    }
    if (a[v] & (1 << bit)) {
        ans = make_pair(ans.second, ans.first + 1);
        re = make_pair(re.second, re.first + 1);
    } else {
        ans.first++;
        re.first++;
    }
    tans += (1ll << bit) * ans.second;
    return re;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < 20; ++i) {
        dfs(0, -1, i);
    }
    cout << tans << endl;
}