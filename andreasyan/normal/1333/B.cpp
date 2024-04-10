#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;

int n;
int a[N], b[N];

bool solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    int p = n + 1, m = n + 1;
    for (int i = n; i >= 1; --i)
    {
        if (a[i] > 0)
            p = i;
        if (a[i] < 0)
            m = i;
    }
    for (int i = n; i >= 1; --i)
    {
        if (a[i] == b[i])
            continue;
        if (a[i] < b[i])
        {
            if (!(p < i))
                return false;
        }
        else
        {
            if (!(m < i))
                return false;
        }
    }
    return true;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}