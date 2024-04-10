#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 70, msz = 1 << 10, maxd = 10;

/*
 * 1.  - 1
 * 2.  
 * 3. 
 * 4.  
 */

int dp[maxd][maxd][maxn][msz];

void calc_dp()
{
    for(int i = 1; i < maxd; i++)
    {
        dp[i][0][0][0] = 1;
        for(int j = 1; j < maxn; j++)
        {
            for(int a = 0; a <= i; a++)
                for(int b = 0; b <= i; b++)
                for(int msk = 0; msk < msz; msk++)
                {
                    dp[i][b][j][msk ^ (1 << b)] += dp[i][a][j - 1][msk];
                }
        }
    }
}

int get(int m, int x)
{
    vector<int> d;
    while(x)
    {
        d.push_back(x % m);
        x /= m;
    }
    reverse(begin(d), end(d));
    
    //for(auto it: d)
    //{
    //    cout << it << ' ';
    //}
    //cout << endl;
    int mask = 0, ans = 0;
    for(int i = 0; i < d.size(); i++)
    {
        for(int j = 0; j < d[i] + (i + 1 == d.size()); j++)
        {
            //cout << "last_d " << j << " ln " << i << " contrib " << dp[m - 1][j][i][0] << endl;
            if(i == 0 && j == 0)
                continue;
            ans += dp[m - 1][j][d.size() - i][mask];
        }
        if(i)
        for(int j = 1; j < m; j++)
        {
            //cout << "last_d " << j << " len " << i << " contrib " << dp[m - 1][j][i][0] << endl;
            ans += dp[m - 1][j][i][0];
        }
        mask ^= 1 << d[i];
    }
    //cout << ans << endl;
    return ans;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    calc_dp();
    int q;
    cin >> q;
    while(q--)
    {
        int b, l, r;
        cin >> b >> l >> r;
        cout << get(b, r) - get(b, l - 1) << "\n";
    }
    return 0;
}