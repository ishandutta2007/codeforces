#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 55;

char a[N], b[N];
int an, bn;
int qq;

vector<pair<int, int> > u[26];

bool dpa[N][N][26], dpb[N][N][26];

int dp[N][N];

void solv()
{
    scanf(" %s %s", a, b);
    an = strlen(a);
    bn = strlen(b);
    scanf("%d", &qq);
    while (qq--)
    {
        char s[10];
        scanf(" %s", s);
        u[s[0] - 'a'].push_back(m_p(s[3] - 'a', s[4] - 'a'));
    }
    for (int d = 1; d <= an; ++d)
    {
        for (int l = 0; l <= an - d; ++l)
        {
            int r = l + d - 1;
            if (l == r)
            {
                dpa[l][r][a[l] - 'a'] = true;
                continue;
            }
            for (int i = 0; i < 26; ++i)
            {
                for (int m = l; m < r; ++m)
                {
                    for (int j = 0; j < u[i].size(); ++j)
                    {
                        if (dpa[l][m][u[i][j].first] && dpa[m + 1][r][u[i][j].second])
                        {
                            dpa[l][r][i] = true;
                            break;
                        }
                    }
                    if (dpa[l][r][i])
                        break;
                }
            }
        }
    }
    for (int d = 1; d <= bn; ++d)
    {
        for (int l = 0; l <= bn - d; ++l)
        {
            int r = l + d - 1;
            if (l == r)
            {
                dpb[l][r][b[l] - 'a'] = true;
                continue;
            }
            for (int i = 0; i < 26; ++i)
            {
                for (int m = l; m < r; ++m)
                {
                    for (int j = 0; j < u[i].size(); ++j)
                    {
                        if (dpb[l][m][u[i][j].first] && dpb[m + 1][r][u[i][j].second])
                        {
                            dpb[l][r][i] = true;
                            break;
                        }
                    }
                    if (dpb[l][r][i])
                        break;
                }
            }
        }
    }
    for (int i = 0; i <= an; ++i)
    {
        for (int j = 0; j <= bn; ++j)
        {
            dp[i][j] = N * N * N;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i <= an; ++i)
    {
        for (int j = 0; j <= bn; ++j)
        {
            for (int ii = i + 1; ii <= an; ++ii)
            {
                for (int jj = j + 1; jj <= bn; ++jj)
                {
                    for (int k = 0; k < 26; ++k)
                    {
                        if (dpa[i][ii - 1][k] && dpb[j][jj - 1][k])
                        {
                            dp[ii][jj] = min(dp[ii][jj], dp[i][j] + 1);
                            break;
                        }
                    }
                }
            }
        }
    }
    if (dp[an][bn] == N * N * N)
        printf("-1\n");
    else
        printf("%d\n", dp[an][bn]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}