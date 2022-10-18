#include <bits/stdc++.h>
#pragma pack(1)

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string x[n];
    for(int i = 0; i < n; i++)
        cin >> x[i];
    int ans = 0;
    bool used[n];
    memset(used, 0, sizeof(used));
    for(int i = 0; i < m; i++)
    {
        bool ok = 0;
        bool to_used[n];
        memset(to_used, 0, n);
        for(int j = 1; j < n; j++)
        {
            if(x[j][i] > x[j - 1][i]) to_used[j] = 1;
            if(x[j][i] < x[j - 1][i] && !used[j]) ok = 1;
        }
        if(ok) ans++;
        else
            for(int j = 1; j < n; j++)
                used[j] |= to_used[j];
    }
    cout << ans << endl;
    return 0;
}