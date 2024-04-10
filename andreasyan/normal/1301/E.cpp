#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 505;

int n, m, qq;
char a[N][N];

int p0[4][N][N];

int sum0(int k, int x1, int y1_, int d)
{
    int x2 = x1 + d - 1, y2 = y1_ + d - 1;
    return p0[k][x2][y2] - p0[k][x1 - 1][y2] - p0[k][x2][y1_ - 1] + p0[k][x1 - 1][y1_ - 1];
}

int p[N][N][N];

int sum(int k, int x1, int y1_, int x2, int y2)
{
    if (x1 > x2)
        return 0;
    if (y1_ > y2)
        return 0;
    return p[k][x2][y2] - p[k][x1 - 1][y2] - p[k][x2][y1_ - 1] + p[k][x1 - 1][y1_ - 1];
}

void solv()
{
    scanf("%d%d%d", &n, &m, &qq);
    for (int i = 1; i <= n; ++i)
        scanf(" %s", (a[i] + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == 'R')
                a[i][j] = 0;
            else if (a[i][j] == 'G')
                a[i][j] = 1;
            else if (a[i][j] == 'Y')
                a[i][j] = 2;
            else
                a[i][j] = 3;
        }
    }
    for (int k = 0; k < 4; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                p0[k][i][j] = p0[k][i - 1][j] + p0[k][i][j - 1] - p0[k][i - 1][j - 1];
                if (k == a[i][j])
                    ++p0[k][i][j];
            }
        }
    }
    for (int k = 1; k <= n; ++k)
    {
        if (k % 2 == 1)
            continue;
        for (int i = k; i <= n; ++i)
        {
            for (int j = k; j <= m; ++j)
            {
                p[k][i][j] = p[k][i - 1][j] + p[k][i][j - 1] - p[k][i - 1][j - 1];
                if (sum0(0, i - k + 1, j - k + 1, k / 2) == (k / 2) * (k / 2))
                {
                    if (sum0(1, i - k + 1, j - k / 2 + 1, k / 2) == (k / 2) * (k / 2))
                    {
                        if (sum0(2, i - k / 2 + 1, j - k + 1, k / 2) == (k / 2) * (k / 2))
                        {
                            if (sum0(3, i - k / 2 + 1, j - k / 2 + 1, k / 2) == (k / 2) * (k / 2))
                            {
                                ++p[k][i][j];
                            }
                        }
                    }
                }
            }
        }
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 2 == 0)
            v.push_back(i);
    }
    while (qq--)
    {
        int x1, y1_, x2, y2;
        scanf("%d%d%d%d", &x1, &y1_, &x2, &y2);
        int l = 0, r = sz(v) - 1;
        int ans = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (sum(v[m], x1 + v[m] - 1, y1_ + v[m] - 1, x2, y2))
            {
                ans = v[m];
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        printf("%d\n", ans * ans);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}