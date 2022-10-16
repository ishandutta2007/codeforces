#include <iostream>

using namespace std;

const int MAXN = 200 * 1000 + 5;
int a[MAXN], n;
long long g[2 * MAXN], dp[2 * MAXN];

void dfs(int v) {
    int num = v >> 1;
    if(num < 0 || num >= n)
        return;
    if(dp[v] != -3)
        return;
    dp[v] = -2;
    dfs(g[v]);
    int tonum = g[v] >> 1;
    if(0 <= tonum && tonum < n && dp[g[v]] < 0)
        dp[v] = -1;
    else
        dp[v] = (0 <= tonum && tonum < n? dp[g[v]] : 0) + a[v >> 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> a[i];
        g[2 * i] = 2 * (i + a[i]) + 1;
        g[2 * i + 1] = 2 * (i - a[i]);
    }
    for(int i = 0; i < 2 * n; i++)
        dp[i] = -3;
    for(int i = 0; i < 2 * n; i++)
        dfs(i);
    for(int i = 1; i < n; i++)
        cout << (dp[2 * i + 1] == -1? -1 : i + dp[2 * i + 1]) << '\n';
    return 0;
}