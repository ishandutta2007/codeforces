#include <bits/stdc++.h>

int n, a[50005];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    if (a[1] + a[2] <= a[n]) {
        printf("1 2 %d\n", n);
    } else {
        printf("-1\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}