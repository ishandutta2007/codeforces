#include <cstdio>

using namespace std;

int n, m, a, b, xa, ya, xb, yb;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d %d %d %d", &n, &m, &a, &b);

    xa = (a - 1) / m + 1;
    ya = (a - 1) % m + 1;
    xb = (b - 1) / m + 1;
    yb = (b - 1) % m + 1;
    if (b == n) yb = m;

    if (xa == xb)
    {
        printf("1\n");
        return 0;
    }

    if (xa + 1 == xb)
    {
        printf("%d\n", 1 + (ya != 1 || yb != m));
        return 0;
    }

    printf("%d\n", 1 + (ya != 1) + (yb != m) - (yb + 1 == ya));
    return 0;
}