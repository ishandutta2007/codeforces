#include <bits/stdc++.h>
using namespace std;
const int N = 55, M = 10004;

bool x[M], y[M];
bool c[M];

int n, m;
bool a[N][M];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int s;
        cin >> s;
        while (s--)
        {
            int x;
            cin >> x;
            a[i][x] = true;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            bool z = false;
            for (int k = 0; k < m; ++k)
            {
                if (a[i][k] == true && a[j][k] == true)
                {
                    z = true;
                    break;
                }
            }
            if (!z)
            {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    cout << "possible" << endl;
    return 0;
}