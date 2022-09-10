#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        int n, k;
        scanf("%d %d", &n, &k);

        if (k == n - 1 && n == 4) {
            puts("-1");
            continue;
        }

        if (k == n - 1) {
            printf("%d %d\n", n - 2, n - 1);
            printf("%d %d\n", 1, 3);
            printf("%d %d\n", 2, n - 3);
            printf("%d %d\n", 0, n - 4);

            for (int i = 4; i < n / 2; ++i) {
                printf("%d %d\n", i, n - i - 1);
            }

            continue;
        }

        printf("%d %d\n", k, n - 1);
        if (k) {
            printf("%d %d\n", 0, n - k - 1);
        }

        for (int i = 1; i < n / 2; ++i) {
            if (i != k && i != n - k - 1) {
                printf("%d %d\n", i, n - i - 1);
            }
        }
    }

    return 0;
}