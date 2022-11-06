#include <bits/stdc++.h>

const int MAX = 100 * 100;

int a[MAX];

int main() {
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    n *= m;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans = 2147483647;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if ((a[i] - a[j]) % d != 0) {
                ok = false;
                break;
            }
            k += abs((a[i] - a[j]) / d);
        }
        if (ok && k < ans) {
            ans = k;
        }
    }
    printf("%d", ans == 2147483647 ? -1 : ans);

    return 0;
}