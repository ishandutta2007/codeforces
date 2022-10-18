#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int c[n];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    int dp[k + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
    {
        int tdp[k + 1][k + 1];
        memcpy(tdp, dp, sizeof(dp));
        for(int a = 0; a < k; a++)
            for(int b = 0; b < k; b++)
            {
                if(a + c[i] <= k)
                    tdp[a + c[i]][b] |= dp[a][b];
                if(a + c[i] <= k && b + c[i] <= k)
                    tdp[a + c[i]][b + c[i]] |= dp[a][b];
            }
        memcpy(dp, tdp, sizeof(dp));
    }
    vector<int> ans;
    for(int i = 0; i <= k; i++)
        if(dp[k][i])
            ans.push_back(i);
    cout << ans.size() << "\n";
    for(auto it: ans)
        cout << it << ' ';
	return 0;
}