#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>
#include <queue>
#include <random>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;
const int N = 3e5;
vector<int> g[N];
bool used[N];
int cnt = 0;
void dfs(int u) {
    used[u] = 1;
    cnt++;
    for(int v : g[u]) if(!used[v]) dfs(v);
}
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //ifstream cin("in.txt");
    int n , m;
    cin >> n >> m;
    int rs = m;
    for(int i = 0; i < m; i++) {
        int u , v;
        cin >> u >> v;
        u-- , v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            cnt = 0;
            rs++;
            dfs(i);
            rs -= cnt;
        }
    }
    cout << rs << "\n";
    
}