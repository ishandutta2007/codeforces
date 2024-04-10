#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 5,  MOD = 998244353;

long long n;
long long a[N];
long long dp[N][5];
char ch[6] = {'#', 'h', 'a', 'r', 'd', '#'};

int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin>>n>>s;
    s = "#" + s;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 4; j++)
            if (ch[j] == s[i]){
                dp[i][j - 1] = dp[i - 1][j - 1] + a[i];
                if (j >= 2)
                    dp[i][j - 1] = min (dp[i][j - 1], dp[i - 1][j - 2]);
            }
            else
                dp[i][j - 1] = dp[i - 1][j - 1];
    }
    long long x = dp[n][0];
    for (int i = 1; i <= 3; i++)
        x = min (x, dp[n][i]);
    cout<<x<<endl;
    return 0;
}