#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int l[N], r[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &l[i], &r[i]);
    int minr = r[1];
    int maxl = l[1];
    for (int i = 2; i <= n; ++i)
    {
        minr = min(minr, r[i]);
        maxl = max(maxl, l[i]);
    }
    printf("%d\n", max(0, maxl - minr));
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