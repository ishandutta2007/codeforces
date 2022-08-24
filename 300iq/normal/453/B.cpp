#include <bits/stdc++.h>

using namespace std;

bool prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return (x > 1);
}

const int N = 100 + 7;
const int LIM = (1 << 17);
int dp[N][LIM];
int pr[N][LIM];
int num[N][LIM];

int main()
{
    vector <int> arr;
    for (int i = 1; i <= 60; i++)
    {
        if (prime(i))
        {
            arr.push_back(i);
        }
    }
    vector <int> kek(61);
    for (int i = 1; i <= 60; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if (i % arr[j] == 0)
            {
                kek[i] |= (1 << j);
            }
        }
    }
    int lim = (1 << 17);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < lim; j++)
        {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int mask = 0; mask < lim; mask++)
        {
            for (int cur = 1; cur <= 60; cur++)
            {
                int lel = kek[cur];
                if (!(lel & mask))
                {
                    if (dp[i][mask] == 1e9)
                    {
                        continue;
                    }
                    if (dp[i][mask] + abs(a[i] - cur) < dp[i + 1][mask | lel])
                    {
                        pr[i + 1][mask | lel] = mask;
                        num[i + 1][mask | lel] = cur;
                        dp[i + 1][mask | lel] = dp[i][mask] + abs(a[i] - cur);
                    }
                }
            }
        }
    }
    int msk = -1;
    for (int mask = 0; mask < lim; mask++)
    {
        if (msk == -1 || dp[n][msk] > dp[n][mask])
        {
            msk = mask;
        }
    }
    vector <int> res;
    int cur = n, m = msk;
    while (cur)
    {
        res.push_back(num[cur][m]);
        m = pr[cur][m];
        cur--;
    }
    reverse(res.begin(), res.end());
    for (auto c : res)
    {
        cout << c << ' ';
    }
}