#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
const int M = 1000000007;

int n, m;
int a[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        for (int j = 1; j <= x; ++j)
            a[i][j] = 1;
        a[i][x + 1] = 2;
    }
    for (int j = 1; j <= m; ++j)
    {
        int x;
        scanf("%d", &x);
        for (int i = 1; i <= x; ++i)
        {
            if (a[i][j] == 2)
            {
                cout << 0 << endl;
                return 0;
            }
            a[i][j] = 1;
        }
        if (a[x + 1][j] == 1)
        {
            cout << 0 << endl;
            return 0;
        }
        a[x + 1][j] = 2;
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (!a[i][j])
                ans = (ans + ans) % M;
        }
    }
    cout << ans << endl;
    return 0;
}