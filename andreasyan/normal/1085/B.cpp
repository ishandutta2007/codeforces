#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000009;

int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    int ans = INF;
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            if ((n / i) < k)
                ans = min(ans, i * k + (n / i));
        }
    }
    printf("%d\n", ans);
    return 0;
}