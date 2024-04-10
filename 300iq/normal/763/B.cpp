#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    puts("YES");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int a = x1 % 2;
        int b = y1 % 2;
        if (a < 0)
        {
            a += 2;
        }
        if (b < 0)
        {
            b += 2;
        }
        printf("%d\n", a * 2 + b + 1);
    }
}