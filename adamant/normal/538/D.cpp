#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string x[n];
    for(int i = 0; i < n; i++)
        cin >> x[i];
    vector<string> ans(2 * n - 1, string(2 * n - 1, '.'));
    bool cover[n][n];
    memset(cover, 0, sizeof(cover));
    for(int i = 0; i < 2 * n - 1; i++)
        for(int j = 0; j < 2 * n - 1; j++)
        {
            bool mb = 0;
            bool nmb = 0;
            for(int i2 = 0; i2 < n; i2++)
                for(int j2 = 0; j2 < n; j2++)
                {
                    if(x[i2][j2] == 'o')
                    {
                        int ni = i2 + i - n + 1;
                        int nj = j2 + j - n + 1;
                        if(ni >= 0 && ni < n && nj >= 0 && nj < n)
                        {
                            mb |= x[ni][nj] == 'x';
                            nmb |= x[ni][nj] == '.';
                        }
                    }
                }
            if(nmb)
                continue;

            for(int i2 = 0; i2 < n; i2++)
                for(int j2 = 0; j2 < n; j2++)
                {
                    if(x[i2][j2] == 'o')
                    {
                        int ni = i2 + i - n + 1;
                        int nj = j2 + j - n + 1;
                        if(ni >= 0 && ni < n && nj >= 0 && nj < n)
                        {
                            mb |= x[ni][nj] == 'x';
                            cover[ni][nj] = 1;
                            nmb |= x[ni][nj] == '.';
                        }
                    }
                }
            if(mb)
                ans[i][j] = 'x';
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(cover[i][j] == 0 && x[i][j] == 'x')
            {
                cout << "NO";
                return 0;
            }
        }
    ans[n - 1][n - 1] = 'o';
    cout << "YES" << endl;
    for(int i = 0; i < 2 * n - 1; i++)
        cout << ans[i] << endl;
}