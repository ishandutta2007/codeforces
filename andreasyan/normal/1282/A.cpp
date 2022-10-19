#include <bits/stdc++.h>
using namespace std;

int hat(int l1, int r1, int l2, int r2)
{
    if (r1 > r2)
    {
        swap(l1, l2);
        swap(r1, r2);
    }
    if (l2 <= r1 && r1 <= r2)
        return (r1 - max(l1, l2));
    return 0;
}

void solv()
{
    int a, b, c, r;
    scanf("%d%d%d%d", &a, &b, &c, &r);
    if (a > b)
        swap(a, b);
    printf("%d\n", b - a - hat(a, b, c - r, c + r));
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}