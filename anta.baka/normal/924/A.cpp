#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 2e5, INF = 1e9;

char a[50][50];
vector<int> g[100];
int n, m;
vector<int> vi, vj;
vector<bool> was;

void dfs(int v) {
    was[v] = true;
    if(v < n) vi.push_back(v);
    else vj.push_back(v - n);
    for(int to : g[v]) if(!was[to]) dfs(to);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(a[i][j] != '#') continue;
            g[i].push_back(j + n);
            g[j + n].push_back(i);
            for(int i1 = i + 1; i1 < n; i1++)
                if(a[i1][j] == '#') {
                    g[i].push_back(i1);
                    g[i1].push_back(i);
                    break;
                }
            for(int j1 = j + 1; j1 < m; j1++)
                if(a[i][j1] == '#') {
                    g[j + n].push_back(j1 + n);
                    g[j1 + n].push_back(j + n);
                    break;
                }
        }
    was.assign(n + m, false);
    for(int u = 0; u < n + m; u++)
        if(!was[u]) {
            vi.clear();
            vj.clear();
            dfs(u);
            for(int i : vi)
                for(int j : vj)
                    if(a[i][j] != '#')
                        return cout << "No", 0;
        }
    cout << "Yes";
}