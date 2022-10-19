#include <bits/stdc++.h>
using namespace std;
const int N = 102, M = 55;

int n, m;
char a[N][M];

bool c[N];

string ans;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf(" %s", a[i]);
    for (int i = 0; i < n; ++i)
    {
        if (c[i])
            continue;
        for (int j = 0; j < n; ++j)
        {
            if (c[j] || i == j)
                continue;
            bool z = true;
            for (int k = 0; k < m; ++k)
            {
                if (a[i][k] != a[j][m - k - 1])
                {
                    z = false;
                    break;
                }
            }
            if (z)
            {
                c[i] = c[j] = true;
                for (int k = 0; k < m; ++k)
                    ans += a[i][k];
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (c[i])
            continue;
        bool z = true;
        for (int k = 0; k < m; ++k)
        {
            if (a[i][k] != a[i][m - k - 1])
            {
                z = false;
                break;
            }
        }
        if (z)
        {
            string yans = ans;
            for (int k = 0; k < m; ++k)
                yans += a[i][k];
            reverse(ans.begin(), ans.end());
            yans += ans;
            cout << yans.size() << endl;
            cout << yans << endl;
            return 0;
        }
    }
    string yans = ans;
    reverse(ans.begin(), ans.end());
    yans += ans;
    cout << yans.size() << endl;
    cout << yans << endl;
    return 0;
}