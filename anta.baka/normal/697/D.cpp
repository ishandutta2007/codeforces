#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
int p[N], cnt[N];
vector<int> g[N];
double ans[N];

void dfs(int v) {
    cnt[v] = 1;
    for(int i = 0, sz=(int)g[v].size(); i < sz; i++)
        dfs(g[v][i]), cnt[v] += cnt[g[v][i]];
}

void solve(int v) {
    if(v)
        ans[v] = ans[p[v]] + 1 + (cnt[p[v]] - cnt[v] - 1) / 2.0;
    for(int i = 0, sz=(int)g[v].size(); i < sz; i++)
        solve(g[v][i]);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
        cin >> p[i], p[i]--, g[p[i]].push_back(i);
    dfs(0);
    ans[0] = 1.0;
    solve(0);
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    return 0;
}