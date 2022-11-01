#include <bits/stdc++.h>

using namespace std;

main()
{
    long long int y, k, n, i, cnt = 0, start;
    scanf("%I64d %I64d %I64d", &y, &k, &n);
    start = k * (1 + y/k);
    if (start <= n) {
        for (i = k * (1 + y/k); i <= n; i += k) {
            printf("%I64d", i - y);
            if (i + k <= n) printf(" ");
            cnt++;
        }
        printf("\n");
    }
    else printf("-1\n");
}