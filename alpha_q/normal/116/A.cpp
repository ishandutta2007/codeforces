#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
    int n, sum = 0, ans = 0;
    scanf("%d", &n);

    for (int station = 1; station <= n; ++station) {
        int uthse, namse;
        scanf("%d %d", &namse, &uthse);
        sum += uthse - namse;
        if (sum > ans) ans = sum;
    }

    printf("%d\n", ans);
    return 0;
}