#include <bits/stdc++.h>
using namespace std;
const int N = 50004, m = 102, INF = 100000008;

int n;
char a[N];
int h[N][26];

int dp[N][m];
int main()
{
    cin >> a;
    n = strlen(a);

    for (int j = 0; j < 26; ++j)
        h[n][j] = INF;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < 26; ++j)
        {
            h[i][j] = h[i + 1][j];
        }
        h[i][a[i] - 'a'] = i;
    }

    dp[n][1] = INF;
    for (int i = n - 1; i >= 0; --i)
    {
        dp[i][1] = i;
    }

    dp[n][2] = INF;
    for (int i = n - 1; i >= 0; --i)
    {
        dp[i][2] = min(dp[i + 1][2], h[i + 1][a[i] - 'a']);
    }

    for (int k = 3; k < m; ++k)
    {
        dp[n][k] = INF;
        for (int i = n - 1; i >= 0; --i)
        {
            dp[i][k] = dp[i + 1][k];
            if (dp[i + 1][k - 2] != INF)
                dp[i][k] = min(dp[i][k], max(dp[i + 1][k - 2], h[dp[i + 1][k - 2] + 1][a[i] - 'a']));
        }
    }

    for (int k = 100; k >= 1; --k)
    {
        if (dp[0][k] != INF)
        {
            if (k == 1)
            {
                cout << a[0] << endl;
                return 0;
            }
            vector<char> v;
            int i = 0;
            while (1)
            {
                while (dp[i + 1][k] == dp[i][k])
                    ++i;
                v.push_back(a[dp[i][k]]);
                ++i;
                k -= 2;
                if (k == 0)
                {
                    for (int i = 0; i < v.size(); ++i)
                        cout << v[i];
                    for (int i = v.size() - 1; i >= 0; --i)
                        cout << v[i];
                    cout << endl;
                    break;
                }
                else if (k == 1)
                {
                    for (int i = 0; i < v.size(); ++i)
                        cout << v[i];
                    cout << a[dp[i][k]];
                    for (int i = v.size() - 1; i >= 0; --i)
                        cout << v[i];
                    cout << endl;
                    break;
                }
            }
            return 0;
        }
    }
    return 0;
}