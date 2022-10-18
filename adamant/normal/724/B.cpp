#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 0; i < m; i++)
        for(int j = i; j < m; j++)
        {
            for(int k = 0; k < n; k++)
                swap(a[k][i], a[k][j]);
            for(int k = 0; k < n; k++)
            {
                int cnt = 0;
                for(int l = 0; l < m; l++)
                    if(a[k][l] != l + 1)
                        cnt++;
                if(cnt > 2)
                    goto nxt;
            }
            cout << "YES\n";
            return 0;
            nxt:;
            for(int k = 0; k < n; k++)
                swap(a[k][i], a[k][j]);
        }
    cout << "NO\n";
    return 0;
}