#include <bits/stdc++.h>

using namespace std;

vector < int > g[5001];

int isi[5001];
int isi1[5001];
int pt = 0;

void dfs(int v){
    isi[v] = 1;
    for (auto u : g[v]){
        if (isi[u] == 0)
            dfs(u);
    }
}

int dfs1(int v){
    isi1[v] = 1;
    pt++;
    for (auto u : g[v]){
        if (isi1[u] == 0)
            dfs1(u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, s, x, y;
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i){
        cin >> x >> y;
        g[x].push_back(y);
    }
    dfs(s);
    for (int i = 0; i < 5001; ++i)
        isi1[i] = isi[i];
    vector < pair < int, int > > prom;
    for (int i = 1; i <= n; ++i){
        if (isi[i] == 0){
            for (int j = 0; j < 5001; ++j)
            isi1[j] = 0;
            pt = 0;
            dfs1(i);
            prom.push_back({pt, i});
        }
    }
    int ans = 0;
    sort(prom.begin(), prom.end());
    for (int i = prom.size() - 1; i >= 0; --i){
        if (isi[prom[i].second] == 0){
            ans++;
            dfs(prom[i].second);
        }
    }
    cout << ans << endl;
}