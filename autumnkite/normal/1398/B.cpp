#include <bits/stdc++.h>

int n;
char a[105];

void solve() {
    scanf("%s", a);
    n = strlen(a);
    std::vector<int> p;
    for (int i = 0, j; i < n; i = j + 1) {
        j = i;
        while (j < n && a[j] == '1') {
            ++j;
        }
        if (j > i) {
            p.push_back(j - i);
        }
    }
    std::sort(p.begin(), p.end());
    std::reverse(p.begin(), p.end());
    int ans = 0;
    for (int i = 0; i < (int)p.size(); i += 2) {
        ans += p[i];
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}