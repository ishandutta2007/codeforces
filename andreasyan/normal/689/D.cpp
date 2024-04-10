#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n;
int a[N], b[N];

const int m = 20;
int minu[N][m], maxu[N][m];
int u[N];

int qry_minu(int l, int r)
{
    return min(minu[r][u[r - l + 1]], minu[l + (1 << u[r - l + 1]) - 1][u[r - l + 1]]);
}

int qry_maxu(int l, int r)
{
    return max(maxu[r][u[r - l + 1]], maxu[l + (1 << u[r - l + 1]) - 1][u[r - l + 1]]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; ++i)
    {
        minu[i][0] = b[i];
        maxu[i][0] = a[i];
        for (int j = 1; j < m; ++j)
        {
            if (i - (1 << (j - 1)) >= 1)
            {
                minu[i][j] = min(minu[i][j - 1], minu[i - (1 << (j - 1))][j - 1]);
                maxu[i][j] = max(maxu[i][j - 1], maxu[i - (1 << (j - 1))][j - 1]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        while ((1 << (u[i] + 1)) <= i)
            ++u[i];
    }
    long long yans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = i;
        int ans = i + 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (qry_maxu(m, i) <= qry_minu(m, i))
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        l = 1, r = i;
        int ans1 = i + 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (qry_maxu(m, i) < qry_minu(m, i))
            {
                ans1 = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        yans += (ans1 - ans);
    }
    printf("%lld\n", yans);
    return 0;
}