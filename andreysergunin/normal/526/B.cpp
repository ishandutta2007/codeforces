#include <bits/stdc++.h>

using namespace std;
const int MAXN = 300000;
int n, m;
int a[MAXN];
long long ans;

int dfs(int v)
{
    int p, q;
    if (v >= m)
        return 0;

    p = a[2 * v] + dfs(2 * v);
    q = a[2 * v + 1] + dfs(2 * v + 1);
    ans += abs(p - q);
    return max(p, q);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    m = 1 << n;
    for (int i = 2; i < 2 * m; i++)
        cin >> a[i];
    ans = 0;
    int t = dfs(1);
    cout << ans;
    return 0;
}