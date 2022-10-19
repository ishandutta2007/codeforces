#include <bits/stdc++.h>
using namespace std;
const int N = 502;

int n, m;
int a[N][N];

int b[N][2];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int k = 0; k < 20; ++k)
    {
        memset(b, 0, sizeof b);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if ((a[i][j] & (1 << k)))
                    b[i][1] = j;
                else
                    b[i][0] = j;
            }
        }
        int z = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (b[i][0])
                continue;
            z ^= 1;
        }
        if (z == 1)
        {
            cout << "TAK" << endl;
            for (int i = 1; i <= n; ++i)
            {
                if (b[i][0])
                {
                    cout << b[i][0] << ' ';
                }
                else
                {
                    cout << b[i][1] << ' ';
                }
            }
            cout << endl;
            return 0;
        }
        else
        {
            bool f = false;
            for (int i = 1; i <= n; ++i)
            {
                if (b[i][0] && b[i][1])
                    f = true;
            }
            if (!f)
                continue;
            cout << "TAK" << endl;
            for (int i = 1; i <= n; ++i)
            {
                if (b[i][0] && b[i][1] && !z)
                {
                    cout << b[i][1] << ' ';
                    z = 1;
                    continue;
                }
                if (b[i][0])
                {
                    cout << b[i][0] << ' ';
                }
                else
                {
                    cout << b[i][1] << ' ';
                }
            }
            cout << endl;
            return 0;
        }
    }
    cout << "NIE" << endl;
    return 0;
}