#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, m;
int a[N];

void solv()
{
    scanf("%d%d", &n, &m);
    int s = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        s += a[i];
    }
    printf("%d\n", min(m, s));
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