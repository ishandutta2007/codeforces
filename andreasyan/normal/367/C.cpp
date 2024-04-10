#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005, M = 3003;

int n, m;
int a[N];

bool stg(int x)
{
    if (x % 2 == 1)
        return (x * (x - 1)) / 2 + 1 <= n;
    return (x * (x - 2)) / 2 + x <= n;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &a[i], &a[i]);
    }
    sort(a + 1, a + m + 1);
    reverse(a + 1, a + m + 1);
    int l = 1, r = 3000;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    long long yans = 0;
    for (int i = 1; i <= min(ans, m); ++i)
        yans += a[i];
    printf("%I64d\n", yans);
    return 0;
}