#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector <int> adj[N];
int depth[N]{};
int cnt[N]{};

void dfs(int v, int pa) {
    depth[v] = ~pa ? depth[pa] + 1 : 0;
    cnt[depth[v]]++;
    for (int u : adj[v]) if (u ^ pa) {
        dfs(u, v);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> p, p--;
        adj[p].push_back(i + 1);
    }
    dfs(0, -1);
    int ans = 0;
    for (int i = 0; i < N; ++i) ans += cnt[i] & 1;
    cout << ans << endl;
}