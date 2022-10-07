#include <bits/stdc++.h>

int n, a[100005];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    int mn = *std::min_element(a + 1, a + 1 + n);
    std::vector<int> v;
    for (int i = 1; i <= n; ++i) {
        if (a[i] % mn == 0) {
            v.push_back(a[i]);
        }
    }
    std::sort(v.begin(), v.end());
    int p = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] % mn == 0) {
            a[i] = v[p++];
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (a[i] < a[i - 1]) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    int T = 1;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}