#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n, m, i, j, ans, k, l;
    char a[200][200];
    int c[200];
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];

    ans = 0;
    for (i = 0; i < n - 1; i++)
        c[i] = 0;
    for (j = 0; j < m; j++)
    {
        bool f = true;
        for (i = 0; i < n - 1; i++)
        {
            if (a[i][j] > a[i + 1][j] && c[i] == 0)
                f = false;
        }
        if (!f)
            ans++;
        else
        {
            for (i = 0; i < n - 1; i++)
                if (a[i][j] < a[i + 1][j])
                    c[i] = 1;
        }
    }
    cout << ans;
}