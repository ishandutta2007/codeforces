#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> ban;
set<int> vv;

void dfs(int v) {
    vector<int> too;
    for(int to : vv)
        if(ban.find({v, to}) == ban.end() && ban.find({to, v}) == ban.end())
            too.push_back(to);
    for(int to : too)
        vv.erase(to);
    for(int to : too)
        dfs(to);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    int hi = n - 1;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        ban.insert({u, v});
        if(!u || !v)
            hi--;
    }
    for(int i = 1; i < n; i++)
        vv.insert(i);
    int lo = 0;
    for(int i = 1; i < n; i++)
        if(vv.find(i) != vv.end() && ban.find({i, 0}) == ban.end() && ban.find({0, i}) == ban.end()) {
            vv.erase(i);
            dfs(i);
            lo++;
        }
    cout << (vv.empty() && lo <= k && k <= hi ? "possible" : "impossible");
}