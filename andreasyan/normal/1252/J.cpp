#include <bits/stdc++.h>
using namespace std;

int n, x, a, b;

void solv()
{
    scanf("%d%d%d%d", &n, &x, &a, &b);
    if (a > b)
        swap(a, b);
    printf("%d\n", (b - a) + min(x, (a - 1) + (n - b)));
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}