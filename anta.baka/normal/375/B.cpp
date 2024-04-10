#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[5000][5000];
int dp[5000][5000];
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == '1')
            {
                dp[i][j] = 1;
                if(j) dp[i][j] += dp[i][j - 1];
            }
        }
    for(int j = 0; j < m; j++)
    {
        vector<int> cnt(5001, 0);
        for(int i = 0; i < n; i++) cnt[dp[i][j]]++;
        int tot = 0;
        for(int i = 5000; i; i--)
        {
            tot += cnt[i];
            ans = max(ans, tot * i);
        }
    }
    cout << ans;
}