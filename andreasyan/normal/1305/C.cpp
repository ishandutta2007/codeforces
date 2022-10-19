#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 1003;

int n, m;
int a[N];

int q[M];

int ast(int x, long long n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        a[i] %= m;
    int ans = 1;
    for (int j = 0; j < m; ++j)
    {
        memset(q, 0, sizeof q);
        long long qq = 0;
        for (int i = 1; i <= n; ++i)
        {
            qq += q[(a[i] - j + m) % m];
            q[a[i]]++;
        }
        ans = (ans * ast(j, qq)) % m;
    }
    printf("%d\n", ans);
    return 0;
}