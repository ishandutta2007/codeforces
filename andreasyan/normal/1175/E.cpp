#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 500005;
struct ban
{
    int l, r;
};

int n, qq;
ban a[N];

int minu[N];

const int m = 22;
int p[N][m];
int q[N][m];

int main()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].l, &a[i].r);
    for (int i = 0; i < N; ++i)
        minu[i] = N;
    for (int i = 1; i <= n; ++i)
    {
        minu[a[i].r] = min(minu[a[i].r], a[i].l);
    }
    int yminu = N;
    for (int i = N - 1; i >= 0; --i)
    {
        yminu = min(yminu, minu[i]);
        if (yminu < i)
            p[i][0] = yminu;
        else
            p[i][0] = i;
    }
    for (int x = 0; x < N; ++x)
    {
        if (x == p[x][0])
            q[x][0] = 0;
        else
            q[x][0] = 1;
        for (int i = 1; i < m; ++i)
        {
            p[x][i] = p[p[x][i - 1]][i - 1];
            q[x][i] = q[x][i - 1] + q[p[x][i - 1]][i - 1];
        }
    }
    while (qq--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int ans = 0;
        for (int i = m - 1; i >= 0; --i)
        {
            if (p[r][i] > l)
            {
                ans += q[r][i];
                r = p[r][i];
            }
        }
        ans += q[r][0];
        r = p[r][0];
        if (r <= l)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }
    return 0;
}