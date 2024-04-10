#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n, m, k;
int a[N], b[N];
int c[N][N];

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cin >> c[i][j];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (c[i][j])
                cout << min(a[i], b[j]) << ' ';
            else
                cout << 0 << ' ';
        }
        cout << endl;
    }
    return 0;
}