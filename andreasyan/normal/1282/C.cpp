#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct ban
{
    int z;
    int x;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n, T, aa, bb;
ban a[N];
int s[N][2];

void solv()
{
    scanf("%d%d%d%d", &n, &T, &aa, &bb);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].z);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].x);
    a[0].z = -1;
    sort(a + 1, a + n + 1);
    s[n + 1][0] = s[n + 1][1] = 0;
    for (int i = n; i >= 1; --i)
    {
        s[i][0] = s[i + 1][0];
        s[i][1] = s[i + 1][1];
        s[i][a[i].z]++;
    }
    int ans = 0;
    long long p = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (a[i].z == 0)
            p += aa;
        else if (a[i].z == 1)
            p += bb;
        while (i < n && a[i].x == a[i + 1].x)
        {
            ++i;
            if (a[i].z == 0)
                p += aa;
            else if (a[i].z == 1)
                p += bb;
        }
        long long h;
        if (i == n)
            h = T;
        else
            h = a[i + 1].x - 1;
        if (p > h)
            continue;
        long long pp = p;
        int yans = i;
        if ((p + s[i + 1][0] * 1LL * aa) <= h)
        {
            p += s[i + 1][0] * 1LL * aa;
            yans += s[i + 1][0];
        }
        else
        {
            yans += (h - p) / aa;
            p = h;
        }
        if ((p + s[i + 1][1] * 1LL * bb) <= h)
        {
            p += s[i + 1][1] * 1LL * bb;
            yans += s[i + 1][1];
        }
        else
        {
            yans += (h - p) / bb;
            p = h;
        }
        ans = max(ans, yans);
        p = pp;
    }
    printf("%d\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}