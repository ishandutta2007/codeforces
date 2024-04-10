#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        int x, y, a, b;
        scanf("%d%d%d%d", &x, &y, &a, &b);
        if ((y - x) % (a + b) == 0)
            printf("%d\n", (y - x) / (a + b));
        else
            printf("-1\n");
    }
    return 0;
}