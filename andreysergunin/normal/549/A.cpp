#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    char a[MAXN][MAXN];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++)
        {
            char p[5];
            p[0] = a[i][j];
            p[1] = a[i][j + 1];
            p[2] = a[i + 1][j];
            p[3] = a[i + 1][j + 1];
            sort(p, p + 4);
            if (p[0] == 'a' && p[1] == 'c' && p[2] == 'e' && p[3] == 'f')
                ans++;
        }
    cout << ans;
    return 0;
}