#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;
struct ban
{
    int i, x;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n, A;
int cf, cm;
long long m, mm;
ban a[N];

long long p[N];

bool bynn(int x, long long d, int i)
{
    int l = 1, r = i;
    int ans = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m].x <= x)
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return (x * 1LL * ans - p[ans]) <= d;
}

int byn(long long d, int i)
{
    int l = 0, r = A;
    int ans = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (bynn(m, d, i))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return ans;
}

int aa[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d%lld", &n, &A, &cf, &cm, &m);
    mm = m;
    for (int i = 1; i <= n; ++i)
    {
        a[i].i = i;
        scanf("%d", &a[i].x);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i].x;
    long long ans = byn(m, n) * 1LL * cm;
    int ansi = n + 1;
    for (int i = n; i >= 1; --i)
    {
        m -= (A - a[i].x);
        if (m < 0)
            break;
        long long yans = byn(m, i - 1) * 1LL * cm + (n - i + 1) * cf;
        if (yans > ans)
        {
            ans = yans;
            ansi = i;
        }
    }
    printf("%lld\n", ans);
    m = mm;
    for (int i = n; i >= ansi; --i)
    {
        m -= (A - a[i].x);
        aa[a[i].i] = A;
    }
    int x = byn(m, ansi - 1);
    for (int i = 1; i < ansi; ++i)
    {
        if (a[i].x > x)
            aa[a[i].i] = a[i].x;
        else
            aa[a[i].i] = x;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", aa[i]);
    printf("\n");
    return 0;
}