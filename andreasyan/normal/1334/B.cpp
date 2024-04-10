#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;

int n, x;
int a[N];

void solv()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    long long s = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        s += a[i];
        if (s >= x * 1LL * i)
            ans = i;
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