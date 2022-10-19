#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 720, M = 1000000007;

int n;
char a[N];

int u[N];

int dp[N][N][3][3];

void rec(int l, int r)
{
    if (l + 1 == r)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i && j)
                    continue;
                if (i == 0 && j == 0)
                    continue;
                dp[l][r][i][j]++;
            }
        }
        return;
    }
    vector<pair<int, int> > v;
    int x = l;
    while (x <= r)
    {
        v.push_back(m_p(x, u[x]));
        x = u[x] + 1;
    }
    if (v.size() == 1)
    {
        rec(l + 1, r - 1);
        for (int i0 = 0; i0 < 3; ++i0)
        {
            for (int i3 = 0; i3 < 3; ++i3)
            {
                if (i0 && i3)
                    continue;
                if (i0 == 0 && i3 == 0)
                    continue;
                for (int i1 = 0; i1 < 3; ++i1)
                {
                    for (int i2 = 0; i2 < 3; ++i2)
                    {
                        if (i0 == 1 && i1 == 1)
                            continue;
                        if (i2 == 1 && i3 == 1)
                            continue;
                        if (i0 == 2 && i1 == 2)
                            continue;
                        if (i2 == 2 && i3 == 2)
                            continue;
                        dp[l][r][i0][i3] = (dp[l][r][i0][i3] + dp[l + 1][r - 1][i1][i2]) % M;
                    }
                }
            }
        }
        return;
    }
    for (int i = 0; i < v.size(); ++i)
        rec(v[i].first, v[i].second);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            dp[l][r][i][j] = dp[v[0].first][v[0].second][i][j];
        }
    }
    for (int i = 1; i < v.size(); ++i)
    {
        int dpp[3][3] = {};
        for (int i0 = 0; i0 < 3; ++i0)
        {
            for (int i1 = 0; i1 < 3; ++i1)
            {
                for (int i2 = 0; i2 < 3; ++i2)
                {
                    for (int i3 = 0; i3 < 3; ++i3)
                    {
                        if (i1 == 1 && i2 == 1)
                            continue;
                        if (i1 == 2 && i2 == 2)
                            continue;
                        dpp[i0][i3] = (dpp[i0][i3] + dp[l][r][i0][i1] * 1LL * dp[v[i].first][v[i].second][i2][i3]) % M;
                    }
                }
            }
        }
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                dp[l][r][i][j] = dpp[i][j];
    }
}

int main()
{
    scanf(" %s", a);
    n = strlen(a);
    stack<int> s;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '(')
            s.push(i);
        else
        {
            u[i] = s.top();
            u[s.top()] = i;
            s.pop();
        }
    }
    rec(0, n - 1);
    int ans = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            ans = (ans + dp[0][n - 1][i][j]) % M;
        }
    }
    printf("%d\n", ans);
    return 0;
}