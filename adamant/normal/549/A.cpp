#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < m - 1; j++)
    {
        string x;
        x += a[i][j];
        x += a[i + 1][j + 1];
        x += a[i + 1][j];
        x += a[i][j + 1];
        sort(x.begin(), x.end());
        ans += x == "acef";
    }
    cout << ans << "\n";
}