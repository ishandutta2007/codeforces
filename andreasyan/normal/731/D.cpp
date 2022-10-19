#include <bits/stdc++.h>
using namespace std;
const int N = 500005;

int n, m;
vector<int> a[N];

int u[N + N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
        }
    }
    for (int i = 1; i < n; ++i)
    {
        bool z = false;
        for (int j = 0; j < a[i].size(); ++j)
        {
            if (j == a[i + 1].size())
            {
                cout << -1 << endl;
                return 0;
            }
            if (a[i][j] != a[i + 1][j])
            {
                int x = a[i][j];
                int y = a[i + 1][j];
                if (x < y)
                {
                    u[0]++;
                    u[m - y + 1]--;
                    u[m - x + 1]++;
                    u[m]--;
                }
                else
                {
                    u[m - x + 1]++;
                    u[m - y + 1]--;
                }
                z = true;
                break;
            }
        }
        if (!z)
        {
            u[0]++;
            u[m]--;
        }
    }
    int g = 0;
    for (int i = 0; i < m; ++i)
    {
        g += u[i];
        if (g == (n - 1))
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}