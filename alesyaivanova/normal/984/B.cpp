#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int f[n][m];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int e = 0; e < m; e++)
        {
            if (s[e] == '*')
                f[i][e] = -1;
            else if (s[e] == '.')
                f[i][e] = 0;
            else
                f[i][e] = s[e] - '0';
        }
    }
    int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};
    int q[n][m] = {};
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < m; e++)
        {
            if (f[i][e] == -1)
            {
                q[i][e] = -1;
                for (int k = 0; k < 8; k++)
                {
                    if (i + dx[k] >= 0 && i + dx[k] < n && e + dy[k] >= 0 && e + dy[k] < m && q[i + dx[k]][e + dy[k]] != -1)
                        q[i + dx[k]][e + dy[k]]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < m; e++)
        {
            if (q[i][e] != f[i][e])
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}