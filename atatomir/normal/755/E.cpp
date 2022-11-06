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

int n, k, i;

int main()
{
    scanf("%d%d", &n, &k);

    if (n <= 3 || k >= 4 || k == 1) {
        printf("-1");
        return 0;
    }

    if (k == 3) {
        printf("%d\n", 3 + 2 * (n - 4));
        printf("1 2\n2 3\n3 4\n");
        for (i = 5; i <= n; i++)
            printf("%d %d\n%d %d\n", 2, i, 4, i);
        return 0;
    }

    if (n == 4) {
        printf("-1");
        return 0;
    }

    printf("%d\n", n);
    for (i = 2; i <= n; i++)
        printf("%d %d\n", i - 1, i);
    printf("%d %d\n", 1, n);


    return 0;
}