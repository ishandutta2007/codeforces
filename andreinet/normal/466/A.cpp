#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int n, m, a, b;
    scanf("%d%d%d%d", &n, &m, &a, &b);

    int ans = (n + m - 1) / m * b;
    for (int i = 0; i * m <= n; ++i)
        ans = min(ans, b * i + (n - i * m) * a);

    printf("%d\n", ans);
}