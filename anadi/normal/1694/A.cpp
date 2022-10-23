#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        int a, b;
        scanf("%d %d", &a, &b);

        int n = a + b;
        for (int i = 1; i <= n; ++i) {
            if ((i & 1) && a > 0) {
                printf("0");
                a--;
            } else if (b > 0) {
                printf("1");
                b--;
            } else {
                printf("0");
                a--;
            }
        }

        puts("");
    }

    return 0;
}