#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

int n, d, h, i, pas;

void nosol() {
    printf("-1");
    exit(0);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &d, &h);

    if (n < d + 1) nosol();
    if (h > d) nosol();
    if (d - h > h) nosol();

    if (d == h) {
        if (d == 1) {
            if (n != 2)
                nosol();

            printf("%d %d", 1, 2);
            return 0;
        }

        for (i = 1; i <= h; i++)
            printf("%d %d\n", i, i + 1);

        n -= h + 1;
        for (i = 1; i <= n; i++)
            printf("%d %d\n", 2, h + 1 + i);
    } else {
        for (i = 1; i <= h; i++)
            printf("%d %d\n", i, i + 1);
        pas = h + 1;

        printf("%d %d\n", 1, ++pas);
        for (i = 2; i <= d - h; i++)
            printf("%d %d\n", pas, pas + 1), pas++;

        n -= d + 1;
        for (i = 1; i <= n; i++)
            printf("%d %d\n", 1, pas + i);
    }

    return 0;
}