#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int p[N];
int x, a;
int y, b;
long long k;

int u[N];

bool stg(int q)
{
    vector<int> v;
    for (int i = 1; i <= q; ++i)
        v.push_back(u[i]);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long ans = 0;
    for (int i = 1; i <= q; ++i)
    {
        ans += (p[i] / 100 * 1LL * v[i - 1]);
    }
    return (ans >= k);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]);
    scanf("%d%d", &x, &a);
    scanf("%d%d", &y, &b);
    scanf("%lld", &k);
    sort(p + 1, p + n + 1);
    reverse(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++i)
        u[i] = 0;
    for (int i = a; i <= n; i += a)
        u[i] += x;
    for (int i = b; i <= n; i += b)
        u[i] += y;
    int l = 1, r = n;
    int ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    printf("%d\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}