#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 110;

int n;
pair<int, int> p[MAX_N];
pair<int, int> d[102][102][3][3];
pair<int, int> dp[102][3];
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

bool check(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int m = n * n;
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < n; e++)
        {
            int a;
            cin >> a;
            a--;
            p[a].first = i;
            p[a].second = e;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int e = 0; e < m; e++)
        {
            for (int t1 = 0; t1 < 3; t1++)
            {
                for (int t2 = 0; t2 < 3; t2++)
                {
                    d[i][e][t1][t2].first = 1000000000;
                    d[i][e][t1][t2].second = 1000000000;
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x = i / n;
        int y = i % n;
        for (int j = 0; j < 8; j++)
        {
            if (check(x + dx[j], y + dy[j]))
            {
                d[i][(x + dx[j]) * n + (y + dy[j])][0][0].first = 1;
                d[i][(x + dx[j]) * n + (y + dy[j])][0][0].second = 0;
            }
        }
        for (int e = 0; e < n; e++)
        {
            if (check(x + e, y + e))
            {
                d[i][(x + e) * n + (y + e)][1][1].first = 1;
                d[i][(x + e) * n + (y + e)][1][1].second = 0;
            }
            if (check(x - e, y + e))
            {
                d[i][(x - e) * n + (y + e)][1][1].first = 1;
                d[i][(x - e) * n + (y + e)][1][1].second = 0;
            }
            if (check(x + e, y - e))
            {
                d[i][(x + e) * n + (y - e)][1][1].first = 1;
                d[i][(x + e) * n + (y - e)][1][1].second = 0;
            }
            if (check(x - e, y - e))
            {
                d[i][(x - e) * n + (y - e)][1][1].first = 1;
                d[i][(x - e) * n + (y - e)][1][1].second = 0;
            }
            d[i][x * n + e][2][2].first = 1;
            d[i][x * n + e][2][2].second = 0;
            d[i][e * n + y][2][2].first = 1;
            d[i][e * n + y][2][2].second = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int t1 = 0; t1 < 3; t1++)
        {
            for (int t2 = 0; t2 < 3; t2++)
            {
                if (t1 == t2)
                {
                    d[i][i][t1][t2].first = 0;
                    d[i][i][t1][t2].second = 0;
                }
                else
                {
                    d[i][i][t1][t2].first = 1;
                    d[i][i][t1][t2].second = 1;
                }
            }
        }
    }
    for (int k = 0; k < m; k++)
    {
        for (int t2 = 0; t2 < 3; t2++)
        {
            for (int t3 = 0; t3 < 3; t3++)
            {
                for (int i = 0; i < m; i++)
                {
                    for (int e = 0; e < m; e++)
                    {
                        for (int t1 = 0; t1 < 3; t1++)
                        {
                            for (int t4 = 0; t4 < 3; t4++)
                            {
                                int cur = d[i][k][t1][t2].first + d[k][e][t3][t4].first;
                                int q = d[i][k][t1][t2].second + d[k][e][t3][t4].second;
                                if (t2 != t3)
                                {
                                    cur++;
                                    q++;
                                }
                                if (make_pair(cur, q) < d[i][e][t1][t4])
                                {
                                    d[i][e][t1][t4].first = cur;
                                    d[i][e][t1][t4].second = q;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int t1 = 0; t1 < 3; t1++)
    {
        dp[0][t1].first = 0;
        dp[0][t1].second = 0;
    }
    for (int i = 1; i < m; i++)
    {
        int a = p[i].first * n + p[i].second;
        int b = p[i - 1].first * n + p[i - 1].second;
        for (int t1 = 0; t1 < 3; t1++)
        {
            dp[i][t1].first = 1000000000;
            dp[i][t1].second = 1000000000;
            for (int t2 = 0; t2 < 3; t2++)
            {
                //cout << a << " " << b << " " << t1 << " " << t2 << " " << d[b][a][t2][t1].first << " " << d[b][a][t2][t1].second << endl;
                dp[i][t1] = min(dp[i][t1], make_pair(dp[i - 1][t2].first + d[b][a][t2][t1].first, dp[i - 1][t2].second + d[b][a][t2][t1].second));
            }
            //cout << i << " " << t1 << " " << dp[i][t1].first << " " << dp[i][t1].second << endl;
        }
    }
    pair<int, int> ans(1000000000, 1000000000);
    for (int t1 = 0; t1 < 3; t1++)
        ans = min(ans, dp[m - 1][t1]);
    cout << ans.first << " " << ans.second;
}