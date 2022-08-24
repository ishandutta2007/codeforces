#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    char c[n][m];
    int mn_i = n, mx_i = 0;
    int mn_j = m, mx_j = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == 'X')
            {
                mn_i = min(mn_i, i);
                mx_i = max(mx_i, i);
                mn_j = min(mn_j, j);
                mx_j = max(mx_j, j);
            }
        }
    }
    bool good = 1;
    for (int x = mn_i; x <= mx_i; x++)
    {
        for (int y = mn_j; y <= mx_j; y++)
        {
            good &= (c[x][y] == 'X');
        }
    }
    cout << (good ? "YES" : "NO") << '\n';
}