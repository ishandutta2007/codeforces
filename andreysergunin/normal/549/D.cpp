#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    string a[MAXN];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[MAXN][MAXN];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
        {
            if (a[i][j] == 'W')
            {
                if (b[i][j] != 1)
                {
                    ans++;
                    int u = b[i][j] - 1;
                    for (int k = 0; k <= i; k++)
                        for (int l = 0; l <= j; l++)
                            b[k][l] -= u;
                }
            }
            if (a[i][j] == 'B')
            {
                if (b[i][j] != -1)
                {
                    ans++;
                    int u = b[i][j] + 1;
                    for (int k = 0; k <= i; k++)
                        for (int l = 0; l <= j; l++)
                            b[k][l] -= u;
                }
            }
        }
    cout << ans;
    return 0;
}