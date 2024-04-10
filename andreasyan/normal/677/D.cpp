#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 303, INF = 1000000009;

int n, m, p;
int a[N][N];

vector<pair<int, int> > v[N * N];

int dp[N][N];

void solv()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
            v[a[i][j]].push_back(m_p(i, j));
        }
    }
    for (int k = 1; k <= p; ++k)
        sort(v[k].begin(), v[k].end());
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            dp[i][j] = INF;
    }
    for (int i = 0; i < v[1].size(); ++i)
    {
        int x = v[1][i].first;
        int y = v[1][i].second;
        dp[x][y] = x + y - 2;
    }
    for (int k = 2; k <= p; ++k)
    {
        int minu[N];
        int u = 0;
        for (int y = 1; y <= m; ++y)
            minu[y] = INF;
        int j = 0;
        for (int i = 0; i < v[k].size(); ++i)
        {
            while (j < v[k - 1].size() && v[k - 1][j].first <= v[k][i].first)
            {
                int xx = v[k - 1][j].first;
                int yy = v[k - 1][j].second;
                for (int y = 1; y <= m; ++y)
                    minu[y] += abs(u - xx);
                u = xx;
                for (int y = 1; y <= m; ++y)
                    minu[y] = min(minu[y], dp[xx][yy] + abs(y - yy));
                ++j;
            }
            int xx = v[k][i].first;
            int yy = v[k][i].second;
            for (int y = 1; y <= m; ++y)
                minu[y] += abs(u - xx);
            u = xx;
            dp[xx][yy] = min(dp[xx][yy], minu[yy]);
        }
        u = n + 1;
        for (int y = 1; y <= m; ++y)
            minu[y] = INF;
        j = v[k - 1].size() - 1;
        for (int i = v[k].size() - 1; i >= 0; --i)
        {
            while (j >= 0 && v[k - 1][j].first >= v[k][i].first)
            {
                int xx = v[k - 1][j].first;
                int yy = v[k - 1][j].second;
                for (int y = 1; y <= m; ++y)
                    minu[y] += abs(u - xx);
                u = xx;
                for (int y = 1; y <= m; ++y)
                    minu[y] = min(minu[y], dp[xx][yy] + abs(y - yy));
                --j;
            }
            int xx = v[k][i].first;
            int yy = v[k][i].second;
            for (int y = 1; y <= m; ++y)
                minu[y] += abs(u - xx);
            u = xx;
            dp[xx][yy] = min(dp[xx][yy], minu[yy]);
        }
    }
    printf("%d\n", dp[v[p][0].first][v[p][0].second]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}