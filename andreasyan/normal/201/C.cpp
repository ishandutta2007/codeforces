#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;
int a[N];

long long p[N], s[N];

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 2; i <= n; ++i)
    {
        if (a[i - 1] == 1)
            p[i] = 0;
        else
            p[i] = (p[i - 1] + (a[i - 1] / 2) * 2);
    }
    for (int i = n - 1; i >= 1; --i)
    {
        if (a[i] == 1)
            s[i] = 0;
        else
            s[i] = (s[i + 1] + (a[i] / 2) * 2);
    }
    long long ans = 0;
    long long maxu = 0;
    for (int i = n; i >= 1; --i)
    {
        maxu = max(maxu, s[i]);
        ans = max(ans, p[i] + maxu);
        maxu += (((a[i - 1] - 1) / 2) * 2 + 1);
    }
    printf("%I64d\n", ans);
    return 0;
}