#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n, m, p;
int a[N], b[N];

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);
    int i = 0, j = 0;
    while (1)
    {
        if ((a[i] * 1LL * b[j]) % p != 0)
        {
            printf("%d\n", i + j);
            return 0;
        }
        if (a[i] % p == 0)
            ++i;
        if (b[j] % p == 0)
            ++j;
    }
    return 0;
}