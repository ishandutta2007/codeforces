#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, r;
int x[N];

void solv()
{
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    sort(x + 1, x + n + 1);
    long long g = 0;
    int ans = 0;
    for (int i = n; i >= 1; --i)
    {
        if (x[i] != x[i - 1])
        {
            if (x[i] - g <= 0)
                continue;
            else
            {
                ++ans;
                g += r;
            }
        }
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