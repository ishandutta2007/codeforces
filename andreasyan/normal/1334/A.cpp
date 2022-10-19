#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 102;

int n;
int x[N], y[N];

bool solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if ((x[i] - x[i - 1]) < (y[i] - y[i - 1]))
            return false;
        if ((x[i] < x[i - 1]))
            return false;
        if ((y[i] < y[i - 1]))
            return false;
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