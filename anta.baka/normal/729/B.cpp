#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int a[1000][1000];
int u[1000][1000];
int d[1000][1000];
int l[1000][1000];
int r[1000][1000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 0; i < n; i++)
    {
        l[i][0] = (a[i][0] == 1);
        r[i][m-1] = (a[i][m-1] == 1);
    }
    for(int j = 0; j < m; j++)
    {
        u[0][j] = (a[0][j] == 1);
        d[n-1][j] = (a[n-1][j] == 1);
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(i)
                u[i][j] = u[i-1][j] + (a[i][j] == 1);
            if(j)
                l[i][j] = l[i][j-1] + (a[i][j] == 1);
        }
    for(int i = n-1; i >= 0; i--)
        for(int j = m-1; j >= 0; j--)
        {
            if(i+1 < n)
                d[i][j] = d[i+1][j] + (a[i][j] == 1);
            if(j+1 < m)
                r[i][j] = r[i][j+1] + (a[i][j] == 1);
        }
    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == 0)
                res += (r[i][j] > 0) + (l[i][j] > 0) + (d[i][j] > 0) + (u[i][j] > 0);
    cout << res;
}