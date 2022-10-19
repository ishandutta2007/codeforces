#include <bits/stdc++.h>
using namespace std;
const int N = 502;

int n;
int a[N][N];
int z[N];

long long ans[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
        cin >> z[i];
    for (int i = n; i >= 1; --i)
    {
        for (int x = 1; x <= n; ++x)
        {
            for (int y = 1; y <= n; ++y)
            {
                a[x][y] = min(a[x][y], a[x][z[i]] + a[z[i]][y]);
            }
        }
        for (int x = i; x <= n; ++x)
        {
            for (int y = i; y <= n; ++y)
            {
                ans[i] += a[z[x]][z[y]];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    return 0;
}